#include "scudp.h"

#include <QHostAddress>
#include <QDebug>


SCUDP::SCUDP(QObject *parent, AndTranslator *c) : QObject(parent){

    udpSocket = new QUdpSocket(this);

    udpSocket->bind(QHostAddress::Any, PORT);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

    converter = c;

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
        qDebug() << "Received from" << sender.toString() << ":" << senderPort << "message:" << datagram;
    }
}

void SCUDP::deviceAddress(QByteArray d){
    if(!d.isNull()){
        char da = d.at(0);
        switch (da) {
            case 0x00:

                break;

            case 0x02:

                AND1(d.last(d.size() - 3));//lo mando sin encabezado
                break;

            case 0x03:

                break;

            default:
                break;
            }
    }
}

void SCUDP::pedidoDCLCONC(QByteArray d)
{

}

QByteArray bitwiseInvert(const QByteArray &data) {//podria pasarse el tamaño por parametro
    QByteArray invertedData = data;
    for (int i = 0; i < invertedData.size(); ++i) {
        invertedData[i] = ~invertedData[i];
    }
    return invertedData;
}

void SCUDP::AND1(QByteArray d){
    QByteArray data = bitwiseInvert(d);
    converter->processBinaryString(data);
    //falta ACK
}

