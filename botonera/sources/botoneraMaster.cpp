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
    sendMessage();
}
void BotoneraMaster::removeCodeFromRange(QString boton){
    estadoActual->removeRange(boton);
    sendMessage();
}
void BotoneraMaster::removeCodeFromLabelSelection(QString boton){
    estadoActual->removeLabel(boton);
    concentrator->removeDisplaySelection(boton);
    sendMessage();
}
void BotoneraMaster::removeCodeFromQek(QString boton){
    estadoActual->removeQek(boton);
    concentrator->removeQEK();
    sendMessage();
}
void BotoneraMaster::removeCodeFromThreat(QString boton){
    estadoActual->removeThreat(boton);
    concentrator->removeThreat(boton);
    sendMessage();
}
void BotoneraMaster::removeCodeFromCenter(QString boton){
    estadoActual->removeCenter(boton);
    concentrator->removeCenter(boton);
    sendMessage();
}
void BotoneraMaster::removeCodeFromDisplayMode(QString boton){
    estadoActual->removeDisplayMode(boton);
    concentrator->removeDisplayMode(boton);
    sendMessage();
}
void BotoneraMaster::removeCodeFromDisplaySelection(QString boton){
    estadoActual->removeDisplaySelection(boton);
    concentrator->removeDisplaySelection(boton);
    sendMessage();
}
void BotoneraMaster::removeCodeFromIcm(QString boton){
    estadoActual->removeIcm(boton);
    sendMessage();
}

/* ------------------SETTERS-----------------------*/

void BotoneraMaster::sendCodeToRange(QString boton){
    estadoActual->setRange(boton);
    sendMessage();
}
void BotoneraMaster::sendCodeToLabelSelection(QString boton){
    estadoActual->setLabel(boton);
    sendMessage();
}

void BotoneraMaster::sendCodeToQek(QString boton){
    estadoActual->setQEK(boton);
    sendMessage();
}

void BotoneraMaster::sendCodeToThreat(QString boton){
    estadoActual->setThreat(boton);
    sendMessage();
}

void BotoneraMaster::sendCodeToCenter(QString boton){
    estadoActual->setCenter(boton);
    sendMessage();
}

void BotoneraMaster::sendCodeToDisplayMode(QString boton){
    estadoActual->setDisplayMode(boton);
    sendMessage();
}

void BotoneraMaster::sendCodeToDisplaySelection(QString boton){
    estadoActual->setDisplaySelection(boton);
    sendMessage();
}

void BotoneraMaster::sendCodeToIcm(QString boton){
    estadoActual->setICM(boton);
    sendMessage();
}


void BotoneraMaster::sendMessage(){
    concentrator->getMessage(estadoActual);
}

QString BotoneraMaster::getOverlay(){
    return estadoActual->getOverlay();
}


