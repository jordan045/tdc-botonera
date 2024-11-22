#include "transciever_fpga.h"
#include <QHostAddress>
#include <QDebug>

Transciever_FPGA::Transciever_FPGA(QObject *parent, AndTranslator *translator, FormatConcentrator *FC) : QObject(parent){
    //Crear el socket y conectarlo al puerto de la FPGA
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, PORT);

    //Conectar la llegada de mensajes nuevos con la clasificación de mensajes
    connect(udpSocket, &QUdpSocket::readyRead, this, &Transciever_FPGA::readPendingDatagrams);
    connect(&ACKdclconc, &QTimer::timeout, this, &Transciever_FPGA::reenviarDCLCONC);

    converter = translator;
    fc = FC;
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
        char deviceAddress = datagram.at(0);  //Agarro el primer byte, pero solo me sirve
                                         //los ultimos 4bits (los 4 primeros son 0s)
        char numeroDeSecuencia[] = {datagram.at(1),datagram.at(2)};
        QByteArray payload = datagram.last(datagram.size()-3);

        switch (deviceAddress) {
            case 0x00:
                sendToLPD(payload);
                break;
            case 0x01:
                pedidoDCLCONC(numeroDeSecuencia);
                break;

            case 0x02:
                AND1(payload, numeroDeSecuencia);
                break;

            case 0x03:
                //AND 2
                break;

            case 0x04:
                //ACK DLC CONC
                recibiACK(datagram.mid(1,1), numeroDeSecuencia);
                break;

            default:
                break;
        }
    }
}

QBitArray Transciever_FPGA::byteArrayToBitArray(const QByteArray &byteArray){
    QBitArray bitArray(byteArray.size() * 8); // Crea un QBitArray con el tamaño en bits

    for (int i = 0; i < byteArray.size(); ++i) {
        for (int b = 0; b < 8; ++b) {
            bool bitValue = byteArray[i] & (1 << (7 - b)); // Obtiene el valor del bit de más alto a más bajo
            bitArray.setBit(i * 8 + b, bitValue);
        }
    }
    return bitArray;
}

QByteArray Transciever_FPGA::bitArrayToByteArray(const QBitArray &bitArray) {
    QByteArray byteArray((bitArray.size() + 7) / 8, 0); // Crea un QByteArray con el tamaño adecuado, inicializado a 0

    for (int i = 0; i < bitArray.size(); ++i) {
        if (bitArray.testBit(i)) {
            byteArray[i / 8] |= (1 << (7 - (i % 8))); // Ajusta el bit correspondiente en el byte
        }
    }
    return byteArray;
}

QByteArray bitwiseInvert(const QByteArray &data) {//podria pasarse el tamaño por parametro
    QByteArray invertedData = data;
    for (int i = 0; i < invertedData.size(); ++i) {
        invertedData[i] = ~invertedData[i];
    }
    return invertedData;
}

void Transciever_FPGA::pedidoDCLCONC(char numSecuencia[]){
    QBitArray a(5);
    QByteArray DCLCONCdata = bitArrayToByteArray(a); //Necesito un getMessage sin parametro en FC
    QByteArray DCLCONCneg = bitwiseInvert(DCLCONCdata);
    DCLCONC(DCLCONCneg, numSecuencia);//recibo por pedido, mando po DCL CONC
}

void Transciever_FPGA::DCLCONC(QByteArray data, char numSecuencia[]){
    data[0] = 0x04;
    ultimoCONC.first = data;
    ultimoCONC.second[0] = numSecuencia[0];
    ultimoCONC.second[1] = numSecuencia[1];
    udpSocket->writeDatagram(ultimoCONC.first, QHostAddress(IP), PORT);//QHostAddress esta mal creo, tenog q poner la ip
    ACKdclconc.start(200);
}

void Transciever_FPGA::AND1(QByteArray data, char numSecuencia[]){
    QByteArray dataInvert = bitwiseInvert(data);
    QByteArray ack;
    ack.resize(3);
    ack[0] = 0x02;
    ack[1] = numSecuencia[0] | 0x80;
    ack[2] = numSecuencia[1];
    udpSocket->writeDatagram(ack, QHostAddress(IP), PORT);
    converter->processBinaryString(dataInvert);
}

void Transciever_FPGA::AND2(QByteArray data, char numSecuencia[]){
    QByteArray dataInvert = bitwiseInvert(data);
    QByteArray ack;
    ack.resize(3);
    ack[0] = 0x02;
    ack[1] = numSecuencia[0] | 0x80;
    ack[2] = numSecuencia[1];
    udpSocket->writeDatagram(ack, QHostAddress(IP), PORT);
    /*
     * Aca hay que mandar a TCP-Slave, merge con SC-TCP
     * Para despues mandarlo a converter
     * converter->processBinaryString(dataInvert);
    */
}

void Transciever_FPGA::sendToLPD(QByteArray data){
    char lastByte = data.at(data.size()-1);
    qint8 id = lastByte & 0x0F;
    //clasificar los id, hacerlo con switch?
}

void Transciever_FPGA::recibiACK(QByteArray ack, char numSecuencia[]){
    QBitArray ACKbit(16);
    ACKbit = byteArrayToBitArray(ack);
    char num_secByte1 = ultimoCONC.second[0] & 0x7F;
    char num_secByte2  = ultimoCONC.second[1];
    if(ACKbit[0] == true && numSecuencia[0] == num_secByte1 && num_secByte2 == numSecuencia[1]){
        ACKdclconc.stop();
    }else{
        //podria reenviarse, pero ya lo hace el timer, a definir con Chris
        //si el DCL CONC que recivo es solo para ACK
    }
}

void Transciever_FPGA::reenviarDCLCONC(){
    DCLCONC(ultimoCONC.first,ultimoCONC.second);//envia el mismo numero de secuencia?
}
