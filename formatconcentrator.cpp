#include "formatconcentrator.h"
#include "estado.h"
#include "qjsondocument.h"
#include <QFile>
#include<QDebug>

FormatConcentrator::FormatConcentrator()
{
    message = new QBitArray(216);
    word1 = new QBitArray(24);
    word2 = new QBitArray(24);
    word3 = new QBitArray(24);
    word4 = new QBitArray(24);
    word5 = new QBitArray(24);
    word6 = new QBitArray(24);
    word7 = new QBitArray(24);
    word8 = new QBitArray(24);
    word9 = new QBitArray(24);

}

QBitArray* FormatConcentrator::getMessage(Estado *estado)
{
    qDebug()<<"Me llamaron en concentrator";
    leerJson();
    setMessage(estado);
    setWord1(estado);
}

void FormatConcentrator::setMessage(Estado *estado)
{
    setWord1(estado);
    /*
    setWord2(estado);
    setWord3(estado);
    setWord4(estado);
    setWord5(estado);
    setWord6(estado);
    setWord7(estado);
    setWord8(estado);
    setWord9(estado);
    */
}

void FormatConcentrator::setWord1(Estado *estado)
{
    /*
    QVector<QString> codigos;
    QString rangoValor = archivo.value(estado->getRange()).toString();
    QString displayValor = archivo.value(estado->getDisplay()).toString();
    QString threatValor = archivo.value(estado->getThreat()).toString();

    codigos.push_back(rangoValor); //revisar como lo va a hacer uri
    codigos.push_back(displayValor);
    codigos.push_back(threatValor);
    int pos = 0;
    for (const auto& codigo : codigos) {
        for (QChar bit : codigo) {
            word1->setBit(pos++, bit == '1');
        }
    }
    */

    qDebug()<<"palabra 1";
    qDebug()<<archivo.value("rango").toString();
    //QString rangoValor = archivo.value(estado->getRange()).toString();
}

void FormatConcentrator::setWord2(Estado *estado)
{
    std::vector<std::string> codigos;
    for (const auto& modo:estado->getModos())
        word2->setBit(archivo["center"].toObject()[modo].toObject()["pos"].toInt(),1); //TA WANACOOO
}

void FormatConcentrator::setWord3(Estado *estado)
{


}

void FormatConcentrator::setWord4(Estado *estado)
{
    int pos = 0;
    QString qekizq = estado->getQekIzq();
    QString qekder = estado->getQekDer();
    for (QChar bit : archivo["qek"].toObject()[qekizq].toObject()["value"].toString()) {
        word1->setBit(pos++, bit == '1');
    }
    for (QChar bit : archivo["qek"].toObject()[qekder].toObject()["value"].toString()) {
        word1->setBit(pos++, bit == '1');
    }
}

void FormatConcentrator::setWord5(Estado *estado)
{
    word5->setBit(21,0);
    word5->setBit(13,0);
}

void FormatConcentrator::setWord6(Estado *estado)
{

}

void FormatConcentrator::setWord7(Estado *estado)
{

}

void FormatConcentrator::setWord8(Estado *estado)
{

}

void FormatConcentrator::setWord9(Estado *estado)
{

}

void FormatConcentrator::leerJson()
{
    QString JsonFilePath = "properties";
    qDebug()<<"Se llamo a leer json";
    QFile File(JsonFilePath);
    if(File.open(QIODevice::ReadOnly))
    {
         QByteArray Bytes = File.readAll();
        File.close();
         qDebug()<<"Se abró el json";
         QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes,&JsonError);
         if(JsonError.error != QJsonParseError::NoError)
        {
            qDebug()<<"ERROR in Json Data";
            return;
        }
        else
         {
             qDebug()<<"No Any Error in Json Data";
         }
        if(Document.isObject())
         archivo = Document.object();
    }
    else
    {
        qDebug()<<"Hubo un error, no se abrio el archivo";
    }
}
