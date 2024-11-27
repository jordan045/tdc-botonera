#ifndef MARKERMESSAGE_H
#define MARKERMESSAGE_H

#include <QPair>
#include <QByteArray>
#include <qfloat16.h>

class MarkerMessage
{
private:
    QPair<qfloat16, qfloat16> coordinates;
    QByteArray mainSymbol;
    QByteArray courseIndicator;
    QByteArray amplInfo;
    QByteArray linkStatus;
    QByteArray trackNumber;
    bool PV;
    bool AP;
    bool LS;

public:
    explicit MarkerMessage(
        QPair<qfloat16, qfloat16> coordinates,
        QByteArray mainSymbol,
        QByteArray courseIndicator = QByteArray(1, 0x0),
        QByteArray amplInfo = QByteArray(2, 0x0),
        QByteArray linkStatus = QByteArray(1, 0x0),
        QByteArray trackNumber = QByteArray(4,0x0),
        bool PV = false,
        bool AP = false,
        bool LS = false
        );

    // Getters
    QPair<qfloat16, qfloat16> getCoordinates() const;
    QByteArray getMainSymbol() const;
    QByteArray getCourseIndicator() const;
    QByteArray getAmplInfo() const;
    QByteArray getLinkStatus() const;
    QByteArray getTrackNumber() const;

    // Setters
    void setCoordinates(QPair<qfloat16, qfloat16> coordinates);
    void setMainSymbol(QByteArray mainSymbol);
    void setCourseIndicator(QByteArray courseIndicator);
    void setAmplInfo(QByteArray amplInfo);
    void setLinkStatus(QByteArray linkStatus);
    void setTrackNumber(QByteArray trackNumber);

    void toString();
};

#endif // MARKERMESSAGE_H
