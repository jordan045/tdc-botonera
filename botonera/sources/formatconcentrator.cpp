#include "formatconcentrator.h"
#include "estado.h"
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

QBitArray* FormatConcentrator::getMessage(Estado *estado)
{
    setMessage(estado);
    return message;
}

void FormatConcentrator::setMessage(Estado *estado)
{
    setRange(estado);
    setDisplaySelection(estado);
    setThreat(estado);
    setCenter(estado);
    setDisplayMode(estado);
    setQEK(estado);
    setICM(estado);
    setOverlay(estado);

    //Crear el log si la flag esta activa
    if(LOG)
        guardarMensaje(estado);
}

void FormatConcentrator::setRange(Estado *estado)
{
    QStringList wordListRange = estado->getRange().split(" ", Qt::SkipEmptyParts);

    foreach(const QString &word, wordListRange) {
        QJsonObject rango = archivo["range_scale"].toObject();
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

void FormatConcentrator::setDisplaySelection(Estado *estado)
    {
    QStringList wordListDSelection = estado->getDisplaySelection().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListDSelection){
        QJsonObject display = archivo["display_selection"].toObject();
        QJsonObject displayActual = display[word].toObject();
        QString posicion = displayActual["pos"].toString();
        message->setBit(posicion.toInt(),true);
    }
}

void FormatConcentrator::setThreat(Estado *estado)
{
    QStringList wordListThreat = estado->getThreat().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListThreat)
    {
        QJsonObject threat = archivo["threat_assesment"].toObject();
        QJsonObject threatActual = threat[word].toObject();
        QString posicion = threatActual["pos"].toString();
        message->setBit(posicion.toInt(),true);
    }
}

void FormatConcentrator::setCenter(Estado *estado)
{
    int offset = WORD_SIZE * 1; //Está en la primer palabra
    QStringList wordListCenter = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListCenter)
    {
        QJsonObject center = archivo["center"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString posicion = centerActual["pos"].toString();
        message->setBit(offset + posicion.toInt(),true);
    }
}

void FormatConcentrator::setDisplayMode(Estado *estado)
{
    int offset = WORD_SIZE * 1; //Está en la primer palabra
    int posFinal = 0;
    QStringList wordListDisplayMode = estado->getDisplayMode().split(" ",Qt::SkipEmptyParts);
    foreach(const QString &word, wordListDisplayMode)
    {
        QJsonObject center = archivo["display_mode"].toObject();
        QJsonObject centerActual = center[word].toObject();
        QString posicion = centerActual["pos"].toString();
        posFinal = offset+posicion.toInt();
        message->setBit(posFinal,true);
    }
}

void FormatConcentrator::setQEK(Estado *estado)
{
    int offset = WORD_SIZE * 4; //Está en la cuarta palabra;
    QStringList wordListQek = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
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
    int offset = WORD_SIZE * 4; //Está en la cuarta palabra;
    offset += 23; //Hay que llegar a la pos 119
    QStringList wordListQek = estado->getCenter().split(" ", Qt::SkipEmptyParts);
    foreach(const QString &word,wordListQek)
    {
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

void FormatConcentrator::guardarMensaje(Estado *estado)
{
    static QFile mensajeFile;
    static QTextStream out;
    static QDateTime date;
    static QString formattedTime;
    static QString formattedFile;

    date = QDateTime::currentDateTime();
    formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    formattedFile = date.toString("dd-MM-yyyy_hh-mm-ss");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

    // Solo calcular la ruta si no ha sido inicializada
    if (mensajeFile.fileName().isEmpty()) {
        QDir dir(QDir::currentPath());
        dir.cdUp();
        dir.cdUp();
        dir.cd("mensajesFC");

        //Se generan nuevos archivos en cada ejecución con la fecha y hora
        QString mensajeFilePath = dir.absolutePath() + "/" + formattedFile + ".log";
        qDebug() << "Format Concentrator: Archivo de log creado en " +mensajeFilePath;
        mensajeFile.setFileName(mensajeFilePath);

        if (!mensajeFile.open(QIODevice::Append | QIODevice::Text)) {
            qDebug() << "ERROR al abrir el archivo de mensajes.";
            return;  // Salir si no se puede abrir el archivo
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
        archivo = Document.object();
    }
    else
    {
        qDebug()<<"Hubo un error, no se abrio el archivo";
    }
}


