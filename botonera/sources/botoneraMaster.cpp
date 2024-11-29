#include "botoneraMaster.h"
#include "estado.h"
BotoneraMaster::BotoneraMaster(QWidget *parent): Botonera(parent),botoneraMasterSource(parent)
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

void BotoneraMaster::removeCodeFromCenterSlave(QString boton)
{
    estadoActual->removeCenterS(boton);
    sendMessage();
}

void BotoneraMaster::removeCodeFromMIKSlave(QString caracter)
{
    estadoActual->removeMIK(caracter); //TODO CAMBIAR
    sendMessage();
}

void BotoneraMaster::removeCodeFromIcmSlave(QString boton)
{
    estadoActual->removeICMS(boton);
    sendMessage();
}

void BotoneraMaster::removeCodeFromQekSlave(QString boton)
{
    estadoActual->removeQEKS(boton);
    sendMessage();
}



/* ------------------SETTERS-----------------------*/

void BotoneraMaster::sendCodeToRangeFromSlave(QString boton){
    range_widget->interact(boton);
}

void BotoneraMaster::sendCodeToLabelSelectionFromSlave(QString boton)
{
    label_selection_widget->interact(boton);
}

void BotoneraMaster::sendCodeToThreatFromSlave(QString boton)
{
    threat_assesment_widget->interact(boton);
}

void BotoneraMaster::sendCodeToDisplayModeFromSlave(QString boton)
{
    display_mode_widget->interact(boton);
}

void BotoneraMaster::sendCodeToDisplaySelectionFromSlave(QString boton)
{
    display_selection_widget->interact(boton);
}

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

void BotoneraMaster::sendCodeToCenterSlave(QString boton)
{
    estadoActual->setCenterS(boton);
}

void BotoneraMaster::sendCharToMIKSlave(QString caracter)
{
    estadoActual->setMIK(caracter); //TODO hay que implementar el seMIKS();
}

void BotoneraMaster::sendCodeToIcmSlave(QString boton)
{
    estadoActual->setICMS(boton);
}

void BotoneraMaster::sendCodeToQekSlave(QString boton)
{
    estadoActual->setQEKS(boton);
}

void BotoneraMaster::sendCodeToOverlaySlave(QString codigo)
{
    estadoActual->setOverlayS(codigo);
    sendMessage();
}



void BotoneraMaster::sendCharToMIK(QString c){
    estadoActual->setMIK(c);
}

QString BotoneraMaster::getOverlay(){
    return estadoActual->getOverlay();
}


