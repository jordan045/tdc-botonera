#ifndef TRANSCIEVER_FPGA_H
#define TRANSCIEVER_FPGA_H

#include "decoderAND.h"
#include "botoneraMaster.h"
#include "decoderLPD.h"
#include <QObject>
#include <QUdpSocket>
#include <QTimer>

#define PORT_NOTEBOOK 8001
#define PORT_FPGA 9000
#define IP_FPGA "172.16.0.100"
#define IP_MASTER "172.16.0.99"
#define MAC_ADDRESS "34BDFA99B530"

#define DA_CONCENTRADOR 0x04
#define DA_AND1 0x02
#define DA_ACK_AND_1 0x82
#define DA_ACK_AND_2 0x83
#define DA_AND2 0x03
#define DA_LPD 0x00
#define DA_PEDIDO_CONCENTRADOR 0x01

class transcieverFPGA : public QObject
{
    Q_OBJECT

public:
    explicit transcieverFPGA(QObject *parent = nullptr, decoderAND *c = nullptr,BotoneraMaster *botonera = nullptr, decoderLPD *decoder = nullptr);
    void sendMessage(const QString &message, const QString &address, quint16 port);

private slots:
    void readPendingDatagrams();
    void reenviarDCLCONC();

private:
    QUdpSocket *udpSocket;
    //QByteArray datagram;
    void readDeviceAddress(QByteArray d);

    QByteArray bitwise(const QByteArray &data);
    QBitArray byteArrayToBitArray(const QByteArray &byteArray);

    void recieveACK(QByteArray ack, quint16 sequenceNumber);
    void generateConcentrator();
    void sendConcentrator(QByteArray data);
    void AND1(QByteArray data, quint16 sequenceNumber);
    void AND2(QByteArray data, quint16 sequenceNumber);
    void sendToLPD(QByteArray data, int wordLength);
    quint16 getNextSequenceNumber();

    QHostAddress *FPGA;

    quint16 sequenceCounter = 0;

    QPair<QByteArray,quint16> bufferConcentrador;
    QTimer *timerConcentrator;

    decoderAND *decoderAND;
    decoderLPD *decoderLPD;
    BotoneraMaster *botonera;
};

#endif // TRANSCIEVER_FPGA_H

//   Pedido DCL CONC
//   DCL CONC
//   AND1
//   AND2
//   LPD
