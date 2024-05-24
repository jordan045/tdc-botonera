#include "formatconcetrator.h"
#include <QFile>

formatConcetrator::formatConcetrator()
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

QBitArray* formatConcetrator::getMessage(Estado *estado)
{
    miEstado = estado;
    leerJson();
    setMessage();
    return message;
}

void formatConcetrator::setMessage()
{
    setWord1();
    setWord2();
    setWord3();
    setWord4();
    setWord5();
    setWord6();
    setWord7();
    setWord8();
    setWord9();


}

void formatConcetrator::setWord1()
{
    std::vector<std::string> codigos;
    QString rangoValor = archivo.value(miEstado.getRange());
    codigos.push_back(); //revisar como lo va a hacer uri
    codigos.push_back(archivo.value(miEstado->getDisplay());
    codigos.push_back(archivo.value(miEstado->getThreat());
    int pos = 0;
    for (const auto& codigo : codigos) {
        for (char bit : codigo) {
            word1->setBit(pos++, bit == '1');
        }
    }
}

void formatConcentrator::setWord2()
{
    std::vector<std::string> codigos;
    for (const auto& modo:miEstado.getModos)
        word2->setBit(archivo["center"].toObject[modo].toObject["pos"].toInt,1); //TA WANACOOO
}

void formatConcetrator::setWord3()
{


}

void formatConcetrator::setWord4()
{
    String qekizq = miestado.getQekIzq();
    String qekder = miestado.getQekDer();
    for (char bit : archivo["qek"].toObject[qekizq].toObject["value"].toString) {
        word1->setBit(pos++, bit == '1');
    }
    for (char bit : archivo["qek"].toObject[qekder].toObject["value"].toString) {
        word1->setBit(pos++, bit == '1');
    }
}

void formatConcetrator::setWord5()
{
    word5->setBit(21,0);
    word5->setBit(13,0);
}

void formatConcetrator::setWord6()
{

}

void formatConcetrator::setWord7()
{

}

void formatConcetrator::setWord8()
{

}

void formatConcetrator::setWord9()
{

}

void formatConcetrator::leerJson()
{
    QString JsonFilePath = "QtJson.json";

    QFile File(JsonFilePath);
    if(File.open(QIODevice::ReadOnly)
    {
         QByteArray Bytes = File.readAll();
        File.close();

         QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes,&JsonError);
         if(JsonError.error != QJsonParseError::NoError)
        {
            qDebug()<<"ERROR in Json Data";)
            return;
        }
        else
         {
             qDebug()<<"No Any Error in Json Data";
         }
        if(Document.isObject())
         archivo = Document.object();
    }
}
