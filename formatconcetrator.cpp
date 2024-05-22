#include "formatconcetrator.h"

int pos = 0;
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

QBitArray* formatConcetrator::getMessage(estado *elEstado)
{
    miestado = elestado;
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
    codigos.push_back(json.value(miEstado->getScale().toString)); //revisar como lo va a hacer uri
    codigos.push_back(json.value(miEstado->getDisplay().toString));
    codigos.push_back(json.value(miEstado->getEvaluacionAmenza().toString)).toString();
    for (const auto& codigo : codigos) {
        for (char bit : codigo) {
            word1->setBit(pos++, bit == '1');
        }
    }
}

void formatConcetrator::setWord2()
{
    std::vector<std::string> codigos;
    codigos.push_back(json.value(miEstado->getScale().toString)); //revisar como lo va a hacer uri
    codigos.push_back(json.value(miEstado->getDisplay().toString));
    codigos.push_back(json.value(miEstado->getEvaluacionAmenza().toString)).toString();
    for (const auto& codigo : codigos) {
        for (char bit : codigo) {
            word1->setBit(pos++, bit == '1');
        }
    }
}

void formatConcetrator::setWord3()
{

}

void formatConcetrator::setWord4()
{

}

void formatConcetrator::setWord5()
{

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
         json = Document.object();
    }
}
