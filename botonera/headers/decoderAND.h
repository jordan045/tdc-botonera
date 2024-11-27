#ifndef DECODERAND_H
#define DECODERAND_H

#include <QObject>
#include <QString>

#define BYTE_LENGTH     8
#define START_OF_TEXT   0b0000010
#define END_OF_TEXT     0b0000011
#define HT              0b0001001
#define TRAILING_OFFSET 38

class decoderAND:public QObject
{
    Q_OBJECT
public:
    explicit decoderAND(QObject *parent = nullptr);
    void processAndMessage(QByteArray data);

private:
    QByteArray getArray(QString &message);
    QPair<int, QString> processMessage(QByteArray &message);

signals:
    void conversionResult(const QPair<int,QString> &result);


};
#endif // DECODERAND_H


