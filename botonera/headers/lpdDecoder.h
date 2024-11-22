#ifndef LPDDECODER_H
#define LPDDECODER_H

#include "cursorMessage.h"
#include "markerMessage.h"
#include <QObject>

#define END_OF_MARKER_MESSAGE 0x17
#define WORD_LENGTH 3 //en bytes
#define LONG_MESSAGE_LENGTH 18
#define SHORT_MESSAGE_LENGTH 9
#define CURSOR_MESSAGE_LENGTH 12
#define DECENTERED_MESSAGE_LENGTH 6

#define MARKER_ID 0x01
#define CURSOR_ID 0x05
#define DECENTERED_ID 0x09

class LPDDecoder: public QObject
{
    Q_OBJECT
public:
    explicit LPDDecoder(QObject *parent = nullptr);
    void processLPDMessage(QByteArray data, int wordLenght);

private:
    QByteArray getArray(QString &message);
    void processMessage(QByteArray &message, int wordLength, QList<MarkerMessage> &markerList, QList<CursorMessage> &cursorList);
    QPair<qfloat16,qfloat16> getCoords(QByteArray message, int offset);

signals:
    void processResult(const QList<MarkerMessage> &markerList, QList<CursorMessage> &cursorList);
};

#endif // LPDDECODER_H
