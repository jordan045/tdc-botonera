#ifndef SCUDP_H
#define SCUDP_H

#include "andTranslator.h"
#include <QObject>
#include <QUdpSocket>

#define PORT 1111

class SCUDP : QObject
{
    Q_OBJECT

public:
    explicit SCUDP(QObject *parent = nullptr, AndTranslator *c = nullptr);
    void sendMessage(const QString &message, const QString &address, quint16 port);

private slots:
    void readPendingDatagrams();

private:
    QUdpSocket *udpSocket;
    //QByteArray datagram;
    void deviceAddress(QByteArray d);

    QByteArray bitwise(QByteArray &data);

    void pedidoDCLCONC();
    void DCLCONC();
    void AND1(QByteArray d);
    void AND2();
    void LPD();


    AndTranslator *converter;
};

#endif // SCUDP_H

//   Pedido DCL CONC
//   DCL CONC
//   AND1
//   AND2
//   LPD
