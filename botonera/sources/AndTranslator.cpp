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

void AndTranslator::processBinaryString()
{
    QFile file(":/binary/one_page.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo";
        return;
    }

    // Crear un QTextStream para leer el archivo línea por línea
    QTextStream in(&file);
    QPair<int,QString> result;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QByteArray messageArray = getArray(line);
        result = processMessage(messageArray);
        qDebug() << result.second;
        emit conversionResult(result);
    }
    file.close();


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

    while(nextChar != END_OF_TEXT){
        text.append(nextChar);
        index++;
        nextChar = message[index];
    }
    int num_row = static_cast<int>(row);
    result.first = num_row;
    result.second = text;

    return result;
}
