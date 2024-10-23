#include "botoneraMaster.h"
#include "estado.h"
BotoneraMaster::BotoneraMaster(QWidget *parent): Botonera(parent)
{
    qDebug()<< "estoy en el contructor de botonera Master";
    concentrator = new FormatConcentrator();
   // estadoActual = new Estado(this);
    range_widget->start();
}


//---------Removers----------------------------//

void BotoneraMaster::setOverlay(QString codigo){
    overlay = codigo.toInt();
    miEstado->setOverlay(codigo);
   // sendMessage();
}
void BotoneraMaster::removeCodeFromRange(QString boton){
    miEstado->removeRange(boton);
   // sendMessage();
}
void BotoneraMaster::removeCodeFromLabelSelection(QString boton){
    miEstado->removeLabel(boton);
    concentrator->removeDisplaySelection(boton);
  //  sendMessage();
}
void BotoneraMaster::removeCodeFromQek(QString boton){
    miEstado->removeQek(boton);
    concentrator->removeQEK();
    //sendMessage();
}
void BotoneraMaster::removeCodeFromThreat(QString boton){
    miEstado->removeThreat(boton);
    concentrator->removeThreat(boton);
    //sendMessage();
}
void BotoneraMaster::removeCodeFromCenter(QString boton){
    miEstado->removeCenter(boton);
    concentrator->removeCenter(boton);
    //senMessage();
}
void BotoneraMaster::removeCodeFromDisplayMode(QString boton){
    miEstado->removeDisplayMode(boton);
    concentrator->removeDisplayMode(boton);
    //senMessage();
}
void BotoneraMaster::removeCodeFromDisplaySelection(QString boton){
    miEstado->removeDisplaySelection(boton);
    concentrator->removeDisplaySelection(boton);
    //sendMessage();
}
void BotoneraMaster::removeCodeFromIcm(QString boton){
    miEstado->removeIcm(boton);
    //sendMessage();
}

/* ------------------SETTERS-----------------------*/

void BotoneraMaster::sendCodeToRange(QString boton){
    miEstado->setRange(boton);
    //sendMessage();
}
void BotoneraMaster::sendCodeToLabelSelection(QString boton){
    miEstado->setLabel(boton);
    //sendMessage();
}

void BotoneraMaster::sendCodeToQek(QString boton){
    miEstado->setQEK(boton);
    //sendMessage();
}

void BotoneraMaster::sendCodeToThreat(QString boton){
    miEstado->setThreat(boton);
    //sendMessage();
}

void BotoneraMaster::sendCodeToCenter(QString boton){
    miEstado->setCenter(boton);
    //sendMessage();
}

void BotoneraMaster::sendCodeToDisplayMode(QString boton){
    miEstado->setDisplayMode(boton);
    //sendMessage();
}

void BotoneraMaster::sendCodeToDisplaySelection(QString boton){
    miEstado->setDisplaySelection(boton);
    //sendMessage();
}

void BotoneraMaster::sendCodeToIcm(QString boton){
    miEstado->setICM(boton);
    //sendMessage();
}


void BotoneraMaster::sendMessage(){
    concentrator->getMessage(miEstado);
}

void BotoneraMaster::sendCharToMIK(QString c){
    miEstado->setMIK(c);
    qDebug()<< "Llamado en sendCharToMik<<" + c;
}

QString BotoneraMaster::getOverlay(){
    return miEstado->getOverlay();
}


