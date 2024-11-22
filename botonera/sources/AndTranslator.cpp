#include "andTranslator.h"
#include <QDebug>
#include <QFile>

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

void AndTranslator::processBinaryString(QByteArray data)
{
    QPair<int, QString> result;
    result = processMessage(data);
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

QPair<int,QString> AndTranslator::processMessage(QByteArray &message){
    QPair<int,QString> result;

    QString text = "";
    char row = message[2] & 0x0F;           //Extraer fila del tercer campo del mensaje
    int column = message[4];                //Extraer columna del quinto campo del mensaje
    int index = 5;                          //Comienza en 5 porque ahi está el primer caracter
    char nextChar = message[index];         //Extraer primer caracter del sexto campo
    int num_row = static_cast<int>(row);

    // Convertir el valor de 'row' a hexadecimal
    char rowH = message[2];
    QString rowHex = QString::number(rowH, 16).toUpper().rightJustified(2, '0');

    qDebug() << "Row en hexadecimal:" << rowHex;

    while(nextChar != END_OF_TEXT){
        text.append(nextChar);
        index++;
        nextChar = message[index];
    }

    if(num_row == 15){
        char asterix_column = message[TRAILING_OFFSET + 4] & 0x1F; //Extremos la columna donde va el asterisco, solo necesitamos los primeros 5 bits
        int num_asterix_column = static_cast<int>(asterix_column);
        text[num_asterix_column] = message[TRAILING_OFFSET + 5];
    }

    // Si estamos pintando la fila numero 15, tendremos un pequeño mensaje al final (con STX,VT, etc.)
    // Leemos esa pequeña porción para pintar el asterisco donde corresponda

    result.first = num_row;
    result.second = text;

    return result;
}
