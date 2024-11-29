#include "markerMessage.h"
#include "qdebug.h"

MarkerMessage::MarkerMessage(
    QPair<qfloat16, qfloat16> coordinates,
    QByteArray mainSymbol,
    QByteArray courseIndicator,
    QByteArray amplInfo,
    QByteArray linkStatus,
    QByteArray trackNumber,
    bool PV, bool AP, bool LS
    ) : coordinates(coordinates),
    mainSymbol(mainSymbol),
    courseIndicator(courseIndicator),
    amplInfo(amplInfo),
    linkStatus(linkStatus),
    trackNumber(trackNumber),
    PV(PV),
    AP(AP),
    LS(LS)
{
}

// Getters
QPair<qfloat16, qfloat16> MarkerMessage::getCoordinates() const {
    return coordinates;
}

QByteArray MarkerMessage::getMainSymbol() const {
    return mainSymbol;
}

QByteArray MarkerMessage::getCourseIndicator() const {
    return courseIndicator;
}

QByteArray MarkerMessage::getAmplInfo() const {
    return amplInfo;
}

QByteArray MarkerMessage::getLinkStatus() const {
    return linkStatus;
}

QByteArray MarkerMessage::getTrackNumber() const {
    return trackNumber;
}

// Setters
void MarkerMessage::setCoordinates(QPair<qfloat16, qfloat16> newCoordinates) {
    coordinates = newCoordinates;
}

void MarkerMessage::setMainSymbol(QByteArray newMainSymbol) {
    mainSymbol = newMainSymbol;
}

void MarkerMessage::setCourseIndicator(QByteArray newCourseIndicator) {
    courseIndicator = newCourseIndicator;
}

void MarkerMessage::setAmplInfo(QByteArray newAmplInfo) {
    amplInfo = newAmplInfo;
}

void MarkerMessage::setLinkStatus(QByteArray newLinkStatus) {
    linkStatus = newLinkStatus;
}

void MarkerMessage::setTrackNumber(QByteArray newTrackNumber) {
    trackNumber = newTrackNumber;
}

// toString method
void MarkerMessage::toString() {
    qDebug() << "----------------------------------------";
    qDebug() << "COORDENADAS: " << coordinates.first << " " << coordinates.second;
    qDebug() << "MAIN SYMBOL: " << mainSymbol;
    qDebug() << "COURSE INDICATOR: " << courseIndicator;
    qDebug() << "AMPL INFO: " << amplInfo;
    qDebug() << "LINK STATUS: " << linkStatus;
    qDebug() << "TRACK NUMBER: " << trackNumber;
    qDebug() << "PV: " << PV;
    qDebug() << "AP: " << AP;
    qDebug() << "LS: " << LS;
}
