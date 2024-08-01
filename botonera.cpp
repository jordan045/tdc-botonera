#include "botonera.h"
#include "display_selection.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

Botonera::Botonera(QWidget *parent) :
    QWidget(parent)
{
    miEstado = new Estado(this);
    range_widget = new Range(this);
    label_selection_widget = new Label(this);
    threat_assesment_widget = new Threat(this);
    center_widget = new Center(this);
    display_mode_widget = new DisplayMode(this);
    icm_widget = new Icm(this);
    display_selection_widget = new DisplaySelection(this);
    concentrator = new FormatConcentrator();
}
void Botonera::setOverlay(QString codigo)
{
    miEstado->setOverlay(codigo);
    qek_widget->setOverlay(codigo);
    qDebug()<<"SetOverlay en Botonera"<<codigo;
}
void Botonera::setmodo(int i)
{
    modo = i;
}

void Botonera::removeCodeFromRange(QString *boton){
    miEstado->removeRange(boton);
}
void Botonera::removeCodeFromLabelSelection(QString *boton){
    miEstado->removeLabel(boton);
}
void Botonera::removeCodeFromQek(QString *boton){
    miEstado->removeQek(boton);
}
void Botonera::removeCodeFromThreat(QString *boton){
    miEstado->removeThreat(boton);
}
void Botonera::removeCodeFromCenter(QString *boton){
    miEstado->removeCenter(boton);
}
void Botonera::removeCodeFromDisplayMode(QString *boton){
    miEstado->removeDisplayMode(boton);
}
void Botonera::removeCodeFromDisplaySelection(QString *boton){
    miEstado->removeDisplaySelection(boton);
}
void Botonera::removeCodeFromIcm(QString *boton){
    miEstado->removeIcm(boton);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Botonera::sendCodeToRange(QString *boton)
{
    miEstado->setRange(boton);
}

void Botonera::sendCodeToLabelSelection(QString *boton)
{
    miEstado->setLabel(boton);
}

void Botonera::sendCodeToQek(QString *boton)
{
    miEstado->setQEK(boton);
}

void Botonera::sendCodeToThreat(QString *boton)
{
    miEstado->setThreat(boton);
}

void Botonera::sendCodeToCenter(QString *boton)
{
    miEstado->setCenter(boton);
}

void Botonera::sendCodeToDisplayMode(QString *boton)
{
    miEstado->setDisplayMode(boton);
}

void Botonera::sendCodeToDisplaySelection(QString *boton)
{
    miEstado->setDisplaySelection(boton);
}

void Botonera::sendCodeToIcm(QString *boton)
{
    miEstado->setICM(boton);
}

void Botonera::sendMessage()
{
    qDebug()<<"Me tocaron en botonera";
    concentrator->getMessage(miEstado);
}

QString Botonera::getOverlay(){
    return miEstado->getOverlay();
}

void Botonera::start()
{
    qek_widget = new Qek(this);
    QHBoxLayout *layout = new QHBoxLayout();

    QVBoxLayout *midLay = new QVBoxLayout();
    midLay->addWidget(qek_widget);
    midLay->addWidget(display_mode_widget);
    midLay->addWidget(label_selection_widget);
    midLay->addWidget(center_widget);

    layout->addWidget(range_widget);
    layout->addWidget(icm_widget);
    layout->addLayout(midLay);

    layout->addWidget(display_selection_widget);
    layout->addWidget(threat_assesment_widget);

    // this->setLayout(midLay);
    this->setLayout(layout);

    this->show();
}

Estado* Botonera::getEstado(){
    return miEstado;
}


