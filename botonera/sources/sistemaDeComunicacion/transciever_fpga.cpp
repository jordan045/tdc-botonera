#include "transciever_fpga.h"
#include <QHostAddress>
#include <QDebug>


transcieverFPGA::transcieverFPGA(QObject *parent, class decoderAND *decoderAND, BotoneraMaster *botonera, class decoderLPD *decoderLPD) : QObject(parent){
    //Crear el socket y conectarlo al puerto de la FPGA
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, PORT_NOTEBOOK);
    qDebug() << "TRANSCIEVER: Socket UDP abierto en el puerto: " << PORT_NOTEBOOK << " desde " << IP_MASTER;

    timerConcentrator = new QTimer(this);

    //Conectar la llegada de mensajes nuevos con la clasificación de mensajes
    connect(udpSocket, &QUdpSocket::readyRead, this, &transcieverFPGA::readPendingDatagrams);
    connect(timerConcentrator, &QTimer::timeout, this, &transcieverFPGA::reenviarDCLCONC);

    this->myDecoderAND = decoderAND;
    this->botonera = botonera;
    this->myDecoderLPD = decoderLPD;

    /* TEST INYECTION
        QFile file(":/binary/and_raw_onepage.bin");
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << "No se pudo abrir el archivo";
            return;
        }

        // Tamaño de cada bloque de datos a leer
        const int blockSize = 51;
        QPair<int, QString> result;

        // Leer el archivo en bloques de blockSize bytes
        while (!file.atEnd()) {
            QByteArray block = file.read(blockSize);
            readDeviceAddress(block);
        }
        file.close();
    */
}

quint16 transcieverFPGA::getNextSequenceNumber() {
    sequenceCounter = (sequenceCounter + 1) & 0x7FFF; // Incrementa y aplica una máscara de 15 bits (0x7FFF)
    return sequenceCounter;
}

void transcieverFPGA::readPendingDatagrams(){
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize()); //Resize al tamaño del mensaje recibido

        //Son datos de salida de readDatagram
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        //qDebug() << "llego algo" << datagram.size();
        readDeviceAddress(datagram);
    }
}

void transcieverFPGA::readDeviceAddress(QByteArray datagram){
    if(!datagram.isNull()){
        if (datagram.size() < 3) {
            qWarning() << "TRANSCIEVER: Datagrama muy pequeño para procesar. Tamaño:" << datagram.size();
            return;
        }

        char deviceAddress = datagram.at(0) & 0x0F;

        quint16 sequenceNumber = ((static_cast<quint16>(datagram.at(1) & 0x7F) << 8) |
                                  static_cast<quint8>(datagram.at(2)));

        // Si hay más de 3 bytes, el resto es el payload
        QByteArray payload;
        if (datagram.size() > 3) {
            payload = datagram.mid(3);
        }
        //qDebug() << "pay " << payload;
        int wordLength;

        switch (deviceAddress) {
            case DA_LPD:
                wordLength = datagram.at(2);
                wordLength = wordLength * 3;
                sendToLPD(payload,wordLength);
                break;
            case DA_PEDIDO_CONCENTRADOR:
                generateConcentrator();
                break;

            case DA_AND1:
                AND1(payload, sequenceNumber);
                break;

            case DA_AND2:
                //AND 2
                break;

            case DA_CONCENTRADOR:
                //ACK DLC CONC
                recieveACK(datagram.mid(1,1), sequenceNumber);
                break;

            default:
                break;
        }
    }
}

QByteArray negateData(const QByteArray &data) {
    QByteArray invertedData = data;
    for (int i = 0; i < invertedData.size(); ++i) {
        invertedData[i] = ~invertedData[i];
    }
    return invertedData;
}

void transcieverFPGA::generateConcentrator(){
    QByteArray concentrator = botonera->getConcentrator();
    concentrator = negateData(concentrator);
    sendConcentrator(concentrator);
}

void transcieverFPGA::sendConcentrator(QByteArray data){
    QByteArray header = QByteArray(3,0x0);
    quint16 sequenceNumber = getNextSequenceNumber();

    header[0] = DA_CONCENTRADOR;
    header[1] = (sequenceNumber >> 8) & 0xFF;  // Insertar el primer byte del número de secuencia
    header[2] = sequenceNumber & 0xFF;         // Insertar el segundo byte del número de secuencia

    QByteArray message = header + data;

    bufferConcentrador.first = data;
    bufferConcentrador.second = sequenceNumber;

    if (udpSocket->writeDatagram(message, QHostAddress(IP_FPGA), PORT_FPGA) == -1) {
        qWarning() << "TRANSCIEVER: Failed to send datagram:" << udpSocket->errorString();
    }
    timerConcentrator->start(200);
}

void transcieverFPGA::AND1(QByteArray data, quint16 sequenceNumber){
    QByteArray invertedData = negateData(data);

    // Generar el mensaje ACK para devolver a la FPGA
    QByteArray ack_message = QByteArray(3,0x0);
    ack_message[0] = DA_AND1;
    ack_message[1] = ((sequenceNumber >> 8) & 0xFF) | 0x80;
    ack_message[2] = sequenceNumber & 0xFF;
    udpSocket->writeDatagram(ack_message, QHostAddress(IP_FPGA), PORT_FPGA);

    myDecoderAND->processAndMessage(invertedData);
}

void transcieverFPGA::sendToLPD(QByteArray d, int wordLength){
    myDecoderLPD->processLPDMessage(d, wordLength);
}

void transcieverFPGA::AND2(QByteArray data, quint16 sequenceNumber){
    QByteArray invertedData = negateData(data);
    QByteArray ack_message = QByteArray(3,0x0);

    ack_message[0] = DA_ACK_AND_2;
    ack_message[1] = ((sequenceNumber >> 8) & 0xFF) | 0x80;
    ack_message[2] = sequenceNumber & 0xFF;
    udpSocket->writeDatagram(ack_message, QHostAddress(IP_FPGA), PORT_FPGA);

    myDecoderAND->processAndMessage(invertedData);
    /*
     * Aca hay que mandar a TCP-Slave, merge con SC-TCP
     * Para despues mandarlo a converter
     * converter->processBinaryString(dataInvert);
    */
}

void transcieverFPGA::recieveACK(QByteArray ack, quint16 sequenceNumber){
    bool flagAck = ack[0] & 0x80;

    if(flagAck && (sequenceNumber == bufferConcentrador.second)){
        timerConcentrator->stop();
        bufferConcentrador.first = 0x0;
        bufferConcentrador.second = 0;
    }
}

void transcieverFPGA::reenviarDCLCONC(){
    qDebug() << "TRANSCIEVER: Reenviando Concentrador";
    sendConcentrator(bufferConcentrador.first);//envia el mismo numero de secuencia?
}
