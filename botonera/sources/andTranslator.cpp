#include "AndTranslator.h"
#include <bitset>
#include <QDebug>

AndTranslator::AndTranslator(QObject *parent) : QObject(parent)
{
}




QString AndTranslator::binaryToChar(const QString &binaryString) const
{
    // Convertir la cadena binaria a un valor decimal
    bool ok;
    unsigned long decimalValue = binaryString.toULong(&ok, 2); // Base 2 para binario

    if (!ok) {
        qDebug() << "Error en la conversión de binario a decimal";
        return QString();
    }

    // Convertir el valor decimal a un carácter
    return QString(QChar(static_cast<ushort>(decimalValue)));
}

void AndTranslator::processBinaryString(const QString &binaryString)
{
    QString result = binaryToChar(binaryString);
    emit conversionResult(result);
}
