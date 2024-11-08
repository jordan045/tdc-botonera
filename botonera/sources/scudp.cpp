#include "scudp.h"

#include <QHostAddress>
#include <QDebug>


SCUDP::SCUDP(QObject *parent, AndTranslator *c, FormatConcentrator *f) : QObject(parent){

    udpSocket = new QUdpSocket(this);

    udpSocket->bind(QHostAddress::Any, PORT);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    connect(&ACKdclconc, SIGNAL(&QTimer::timeout), SLOT(&SCUDP::reenviarDCLCONC));

    converter = c;
    fc = f;
}

void SCUDP::sendMessage(const QString &message, const QString &address, quint16 port){
    QByteArray datagram = message.toUtf8();
    udpSocket->writeDatagram(datagram, QHostAddress(address), port);
}

void SCUDP::readPendingDatagrams(){
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        deviceAddress(datagram);
        //qDebug() << "Received from" << sender.toString() << ":" << senderPort << "message:" << datagram;
    }
}


void SCUDP::deviceAddress(QByteArray d){
    if(!d.isNull()){
        char da = d.at(0);  //Agarro el primer byte, pero solo me sirve
                            //los ultimos 4bits (los 4 primeros son 0s)
        switch (da) {
            case 0x00:
                LPD(d.last(d.size() - 3));//lo mando sin encabezado
                break;

            case 0x01:
                pedidoDCLCONC();
                break;

            case 0x02:
                AND1(d.last(d.size() - 3));//lo mando sin encabezado
                break;

            case 0x03:
                //AND 2
                break;

            case 0x04:
                //ACK DLC CONC
                recibiACK(d.mid(1,1));
                break;

            default:
                break;
            }
    }
}

QBitArray SCUDP::byteArrayToBitArray(const QByteArray &byteArray){
    QBitArray bitArray(byteArray.size() * 8); // Crea un QBitArray con el tamaño en bits

    for (int i = 0; i < byteArray.size(); ++i) {
        for (int b = 0; b < 8; ++b) {
            bool bitValue = byteArray[i] & (1 << (7 - b)); // Obtiene el valor del bit de más alto a más bajo
            bitArray.setBit(i * 8 + b, bitValue);
        }
    }
    return bitArray;

}

QByteArray SCUDP::bitArrayToByteArray(const QBitArray &bitArray) {
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

void SCUDP::pedidoDCLCONC(){
    QBitArray a(5);
    QByteArray DCLCONCdata = bitArrayToByteArray(a); //Necesito un getMessage sin parametro en FC
    QByteArray DCLCONCneg = bitwiseInvert(DCLCONCdata);
    DCLCONC(DCLCONCneg);//recibo por pedido, mando po DCL CONC
}

void SCUDP::DCLCONC(QByteArray d){
    d[0] = 0x04;
    ultimoCONC = d;
    udpSocket->writeDatagram(ultimoCONC, QHostAddress::AnyIPv4, PORT);//QHostAddress esta mal creo, tenog q poner la ip
    ACKdclconc.start(200);
}

void SCUDP::AND1(QByteArray d){
    QByteArray data = bitwiseInvert(d);
    converter->processBinaryString(data);
    //falta ACK
}

void SCUDP::LPD(QByteArray d){
    char lastByte = d.at(d.size()-1);
    qint8 id = lastByte & 0x0F;
    //clasificar los id, hacerlo con switch?
}

void SCUDP::recibiACK(QByteArray ack){
    QBitArray ACKbit(16);
    ACKbit = byteArrayToBitArray(ack);
    if(ACKbit[0] == true){
        ACKdclconc.stop();
    }else{
        //podria reenviarse, pero ya lo hace el timer, a definir con Chris
        //si el DCL CONC que recivo es solo para ACK
    }
}

void SCUDP::reenviarDCLCONC(){
    DCLCONC(ultimoCONC);
}

