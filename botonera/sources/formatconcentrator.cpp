#include "formatconcentrator.h"
#include "qjsondocument.h"
#include <QFile>
#include <QDebug>

//Setear en true para generar los logs
#define LOG true

#define WORD_SIZE 24
#define WORD_COUNT 8

FormatConcentrator::FormatConcentrator()
{
    message = new QBitArray(WORD_COUNT * WORD_SIZE);
    leerJson();
}

QByteArray FormatConcentrator::getMessage(IEstado *estado)
{
    setMessage(estado);
    QByteArray byteArrayMessage = bitArrayToByteArray(*message);
    return byteArrayMessage;
}

QByteArray FormatConcentrator::bitArrayToByteArray(const QBitArray &bitArray) {
    QByteArray byteArray((bitArray.size() + 7) / 8, 0); // Inicializa el QByteArray al tamaño necesario

    // Itera sobre cada bit y usa operaciones de desplazamiento para obtener su valor
    for (int i = 0; i < bitArray.size(); ++i) {
        byteArray[i / 8] |= (bitArray.testBit(i) ? 1 : 0) << (7 - (i % 8));
    }

    return byteArray;
}

void FormatConcentrator::setMessage(IEstado *estado)
{
    setRange(estado);
    setDisplaySelection(estado);
    setThreat(estado);
    setCenter(estado);
    setDisplayMode(estado);
    setQEK(estado);
    setICM(estado);
    setOverlay(estado);
    setMIK(estado);
    setIcmS(estado);
    setQekS(estado);
    setOverlayS(estado);
    setDisplayModeS(estado);
    setCenterS(estado);

    //Crear el log si la flag esta activa
    if(LOG)
        guardarMensaje(estado);
}

//------------------------------Setters------------------------------------------------//
//FUNCIONA
void FormatConcentrator::setRange(IEstado *estado)
{
    QStringList wordListRange = estado->getRange().split(" ", Qt::SkipEmptyParts);

    foreach(const QString &word, wordListRange) {
        QJsonObject rango = buttonJson["RANGE_SCALE"].toObject();
        QString rangoActual = rango[word].toString();

        // Inicializa un índice para establecer los bits
        int i = 0;
        for(QChar caracter : rangoActual) {
            if(caracter == '1') {
                message->setBit(i, true);
            } else {
                message->setBit(i, false);
            }
            i++;
        }
    }
}

//FUNCIONA
void FormatConcentrator::setDisplaySelection(IEstado *estado)
{
    QStringList wordListDSelection = estado->getDisplaySelection().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListDSelection){
        QJsonObject display = buttonJson["DISPLAY_SELECTION"].toObject();
        QString displayActual = display[word].toString();
        qDebug()<<"Posicion display Actual" + displayActual;
        int posicion = displayActual.toInt();
        message->setBit(posicion,true);
    }
}

void FormatConcentrator::setThreat(IEstado *estado)
{
    QStringList wordListThreat = estado->getThreat().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListThreat)
    {
        QJsonObject threat = buttonJson["THREAT_ASSESMENT"].toObject();
        QString threatActual = threat[word].toString();
        int posicion = threatActual.toInt();
        message->setBit(posicion,true);
    }
}

void FormatConcentrator::setCenter(IEstado *estado)
{
    int palabra = WORD_SIZE * 1; //Está en la segunda palabra
    QStringList wordListCenter = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListCenter)
    {
        QJsonObject center = buttonJson["CENTER"].toObject();
        QString centerActual = center[word].toString();
        int posicion = centerActual.toInt();
        message->setBit(palabra + posicion,true);
    }
}

void FormatConcentrator::setCenterS(IEstado* estado)
{
    int palabra = WORD_SIZE*1;
    QStringList wordlistCenterS = estado->getCenterS().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word, wordlistCenterS) {

        QJsonObject centerS = buttonJson["CENTER"].toObject();
        QString centerSActual = centerS[word].toString();
        int posicion = centerSActual.toInt();
        message->setBit(palabra+posicion,true);
    }
}


void FormatConcentrator::setDisplayMode(IEstado *estado)
{
    int palabra = WORD_SIZE * 1; //Está en la segunda palabra
    QStringList wordListDisplayMode = estado->getDisplayMode().split(" ",Qt::SkipEmptyParts);
    foreach(const QString &word, wordListDisplayMode)
    {
        QJsonObject displayMode = buttonJson["DISPLAY_MODE"].toObject();
        QString displayModeActual = displayMode[word].toString();
        int posicion = displayModeActual.toInt();
        message->setBit(palabra+posicion,true);
    }
}

void FormatConcentrator::setDisplayModeS(IEstado *estado)
{
    int palabra = WORD_SIZE*1;
    QStringList wordListDisplayModeS = estado->getDisplayModeS().split(" ",Qt::SkipEmptyParts);
    foreach(const QString &word, wordListDisplayModeS)
    {
        QJsonObject displayMode = buttonJson["DISPLAY_MODE"].toObject();
        QString displayModeActual = displayMode[word].toString();
        int posicion = displayModeActual.toInt();
        message->setBit(palabra+posicion,true);
    }
}



void FormatConcentrator::setQEK(IEstado *estado)
{
    int palabra = WORD_SIZE * 3; //Está en la cuarta palabra;
    int offset = 0;
    QStringList wordListQek = estado->getQEK().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
        QJsonObject qek = buttonJson["QEK"].toObject();
        QString qekActual = qek[word].toString();
        for(QChar caracter:qekActual)
        {
            if(caracter == '1')
                message->setBit(palabra+offset,true);
            else
                message->setBit(palabra+offset,false);
            offset++;
        }
    }
}

void FormatConcentrator::setQekS(IEstado *estado)
{
    int palabra = WORD_SIZE * 3; //Está en la cuarta palabra;
    int offset = 8;
    QStringList wordListQek = estado->getQEKS().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
        QJsonObject qek = buttonJson["QEK"].toObject();
        QString qekActual = qek[word].toString();

        for(QChar caracter:qekActual)
        {
            if(caracter == '1')
                message->setBit(palabra+offset,true);
            else
                message->setBit(palabra+offset,false);
            offset++;
        }
    }
}


void FormatConcentrator::setICM(IEstado *estado){
    int palabra= WORD_SIZE * 4; //Está en la quinta palabra;
    int offset = 0;
    QStringList wordListICM = estado->getICM().split(" ", Qt::SkipEmptyParts);
    qDebug()<<"Posicion donde comienza ICM:"+ palabra;
    if(wordListICM.size() == 0)
    {
        for(offset;offset<3;offset++)
            message->setBit(palabra+offset,true);
    }
    foreach(const QString &word,wordListICM)
    {
        QJsonObject ICM = buttonJson["ICM"].toObject();
        QString ICMActual = ICM[word].toString();
        for(QChar caracter:ICMActual)
        {
            if(caracter == '1')
                message->setBit(palabra+offset,true);
            else
                message->setBit(palabra+offset,false);
            offset++;
        }
    }
}

void FormatConcentrator::setIcmS(IEstado *estado)
{
    int palabra= WORD_SIZE * 3; //Está en la cuarta palabra;
    int offset = 8;
    QStringList wordListICMS = estado->getICMS().split(" ", Qt::SkipEmptyParts);
    qDebug()<<"Posicion donde comienza ICM:"+ palabra;
    if(wordListICMS.size() == 0)
    {
        for(offset;offset<3;offset++)
            message->setBit(palabra+offset,true);
    }
    foreach(const QString &word,wordListICMS)
    {
        QJsonObject ICMS = buttonJson["ICM"].toObject();
        QString ICMSActual = ICMS[word].toString();
        for(QChar caracter:ICMSActual)
        {
            if(caracter == '1')
                message->setBit(palabra+offset,true);
            else
                message->setBit(palabra+offset,false);
            offset++;
        }
    }
}


void FormatConcentrator::setOverlay(IEstado *estado){

    int palabra = (WORD_SIZE * 4); //115
    int offset = 4;
    QString overlay = estado->getOverlay();
    for(QChar caracter:overlay)
    {
        if (caracter == '1')
            message->setBit(palabra+offset,true);
        else
            message->setBit(palabra+offset,false);
        palabra++;
    }
}

void FormatConcentrator::setMIK(IEstado *estado)
{
    int palabra = WORD_SIZE * 2;
    int offset = 0;
    QString mikPalabra = estado->getMIK();

    qDebug()<<"Se invocó a setMIK, palabra mik:" <<mikPalabra;
    if(mikPalabra != ""){
        QJsonObject teclasMik = MIKJson["teclas"].toObject();
        qDebug()<< "la letra es: "<< mikPalabra;
        QJsonObject mikBinario = teclasMik[mikPalabra].toObject();
        QString mik = mikBinario["ASCII_Binario"].toString();
        qDebug()<< "La letra representa: "<< mik;
        for (QChar caracter:mik) {
            if(caracter == '1'){
                message->setBit(palabra+offset,true);
            } else {
                message->setBit(palabra+offset,false);
            }
            offset++;
        }
    }
    else{
        for(char caracter:"01000000"){
            if(caracter == '1'){
                message->setBit(palabra+offset,true);
            } else {
                message->setBit(palabra+offset,false);
            }
            offset++;
        }
    }
    qDebug() << "\nMI:\t " << "-" << mikPalabra  << "-";
}

void FormatConcentrator::setOverlayS(IEstado *estado){

    int palabra = WORD_SIZE*4;
    int offset = 12;

    QString overlay = estado->getOverlayS();
    for(QChar caracter:overlay)
    {
        if (caracter == '1')
            message->setBit(palabra+offset,true);
        else
            message->setBit(palabra+offset,false);
        offset++;
    }
}

void FormatConcentrator::removeQEK()
{
    int palabra = WORD_SIZE * 3;
    int offset = 0;
    for(offset; offset<8;offset++)
        message->setBit(palabra + offset,false);
}

void FormatConcentrator::removeQEKS()
{
    int palabra = WORD_SIZE * 3;
    int offset = 8;
    for(offset; offset<16;offset++)
        message->setBit(palabra + offset,false);
}

void FormatConcentrator::removeThreat(QString estado)
{

        QJsonObject threat = buttonJson["THREAT_ASSESMENT"].toObject();
        QString threatActual = threat[estado].toString();
        message->setBit(threatActual.toInt(),false);

}

void FormatConcentrator::removeDisplayMode(QString estado)
{
    int palabra = WORD_SIZE * 1; //Está en la segunda palabra
    QJsonObject center = buttonJson["DISPLAY_MODE"].toObject();
    QString centerActual = center[estado].toString();
    message->setBit(palabra+centerActual.toInt(),false);
}
void FormatConcentrator::removeDisplayModeS(QString estado)
{
    int palabra = WORD_SIZE * 1; //Está en la segunda palabra
    QJsonObject center = buttonJson["DISPLAY_MODE"].toObject();
    QString displayModeActual = center[estado].toString();
    message->setBit(palabra+displayModeActual.toInt(),false);
}

void FormatConcentrator::removeDisplaySelection(QString estado)
{
    QJsonObject display = buttonJson["DISPLAY_SELECTION"].toObject();
    QString displayActual = display[estado].toString();
    message->setBit(displayActual.toInt(),false);
    qDebug()<<"Borre el display Selection desde Concentrator de la posicion: "<< displayActual;
}
void FormatConcentrator::removeCenterS(QString estado)
{

}
void FormatConcentrator::removeCenter(QString estado)
{
    int offset = WORD_SIZE * 1;
    QJsonObject center = buttonJson["CENTER"].toObject();
    QString centerActual = center[estado].toString();
    message->setBit(offset + centerActual.toInt(),false);
}

//--------------------------------------------------------------------------//
//*************************************************************************//
//---------------------------Removers--------------------------------------//

void FormatConcentrator::guardarMensaje(IEstado *estado)
{
    static QFile mensajeFile;
    static QTextStream out;
    static QDateTime date;
    static QString formattedTime;
    static QString formattedFile;

    date = QDateTime::currentDateTime();
    formattedTime = date.toString("dd/MM/yyyy hh:mm:ss");
    formattedFile = date.toString("dd_MM_yyyy-hh_mm_ss");

    // Solo calcular la ruta si no ha sido inicializada
    if (mensajeFile.fileName().isEmpty()) {
        QDir dir(QDir::currentPath());
        dir.cdUp();
        dir.cdUp();
        dir.cd("mensajesFC");

        //Se generan nuevos buttonJsons en cada ejecución con la fecha y hora
        QString mensajeFilePath = dir.absolutePath() + "/" + formattedFile + ".log";
        qDebug() << "Format Concentrator: buttonJson de log creado en " +mensajeFilePath;
        mensajeFile.setFileName(mensajeFilePath);

        if (!mensajeFile.open(QIODevice::Append | QIODevice::Text)) {
            qDebug() << "ERROR al abrir el buttonJson de mensajes.";
            return;  // Salir si no se puede abrir el buttonJson
        }

        out.setDevice(&mensajeFile);
    }

    out     << "---------------------- " << formattedTime << " -----------------------";
    out     << "\nRS:\t " << "-" << estado->getRange()              << "-"
            << "\nLS:\t " << "-" << estado->getLabel()              << "-"
            << "\nQE:\t " << "-" << estado->getQEK()                << "-"
            << "\nTA:\t " << "-" << estado->getThreat()             << "-"
            << "\nCE:\t " << "-" << estado->getCenter()             << "-"
            << "\nDM:\t " << "-" << estado->getDisplayMode()        << "-"
            << "\nDS:\t " << "-" << estado->getDisplaySelection()   << "-"
            << "\nIC:\t " << "-" << estado->getICM()                << "-"
            << "\n\n";

    QString bitString;

    // Feo feo pero funciona no se toca más
    for (int i = 0; i < message->size(); ++i) {
        bitString.append(message->testBit(i) ? '1' : '0');
    }

    int segmentLength = 4; // Longitud de cada segmento
    int totalSegments = bitString.size() / segmentLength; // Número total de segmentos

    for (int i = 0; i < totalSegments; ++i) {
        QString segment = bitString.mid(i * segmentLength, segmentLength);
        out << segment << " ";
        if(i % 6 == 5)
            out << "\n";
    }
    out<<"\n\n";
}

void FormatConcentrator::leerJson()
{
    QString JsonFilePath = ":/json/json/properties.json";
    QFile File(JsonFilePath);
    if(File.open(QIODevice::ReadOnly))
    {
        QByteArray Bytes = File.readAll();
        File.close();
        QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes,&JsonError);
        if(JsonError.error != QJsonParseError::NoError){
            qDebug()<<"ERROR in Json Data";
            return;
        }
        if(Document.isObject())
        buttonJson = Document.object();
    }
    else
        qDebug()<<"Hubo un error, no se abrio el buttonJson";


    QString MIKFilePath = ":/json/json/mik.json";
    QFile MIKFile(MIKFilePath);
    if(MIKFile.open(QIODevice::ReadOnly))
    {
        QByteArray Bytes = MIKFile.readAll();
        MIKFile.close();
        QJsonParseError MIKJsonError;
        QJsonDocument MIKDocument = QJsonDocument::fromJson(Bytes,&MIKJsonError);
        if(MIKJsonError.error != QJsonParseError::NoError){
            qDebug()<<"ERROR in Json Data";
            return;
        }
        if(MIKDocument.isObject())
            MIKJson = MIKDocument.object();
    }
    else
        qDebug()<<"Hubo un error, no se abrio el buttonJson";
}

