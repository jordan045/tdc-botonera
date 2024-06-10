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
    qDebug()<< word1[0];
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

    qDebug()<<"palabra 1";
    QJsonObject rango = archivo["range_scale"].toObject();
    QJsonObject rangoActual = rango[estado->getRange()].toObject();
    QString palabraRango = rangoActual["value"].toString();

    //Formo los primeros 3 bits
    int i = 23;
    for(QChar caracter : palabraRango)
    {
        if(caracter == '1')
        {
            word1->setBit(i,true);
        }
        else
        {
            word1->setBit(i,false);
        }
        i--;
    }

    // BUSCO LA POSICION COMO UN STRING Y LO TRANSFORMO EN INT.
    //DISPLAY SELECTION
    QJsonObject display = archivo["display_selection"].toObject();
    QJsonObject displayActual = display[estado->getDisplaySelection()].toObject();
    QString posicion = displayActual["pos"].toString();

    //THREAT ASSESMENT
    QJsonObject threat = archivo["threat_assesment"].toObject();
    QJsonObject threatActual = display[estado->getThreat()].toObject();

    word1->setBit(posicion.toInt(),true);
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
    QString JsonFilePath = "C:/Users/winra/OneDrive/Escritorio/SIAG/qtJuego/qt-juego/properties.json";
    qDebug()<<"Se llamo a leer json";
    QFile File(JsonFilePath);
    if(File.open(QIODevice::ReadOnly))
    {
         QByteArray Bytes = File.readAll();
        File.close();
         qDebug()<<"Json has open correctly";
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
