#include "transciever_fpga.h"
#include <QHostAddress>
#include <QDebug>


Transciever_FPGA::Transciever_FPGA(QObject *parent, AndTranslator *translator, BotoneraMaster *botonera, LPDDecoder *decoder) : QObject(parent){
    //Crear el socket y conectarlo al puerto de la FPGA
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, PORT);

    //Conectar la llegada de mensajes nuevos con la clasificación de mensajes
    connect(udpSocket, &QUdpSocket::readyRead, this, &Transciever_FPGA::readPendingDatagrams);
    connect(&timerConcentrador, &QTimer::timeout, this, &Transciever_FPGA::reenviarDCLCONC);

    converter = translator;
    this->botonera = botonera;
    this->decoder = decoder;

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
}

quint16 Transciever_FPGA::getNextSequenceNumber() {
    sequenceCounter = (sequenceCounter + 1) & 0x7FFF; // Incrementa y aplica una máscara de 15 bits (0x7FFF)
    return sequenceCounter;
}

void Transciever_FPGA::readPendingDatagrams(){
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize()); //Resize al tamaño del mensaje recibido

        //Son datos de salida de readDatagram
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        readDeviceAddress(datagram);
    }
}

void Transciever_FPGA::readDeviceAddress(QByteArray datagram){
    if(!datagram.isNull()){
        char deviceAddress = datagram.at(0) & 0x0F;  //Sirve los ultimos 4 bits

        //El número de secuencia de cada trama se representa con 15 bits
        quint16 sequenceNumber = (static_cast<quint16>(datagram.at(1)) << 8) | static_cast<quint8>(datagram.at(2));

        QByteArray payload = datagram.last(datagram.size()-3); //Elimina el encabezado
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
                qDebug() << "vamo a AND!";
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

void Transciever_FPGA::generateConcentrator(){
    QByteArray concentrator = botonera->getConcentrator();
    concentrator = negateData(concentrator);
    sendConcentrator(concentrator);
}

void Transciever_FPGA::sendConcentrator(QByteArray data){
    QByteArray header = QByteArray(3,0x0);
    quint16 sequenceNumber = getNextSequenceNumber();

    header[0] = DA_CONCENTRADOR;
    header[1] = (sequenceNumber >> 8) & 0xFF;  // Insertar el primer byte del número de secuencia
    header[2] = sequenceNumber & 0xFF;         // Insertar el segundo byte del número de secuencia

    QByteArray message = header + data;

    bufferConcentrador.first = data;
    bufferConcentrador.second = sequenceNumber;

    if (udpSocket->writeDatagram(message, QHostAddress(IP), PORT) == -1) {
        qWarning() << "Failed to send datagram:" << udpSocket->errorString();
    }
    timerConcentrador.start(200);
}

void Transciever_FPGA::AND1(QByteArray data, quint16 sequenceNumber){
    QByteArray invertedData = negateData(data);
    QByteArray ack_message = QByteArray(3,0x0);

    ack_message[0] = DA_AND1;
    ack_message[1] = (sequenceNumber >> 8) & 0xFF;
    ack_message[2] = sequenceNumber & 0xFF;
    udpSocket->writeDatagram(ack_message, QHostAddress(IP), PORT);

    converter->processAndMessage(invertedData);
}

void Transciever_FPGA::sendToLPD(QByteArray d, int wordLength){
    decoder->processLPDMessage(d, wordLength);
}

void Transciever_FPGA::AND2(QByteArray data, quint16 sequenceNumber){
    QByteArray invertedData = negateData(data);
    QByteArray ack_message = QByteArray(3,0x0);

    ack_message[0] = DA_AND1;
    ack_message[1] = (sequenceNumber >> 8) & 0xFF;
    ack_message[2] = sequenceNumber & 0xFF;
    udpSocket->writeDatagram(ack_message, QHostAddress(IP), PORT);

    converter->processAndMessage(invertedData);
    /*
     * Aca hay que mandar a TCP-Slave, merge con SC-TCP
     * Para despues mandarlo a converter
     * converter->processBinaryString(dataInvert);
    */
}

void Transciever_FPGA::recieveACK(QByteArray ack, quint16 sequenceNumber){
    bool flagAck = ack[0] & 0x80;

    if(flagAck && (sequenceNumber == bufferConcentrador.second)){
        timerConcentrador.stop();
        bufferConcentrador.first = 0x0;
        bufferConcentrador.second = 0;
    }
}

void Transciever_FPGA::reenviarDCLCONC(){
    sendConcentrator(bufferConcentrador.first);//envia el mismo numero de secuencia?
}
