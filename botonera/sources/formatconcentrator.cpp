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

QBitArray* FormatConcentrator::getMessage(IEstado *estado)
{
    setMessage(estado);
    return message;
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
        QJsonObject rangoActual = rango[word].toObject();
        QString palabraRango = rangoActual["value"].toString();

        // Inicializa un índice para establecer los bits
        int i = 23;
        for(QChar caracter : palabraRango) {
            if(caracter == '1') {
                message->setBit(i, true);
            } else {
                message->setBit(i, false);
            }
            i--;
        }
    }
}

//FUNCIONA
void FormatConcentrator::setDisplaySelection(IEstado *estado)
{
    QStringList wordListDSelection = estado->getDisplaySelection().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListDSelection){
        QJsonObject display = buttonJson["DISPLAY_SELECTION"].toObject();
        QJsonObject displayActual = display[word].toObject();
        QString posicion = displayActual["pos"].toString();
        qDebug()<< posicion;
        message->setBit(posicion.toInt()-1,true);
    }
}

void FormatConcentrator::setThreat(IEstado *estado)
{
    QStringList wordListThreat = estado->getThreat().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListThreat)
    {
        QJsonObject threat = buttonJson["THREAT_ASSESMENT"].toObject();
        QJsonObject threatActual = threat[word].toObject();
        QString posicion = threatActual["pos"].toString();
        message->setBit(posicion.toInt(),true);
    }
}

void FormatConcentrator::setCenter(IEstado *estado)
{
    int offset = WORD_SIZE * 1; //Está en la primer palabra
    QStringList wordListCenter = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListCenter)
    {
        QJsonObject center = buttonJson["CENTER"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString posicion = centerActual["pos"].toString();
        message->setBit(offset + posicion.toInt(),true);
    }
}

void FormatConcentrator::setDisplayMode(IEstado *estado)
{
    int offset = WORD_SIZE * 1; //Está en la primer palabra
    int posFinal = 0;
    QStringList wordListDisplayMode = estado->getDisplayMode().split(" ",Qt::SkipEmptyParts);
    foreach(const QString &word, wordListDisplayMode)
    {
        QJsonObject displayMode = buttonJson["DISPLAY_MODE"].toObject();
        QJsonObject displayModeActual = displayMode[word].toObject();
        QString posicion = displayModeActual["pos"].toString();
        posFinal = offset+posicion.toInt();
        if(posFinal != 0)
            message->setBit(posFinal,true);
    }
}

void FormatConcentrator::setQEK(IEstado *estado)
{
    int offset = WORD_SIZE * 4; //Está en la cuarta palabra;
    QStringList wordListQek = estado->getQEK().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
        QJsonObject qek = buttonJson["QEK"].toObject();
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

void FormatConcentrator::removeQEK()
{
    int offset = WORD_SIZE * 4;
    for(int i = offset-1;i>WORD_SIZE*3;i--)
        message->setBit(i,false);
}

void FormatConcentrator::setICM(IEstado *estado){
    int offset = WORD_SIZE * 4; //Está en la cuarta palabra;
    offset += 23; //Hay que llegar a la pos 119
    QStringList wordListICM = estado->getICM().split(" ", Qt::SkipEmptyParts);
    qDebug()<<offset;
    if(wordListICM.size() == 0)
    {
        for(int i = offset; i>116; i--)
            message->setBit(i,true);
    }
    foreach(const QString &word,wordListICM)
    {
        QJsonObject ICM = buttonJson["ICM"].toObject();
        QJsonObject ICMActual = ICM[word].toObject();
        QString posicion = ICMActual["value"].toString();
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

void FormatConcentrator::setOverlay(IEstado *estado){

    int offset = (WORD_SIZE * 4) + 19; //115
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

void FormatConcentrator::setMIK(IEstado *estado)
{
    int palabra = WORD_SIZE * 2;
    int offset = 0;
    QString mikPalabra = estado->getMIK();
    QJsonObject teclasMik = MIKJson["teclas"].toObject();
    QJsonObject mikBinario = teclasMik[mikPalabra].toObject();
    QString mik = mikBinario["ASCII_Binario"].toString();
    for (QChar caracter:mik) {
        if(caracter == '1'){
            message->setBit(palabra+offset,true);
        } else {
            message->setBit(palabra+offset,false);
        }
        offset++;
    }
}



void FormatConcentrator::removeThreat(QString estado)
{

        QJsonObject threat = buttonJson["THREAT_ASSESMENT"].toObject();
        QJsonObject threatActual = threat[estado].toObject();
        QString posicion = threatActual["pos"].toString();
        message->setBit(posicion.toInt(),false);

}

void FormatConcentrator::removeDisplayMode(QString estado)
{
    int offset = WORD_SIZE * 1; //Está en la primer palabra
    int posFinal = 0;
    QJsonObject center = buttonJson["DISPLAY_MODE"].toObject();
    QJsonObject centerActual = center[estado].toObject();
    QString posicion = centerActual["pos"].toString();
    posFinal = offset+posicion.toInt();
    message->setBit(posFinal,false);
}

void FormatConcentrator::removeDisplaySelection(QString estado)
{

        QJsonObject display = buttonJson["DISPLAY_SELECTION"].toObject();
        QJsonObject displayActual = display[estado].toObject();
        QString posicion = displayActual["pos"].toString();
        message->setBit(posicion.toInt()-1,false);

}

void FormatConcentrator::removeCenter(QString estado)
{
    int offset = WORD_SIZE * 1;
    QJsonObject center = buttonJson["CENTER"].toObject();
    QJsonObject centerActual = center[estado].toObject();
    QString posicion = centerActual["pos"].toString();
    message->setBit(offset + posicion.toInt(),false);
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
            << "\nMI:\t " << "-" << estado->getMIK()                << "-"
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
