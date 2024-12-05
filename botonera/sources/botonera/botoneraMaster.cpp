#include "botoneraMaster.h"
#include "estado.h"
BotoneraMaster::BotoneraMaster(QWidget *parent): Botonera(parent),botoneraMasterSource(parent)
{
    concentrator = new FormatConcentrator();
    estadoActual = new Estado(this);
    range_widget->start();
}


//---------Removers----------------------------//

void BotoneraMaster::setOverlay(QString codigo){
    overlay = codigo.toInt();
    estadoActual->setOverlay(codigo);
}
void BotoneraMaster::removeCodeFromRange(QString boton){
    estadoActual->removeRange(boton);
}
void BotoneraMaster::removeCodeFromLabelSelection(QString boton){
    estadoActual->removeLabel(boton);
    concentrator->removeDisplaySelection(boton);
}
void BotoneraMaster::removeCodeFromQek(QString boton){
    estadoActual->removeQek(boton);
    concentrator->removeQEK();
}
void BotoneraMaster::removeCodeFromThreat(QString boton){
    estadoActual->removeThreat(boton);
    concentrator->removeThreat(boton);
}
void BotoneraMaster::removeCodeFromCenter(QString boton){
    estadoActual->removeCenter(boton);
    concentrator->removeCenter(boton);
}
void BotoneraMaster::removeCodeFromDisplayMode(QString boton){
    estadoActual->removeDisplayMode(boton);
    concentrator->removeDisplayMode(boton);
}
void BotoneraMaster::removeCodeFromDisplaySelection(QString boton){
    estadoActual->removeDisplaySelection(boton);
    concentrator->removeDisplaySelection(boton);
}
void BotoneraMaster::removeCodeFromIcm(QString boton){
    estadoActual->removeIcm(boton);
}

void BotoneraMaster::removeCodeFromCenterSlave(QString boton)
{
    estadoActual->removeCenterS(boton);
}

void BotoneraMaster::removeCodeFromMIKSlave(QString caracter)
{
    estadoActual->removeMIK(caracter); //TODO CAMBIAR
}

void BotoneraMaster::removeCodeFromIcmSlave(QString boton)
{
    estadoActual->removeICMS(boton);
}

void BotoneraMaster::removeCodeFromQekSlave(QString boton)
{
    estadoActual->removeQEKS(boton);
}



/* ------------------SETTERS-----------------------*/

void BotoneraMaster::sendCodeToRangeFromSlave(QString boton){
    range_widget->interactVisual(boton);
    estadoActual->setRange(boton);
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

    emit changeRangeSlave(boton);
    qDebug()<<"botoneraMaster::sendCodeToRange emiti señal a botonera slave";
}
void BotoneraMaster::sendCodeToLabelSelection(QString boton){
    estadoActual->setLabel(boton);
}

void BotoneraMaster::sendCodeToQek(QString boton){
    estadoActual->setQEK(boton);
}

void BotoneraMaster::sendCodeToThreat(QString boton){
    estadoActual->setThreat(boton);
}

void BotoneraMaster::sendCodeToCenter(QString boton){
    estadoActual->setCenter(boton);
}

void BotoneraMaster::sendCodeToDisplayMode(QString boton){
    estadoActual->setDisplayMode(boton);
}

void BotoneraMaster::sendCodeToDisplaySelection(QString boton){
    estadoActual->setDisplaySelection(boton);
}

void BotoneraMaster::sendCodeToIcm(QString boton){
    estadoActual->setICM(boton);
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
}


void BotoneraMaster::sendCharToMIK(QString c){
    estadoActual->setMIK(c);
}


QString BotoneraMaster::getOverlay(){
    return estadoActual->getOverlay();
}


