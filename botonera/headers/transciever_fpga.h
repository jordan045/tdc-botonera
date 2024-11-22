#ifndef TRANSCIEVER_FPGA_H
#define TRANSCIEVER_FPGA_H

#include "andTranslator.h"
#include "formatconcentrator.h"
#include "lpdDecoder.h"
#include <QObject>
#include <QUdpSocket>
#include <QTimer>

#define PORT 9000

class Transciever_FPGA : public QObject
{
    Q_OBJECT

public:
    explicit Transciever_FPGA(QObject *parent = nullptr, AndTranslator *c = nullptr, FormatConcentrator *f = nullptr, LPDDecoder *decoder = nullptr);
    void sendMessage(const QString &message, const QString &address, quint16 port);

private slots:
    void readPendingDatagrams();
    void reenviarDCLCONC();

private:
    QUdpSocket *udpSocket;
    //QByteArray datagram;
    void readDeviceAddress(QByteArray d);

    QByteArray bitwise(const QByteArray &data);
    QByteArray bitArrayToByteArray(const QBitArray &bitArray);
    QBitArray byteArrayToBitArray(const QByteArray &byteArray);

    void recibiACK(QByteArray ack);
    void pedidoDCLCONC();
    void DCLCONC(QByteArray d);
    void AND1(QByteArray d);
    void AND2(QByteArray d);
    void sendToLPD(QByteArray d, int wordLength);

    QHostAddress *FPGA; //Host? o se manda de otra forma?

    //QByteArray ultimoCONC;

    QPair<QByteArray,char[2]> ultimoCONC;
    QTimer ACKdclconc;

    AndTranslator *converter;
    FormatConcentrator *fc;
    LPDDecoder *decoder;
};

#endif // TRANSCIEVER_FPGA_H

//   Pedido DCL CONC
//   DCL CONC
//   AND1
//   AND2
//   LPD
