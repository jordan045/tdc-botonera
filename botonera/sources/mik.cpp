#include "mik.h"

MIK::MIK(Botonera *b){
    miBotonera = b;
    tab = 1; //Linea actual

    //QMessageBox::StandardButton reply;
    // Lee el archivo JSON con la información de los overlays
    QFile file(":/json/json/mik.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug("\nERROR al abrir json de MIK\n");
    }

    QByteArray data = file.readAll();
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(data, &jsonError);
    file.close();

    if (jsonError.error != QJsonParseError::NoError) {
        qDebug("Error Error al parsear JSON");
        return;
    }

    // Verificar si el documento es un objeto
    if (!document.isObject()) {
        qWarning("El documento JSON no es un objeto.");
        return;
    }

    QJsonObject rootObj = document.object();
    teclasObj = rootObj["teclas"].toObject();


}

void MIK::selectLine(int t){
    int i= t;

    //Guardar en octal
    while (i != tab) {
        if(tab > 13){
            tab = 0;
        }
        else{
            pressKey("s");
            //releaseKey(' ');
            tab++;
        }
    }
    tab = t;
}

void MIK::pressKey(QString c){
    //QJsonObject caracter = teclasObj[c].toObject();
    //QString toSend = caracter["ASCII_Octal"].toString();
    miBotonera->sendCharToMIK(c);
}

void MIK::releaseKey(QString c){
    //QJsonObject caracter = teclasObj[c].toObject();
    //QString toSend = caracter["ASCII_Octal"].toString();
    //miBotonera->removeCharToMIK(toSend);
}
