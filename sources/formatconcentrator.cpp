#include "formatconcentrator.h"
#include "estado.h"
#include "qjsondocument.h"
#include <QFile>
#include<QDebug>

FormatConcentrator::FormatConcentrator()
{
    message = new QBitArray(216);
    /*
    word1 = new QBitArray(24);
    word2 = new QBitArray(48);
    word3 = new QBitArray(72);
    word4 = new QBitArray(96);
    word5 = new QBitArray(120);
    word6 = new QBitArray(144);
    word7 = new QBitArray(168);
    word8 = new QBitArray(192);
    word9 = new QBitArray(216);
    */
    leerJson();
}

QBitArray* FormatConcentrator::getMessage(Estado *estado)
{
    qDebug()<<"Me llamaron en concentrator";
    setMessage(estado);
   // setWord1(estado);
}

void FormatConcentrator::setMessage(Estado *estado)
{

    /*
    setWord1(estado);
    qDebug()<< "palabra 1 " << word1[0];

    setWord2(estado);
    qDebug()<< "palabra 2 " <<word2[0];

    //setWord3(estado);
    setWord4(estado);
    qDebug()<<"palabra 4" <<word4[0];
    setWord5(estado);
    qDebug()<<"palabra 5:"<<word5[0];

    setWord6(estado);
    setWord7(estado);
    setWord8(estado);
    setWord9(estado);
    juntar();*/
    setRange(estado);
    setDisplaySelection(estado);
    setThreat(estado);
    setCenter(estado);
    setDisplayMode(estado);
    setQEK(estado);
    setICM(estado);
    setOverlay(estado);


    qDebug()<< "palabraCompleta: "<<message[0];

    //setRange(estado);
}
// PALABRA 1//
void FormatConcentrator::setRange(Estado *estado)
{
    // RANGO
    QStringList wordListRange = estado->getRange().split(" ", Qt::SkipEmptyParts);

    // Itera sobre cada palabra en la lista de palabras
    foreach(const QString &word, wordListRange) {
        qDebug() << "Procesando palabra:" << word;

        // Obtiene el objeto JSON "range_scale" del archivo
        QJsonObject rango = archivo["range_scale"].toObject();

        // Depuración: Muestra el rango actual
        qDebug() << "Rango obtenido del estado:" << estado->getRange();

        // Obtiene el objeto JSON asociado a la palabra actual
        QJsonObject rangoActual = rango[word].toObject();

        // Obtiene el valor asociado a la palabra actual en forma de cadena
        QString palabraRango = rangoActual["value"].toString();

        // Depuración: Muestra el valor de rango obtenido
        qDebug() << "Valor de rango:" << palabraRango;

        // Inicializa un índice para establecer los bits
        int i = 23;

        // Itera sobre cada carácter en la cadena de valor de rango
        for(QChar caracter : palabraRango) {
            // Si el carácter es '1', establece el bit correspondiente a verdadero
            if(caracter == '1') {
                message->setBit(i, true);
            } else {
                // Si el carácter no es '1', establece el bit correspondiente a falso
                message->setBit(i, false);
            }
            // Decrementa el índice
            i--;

        }
    }
}
    void FormatConcentrator::setDisplaySelection(Estado *estado)
        {
        //DISPLAY SELECTION
        QStringList wordListDSelection = estado->getDisplaySelection().split(" ", Qt::SkipEmptyParts);
        // BUSCO LA POSICION COMO UN STRING Y LO TRANSFORMO EN INT.
        //DISPLAY SELECTION
        foreach(const QString &word,wordListDSelection){
            qDebug() << "Procesando palabra displaySelection:" << word;
            QJsonObject display = archivo["display_selection"].toObject();
            QJsonObject displayActual = display[word].toObject();
            QString posicion = displayActual["pos"].toString();

            message->setBit(posicion.toInt(),true);
        }
    }

void FormatConcentrator::setThreat(Estado *estado)
{
    QStringList wordListThreat = estado->getThreat().split(" ", Qt::SkipEmptyParts);
    // BUSCO LA POSICION COMO UN STRING Y LO TRANSFORMO EN INT.
    //DISPLAY SELECTION
    foreach(const QString &word,wordListThreat)
    {
        qDebug() << "Procesando palabra ThreatAssesment:" << word;
        QJsonObject threat = archivo["threat_assesment"].toObject();
        QJsonObject threatActual = threat[word].toObject();
        QString posicion = threatActual["pos"].toString();

        message->setBit(posicion.toInt(),true);
    }
}

void FormatConcentrator::setCenter(Estado *estado)
{
    int offset = 24;
    QStringList wordListCenter = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListCenter)
    {
        qDebug() << "Procesando palabra Center:" << word;
        QJsonObject center = archivo["center"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString posicion = centerActual["pos"].toString();

        message->setBit(offset + posicion.toInt(),true);
    }
}
void FormatConcentrator::setDisplayMode(Estado *estado)
{
    int offset = 24;
    int posFinal = 0;   //para probrar
    QStringList wordListDisplayMode = estado->getDisplayMode().split(" ",Qt::SkipEmptyParts);
    foreach(const QString &word, wordListDisplayMode)
    {

        qDebug() << "Procesando palabra DisplayMode:" << word;
        QJsonObject center = archivo["display_mode"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString posicion = centerActual["pos"].toString();
        qDebug()<<"posicion: " << posicion;
        posFinal = offset+posicion.toInt();
        message->setBit(posFinal,true);
    }
}

void FormatConcentrator::setQEK(Estado *estado)
{
    int offset = 96;
    QStringList wordListQek = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
        qDebug() << "Procesando palabra qek:" << word;
        QJsonObject qek = archivo["qek"].toObject();
        QJsonObject qekActual = qek[word].toObject();
        QString posicion = qekActual["value"].toString();

        int i = offset-1;
        for(QChar caracter:posicion)
        {
            if(caracter == '1')
                message->setBit(i,true);
            else
                message->setBit(i,false);
            i--;
        }
    }
}
void FormatConcentrator::setICM(Estado *estado){
    int offset = 119;
    QStringList wordListQek = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
        qDebug() << "Procesando palabra qek:" << word;
        QJsonObject qek = archivo["qek"].toObject();
        QJsonObject qekActual = qek[word].toObject();
        QString posicion = qekActual["value"].toString();
        int i = offset;
        for(QChar caracter:posicion)
        {
            if(caracter == '1')
                message->setBit(i,true);
            else
                message->setBit(i,false);
            i--;
        }
    }
}
void FormatConcentrator::setOverlay(Estado *estado){

    int offset = 115;
    QString overlay = estado->getOverlay();
    for(QChar caracter:overlay)
    {
        if (caracter == '1')
            message->setBit(offset,true);
        else
            message->setBit(offset,false);
        offset--;
    }
}
/*
void FormatConcentrator::setWord1(Estado *estado)
{
    // RANGO

    QStringList wordListRange = estado->getRange().split(" ", Qt::SkipEmptyParts);

    // Itera sobre cada palabra en la lista de palabras
    foreach(const QString &word, wordListRange) {
        qDebug() << "Procesando palabra:" << word;

        // Obtiene el objeto JSON "range_scale" del archivo
        QJsonObject rango = archivo["range_scale"].toObject();

        // Depuración: Muestra el rango actual
        qDebug() << "Rango obtenido del estado:" << estado->getRange();

        // Obtiene el objeto JSON asociado a la palabra actual
        QJsonObject rangoActual = rango[word].toObject();

        // Obtiene el valor asociado a la palabra actual en forma de cadena
        QString palabraRango = rangoActual["value"].toString();

        // Depuración: Muestra el valor de rango obtenido
        qDebug() << "Valor de rango:" << palabraRango;

        // Inicializa un índice para establecer los bits
        int i = 23;

        // Itera sobre cada carácter en la cadena de valor de rango
        for(QChar caracter : palabraRango) {
            // Si el carácter es '1', establece el bit correspondiente a verdadero
            if(caracter == '1') {
                word1->setBit(i, true);
            } else {
                // Si el carácter no es '1', establece el bit correspondiente a falso
                word1->setBit(i, false);
            }
            // Decrementa el índice
            i--;

        }
    }
    //DISPLAY SELECTION

    QStringList wordListDSelection = estado->getDisplaySelection().split(" ", Qt::SkipEmptyParts);
    // BUSCO LA POSICION COMO UN STRING Y LO TRANSFORMO EN INT.
    //DISPLAY SELECTION
    foreach(const QString &word,wordListDSelection)
    {
        qDebug() << "Procesando palabra displaySelection:" << word;
        QJsonObject display = archivo["display_selection"].toObject();
        QJsonObject displayActual = display[word].toObject();
        QString posicion = displayActual["pos"].toString();

        word1->setBit(posicion.toInt(),true);
    }

    //THREATASSESMENT
    QStringList wordListThreatAss = estado->getThreat().split(" ", Qt::SkipEmptyParts);
    // BUSCO LA POSICION COMO UN STRING Y LO TRANSFORMO EN INT.
    foreach(const QString &word,wordListThreatAss)
    {
        qDebug() << "Procesando palabra ThreatAssesment:" << word;
        QJsonObject threat = archivo["threat_assesment"].toObject();
        QJsonObject threatActual = threat[word].toObject();
        QString posicion = threatActual["pos"].toString();

        word1->setBit(posicion.toInt(),true);
    }
}

void FormatConcentrator::setWord2(Estado *estado)
{
    int offset = 24;
    //CENTER
    QStringList wordListCenter = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListCenter)
    {
        qDebug() << "Procesando palabra Center:" << word;
        QJsonObject center = archivo["center"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString posicion = centerActual["pos"].toString();

        word2->setBit(offset + posicion.toInt(),true);
    }

    //DISPLAY SELECTION
    QStringList wordListDisplayMode = estado->getDisplayMode().split(" ",Qt::SkipEmptyParts);
    foreach(const QString &word, wordListDisplayMode)
    {

        qDebug() << "Procesando palabra DisplayMode:" << word;
        QJsonObject center = archivo["display_mode"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString posicion = centerActual["pos"].toString();

        word2->setBit(offset + posicion.toInt(),true);
    }
}

void FormatConcentrator::setWord3(Estado *estado)
{

}

void FormatConcentrator::setWord4(Estado *estado)
{
    int offset = 72;
    QStringList wordListQek = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
        qDebug() << "Procesando palabra qek:" << word;
        QJsonObject qek = archivo["qek"].toObject();
        QJsonObject qekActual = qek[word].toObject();
        QString posicion = qekActual["value"].toString();

        int i = offset-1;
        for(QChar caracter:posicion)
        {
            if(caracter == '1')
                word4->setBit(i,true);
            else
                word4->setBit(i,false);
            i--;
        }
    }
}

void FormatConcentrator::setWord5(Estado *estado)
{
    int offset = 119;
    QStringList wordListICM = estado->getICM().split(" ",Qt::SkipEmptyParts);
    foreach(const QString &word, wordListICM)
    {

        qDebug() << "Procesando palabra ICM:" << word;
        QJsonObject center = archivo["icm"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString valor = centerActual["value"].toString();

        for(QChar caracter:valor)
        {
            if(caracter == '1')
                word5->setBit(offset,true);
            else
                word5->setBit(offset,false);
            offset--;
        }
    }
    word5->setBit(offset,false);
    offset--;

    //OVERLAY
    QString overlay = estado->getOverlay();
    for(QChar caracter:overlay)
    {
        if (caracter == '1')
            word5->setBit(offset,true);
        else
            word5->setBit(offset,false);
        offset--;
    }
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
*/
void FormatConcentrator::leerJson()
{
    QString JsonFilePath = ":/json/json/properties.json";
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
/*
void FormatConcentrator::juntar()
{
    *message = *word1|*word2|*word3|*word4|*word5|*word6|*word7|*word8|*word9;
}
*/
