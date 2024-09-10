#ifndef ANDTRANSLATOR_H
#define ANDTRANSLATOR_H

#include <QObject>
#include <QString>

#define BYTE_LENGTH     8
#define START_OF_TEXT   0b0000010
#define END_OF_TEXT     0b0000011
#define HT              0b0001001
#define VT              0b0001011

class AndTranslator:public QObject
{
    Q_OBJECT
public:
    explicit AndTranslator(QObject *parent = nullptr);

    // // Método para convertir una cadena binaria a un carácter
    // QString binaryToChar(const QString &binaryString) const;

private:
    QByteArray getArray(QString &message);
    QString processMessage(QByteArray &message);

signals:
    void conversionResult(const QString &result);

public slots:
    void processBinaryString(QString &binaryString);
};
#endif // ANDTRANSLATOR_H


