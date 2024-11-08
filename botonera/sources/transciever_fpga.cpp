#include "Transciever_FPGA.h"

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
        char device_address = datagram.at(0);  //Agarro el primer byte, pero solo me sirve
                                         //los ultimos 4bits (los 4 primeros son 0s)
        QByteArray payload = datagram.last(datagram.size()-3);

        switch (device_address) {
            case 0x00:
                sendToLPD(payload);
                break;
            case 0x01:
                pedidoDCLCONC();
                break;

            case 0x02:
                AND1(payload);
                break;

            case 0x03:
                //AND 2
                break;

            case 0x04:
                //ACK DLC CONC
                recibiACK(datagram.mid(1,1));
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

void Transciever_FPGA::pedidoDCLCONC(){
    QBitArray a(5);
    QByteArray DCLCONCdata = bitArrayToByteArray(a); //Necesito un getMessage sin parametro en FC
    QByteArray DCLCONCneg = bitwiseInvert(DCLCONCdata);
    DCLCONC(DCLCONCneg);//recibo por pedido, mando po DCL CONC
}

void Transciever_FPGA::DCLCONC(QByteArray d){
    d[0] = 0x04;
    ultimoCONC = d;
    udpSocket->writeDatagram(ultimoCONC, QHostAddress::AnyIPv4, PORT);//QHostAddress esta mal creo, tenog q poner la ip
    ACKdclconc.start(200);
}

void Transciever_FPGA::AND1(QByteArray d){
    QByteArray data = bitwiseInvert(d);
    converter->processBinaryString(data);
    //falta ACK
}

void Transciever_FPGA::sendToLPD(QByteArray d){
    char lastByte = d.at(d.size()-1);
    qint8 id = lastByte & 0x0F;
    //clasificar los id, hacerlo con switch?
}

void Transciever_FPGA::recibiACK(QByteArray ack){
    QBitArray ACKbit(16);
    ACKbit = byteArrayToBitArray(ack);
    if(ACKbit[0] == true){
        ACKdclconc.stop();
    }else{
        //podria reenviarse, pero ya lo hace el timer, a definir con Chris
        //si el DCL CONC que recivo es solo para ACK
    }
}

void Transciever_FPGA::reenviarDCLCONC(){
    DCLCONC(ultimoCONC);
}

