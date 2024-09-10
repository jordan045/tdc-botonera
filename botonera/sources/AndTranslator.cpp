#include "AndTranslator.h"
#include <QDebug>

AndTranslator::AndTranslator(QObject *parent) : QObject(parent)
{
}
// QString AndTranslator::binaryToChar(const QString &message) const
// {
//     // Convertir la cadena binaria a un valor decimal
//     bool ok;
//     unsigned long decimalValue = message.toULong(&ok, 2); // Base 2 para binario

//     if (!ok) {
//         qDebug() << "Error en la conversión de binario a decimal";
//         return QString();
//     }

//     // Convertir el valor decimal a un carácter
//     return QString(QChar(static_cast<ushort>(decimalValue)));
// }

void AndTranslator::processBinaryString(QString &binaryString)
{
    QByteArray messageArray = getArray(binaryString);
    QString result = processMessage(messageArray);
    emit conversionResult(result);
}

QByteArray AndTranslator::getArray(QString &message){
    QByteArray byteArray;

    for (int i = 0; i < message.length(); i += BYTE_LENGTH) {
        QString byteString = message.sliced(i, BYTE_LENGTH);
        bool ok;
        char byte = static_cast<char>(byteString.toUInt(&ok, 2)); // Convertir binario a uint y luego a char
        if (ok) {
            byteArray.append(byte);
        } else {
            qWarning() << "Error al convertir la cadena binaria a byte.";
        }
    }

    return byteArray;
}

QString AndTranslator::processMessage(QByteArray &message){
    QString text = "";
    int row = message[2];           //Extraer fila del tercer campo del mensaje
    int column = message[4];        //Extraer columna del quinto campo del mensaje
    int index = 5;                  //Comienza en 5 porque ahi está el primer caracter
    char nextChar = message[index]; //Extraer primer caracter del sexto campo

    while(nextChar != END_OF_TEXT){
        text.append(nextChar);
        index++;
        nextChar = message[index];
    }
    return text;
}

