#ifndef TRANSCIEVER_FPGA_H
#define TRANSCIEVER_FPGA_H

#include "andTranslator.h"
#include "botoneraMaster.h"
#include "lpdDecoder.h"
#include <QObject>
#include <QUdpSocket>
#include <QTimer>

#define PORT 9000
#define IP "172.16.0.100"

#define DA_CONCENTRADOR 0x04
#define DA_AND1 0x02
#define DA_AND2 0x03
#define DA_LPD 0x00
#define DA_PEDIDO_CONCENTRADOR 0x01

class Transciever_FPGA : public QObject
{
    Q_OBJECT

public:
    explicit Transciever_FPGA(QObject *parent = nullptr, AndTranslator *c = nullptr,BotoneraMaster *botonera = nullptr, LPDDecoder *decoder = nullptr);
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
    QTimer timerConcentrador;

    AndTranslator *converter;
    LPDDecoder *decoder;
    BotoneraMaster *botonera;
};

#endif // TRANSCIEVER_FPGA_H

//   Pedido DCL CONC
//   DCL CONC
//   AND1
//   AND2
//   LPD
