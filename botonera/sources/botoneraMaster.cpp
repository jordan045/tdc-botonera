#include "botoneraMaster.h"
#include "estado.h"
BotoneraMaster::BotoneraMaster(QWidget *parent): Botonera(parent)
{
    qDebug()<< "estoy en el contructor de botonera Master";
    concentrator = new FormatConcentrator();
    estadoActual = new Estado(this);
    range_widget->start();
}


//---------Removers----------------------------//

void BotoneraMaster::setOverlay(QString codigo){
    overlay = codigo.toInt();
    estadoActual->setOverlay(codigo);
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromRange(QString boton){
    estadoActual->removeRange(boton);
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromLabelSelection(QString boton){
    estadoActual->removeLabel(boton);
    concentrator->removeDisplaySelection(boton);
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromQek(QString boton){
    estadoActual->removeQek(boton);
    concentrator->removeQEK();
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromThreat(QString boton){
    estadoActual->removeThreat(boton);
    concentrator->removeThreat(boton);
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromCenter(QString boton){
    estadoActual->removeCenter(boton);
    concentrator->removeCenter(boton);
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromDisplayMode(QString boton){
    estadoActual->removeDisplayMode(boton);
    concentrator->removeDisplayMode(boton);
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromDisplaySelection(QString boton){
    estadoActual->removeDisplaySelection(boton);
    concentrator->removeDisplaySelection(boton);
    //getConcentrator();
}
void BotoneraMaster::removeCodeFromIcm(QString boton){
    estadoActual->removeIcm(boton);
    //getConcentrator();
}

/* ------------------SETTERS-----------------------*/

void BotoneraMaster::sendCodeToRange(QString boton){
    estadoActual->setRange(boton);
    //getConcentrator();
}
void BotoneraMaster::sendCodeToLabelSelection(QString boton){
    estadoActual->setLabel(boton);
    //getConcentrator();
}

void BotoneraMaster::sendCodeToQek(QString boton){
    estadoActual->setQEK(boton);
    //getConcentrator();
}

void BotoneraMaster::sendCodeToThreat(QString boton){
    estadoActual->setThreat(boton);
    //getConcentrator();
}

void BotoneraMaster::sendCodeToCenter(QString boton){
    estadoActual->setCenter(boton);
    //getConcentrator();
}

void BotoneraMaster::sendCodeToDisplayMode(QString boton){
    estadoActual->setDisplayMode(boton);
    //getConcentrator();
}

void BotoneraMaster::sendCodeToDisplaySelection(QString boton){
    estadoActual->setDisplaySelection(boton);
    //getConcentrator();
}

void BotoneraMaster::sendCodeToIcm(QString boton){
    estadoActual->setICM(boton);
    //getConcentrator();
}


QByteArray BotoneraMaster::getConcentrator(){
    QByteArray DCLCONC = concentrator->getMessage(estadoActual);
    return DCLCONC;
}

void Botonera::sendCharToMIK(QString c){
    miEstado->setMIK(c);
}

QString BotoneraMaster::getOverlay(){
    return estadoActual->getOverlay();
}


