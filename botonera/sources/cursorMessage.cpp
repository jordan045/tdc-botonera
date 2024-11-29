#include "cursorMessage.h"
#include "qdebug.h"

// Constructor
CursorMessage::CursorMessage(
    QPair<qfloat16, qfloat16> coordinates,
    qfloat16 cursorAngle,
    qfloat16 cursorLength,
    int lineType
    ): coordinates(coordinates),
    cursorAngle(cursorAngle),
    cursorLength(cursorLength),
    lineType(lineType)
{
}

// Getters
QPair<qfloat16, qfloat16> CursorMessage::getCoordinates() const {
    return coordinates;
}

qfloat16 CursorMessage::getCursorAngle() const {
    return cursorAngle;
}

qfloat16 CursorMessage::getCursorLength() const {
    return cursorLength;
}

int CursorMessage::getLineType() const {
    return lineType;
}

// Setters
void CursorMessage::setCoordinates(QPair<qfloat16, qfloat16> newCoordinates) {
    coordinates = newCoordinates;
}

void CursorMessage::setCursorAngle(qfloat16 newCursorAngle) {
    cursorAngle = newCursorAngle;
}

void CursorMessage::setCursorLength(qfloat16 newCursorLength) {
    cursorLength = newCursorLength;
}

void CursorMessage::setLineType(int newLineType) {
    lineType = newLineType;
}

void CursorMessage::toString(){
    qDebug() << "--------------------------------";
    qDebug() << "COORDENADAS: " << coordinates.first << " " << coordinates.second;
    qDebug() << "ANGULO: " << cursorAngle;
    qDebug() << "LONGITUD: " << cursorLength;
    qDebug() << "TIPO DE LINEA: " << lineType;
}
