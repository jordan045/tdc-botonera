#include "botonera.h"
#include "display_selection.h"
#include <QVBoxLayout>
#include <QLabel>

Botonera::Botonera(QWidget *parent) :
    QWidget(parent)
{
    miEstado = new Estado(this);
    range_widget = new Range(this);
    label_selection_widget = new Label(this);
    qek_widget = new Qek(this);
    threat_assesment_widget = new Threat(this);
    center_widget = new Center(this);
    display_mode_widget = new DisplayMode(this);
    icm_widget = new Icm(this);
    display_selection_widget = new DisplaySelection(this);
}

void Botonera::setmodo(int i)
{
    modo = i;
}

void Botonera::sendCodeToEstado(Center *z, QString *boton)
{
    miEstado->setCenter(boton);
}

void Botonera::sendCodeToEstado(DisplayMode *z, QString *boton)
{
    miEstado->setDisplay(boton);
}

void Botonera::sendCodeToEstado(DisplaySelection *z, QString *boton)
{
    miEstado->setDisplay(boton);
}

void Botonera::sendCodeToEstado(Icm *z, QString *boton)
{
    miEstado->setICM(boton);
}

void Botonera::sendCodeToEstado(Label *z, QString *boton)
{
    miEstado->setLabel(boton);
}

void Botonera::sendCodeToEstado(Qek *z, QString *boton)
{
    miEstado->setQEK(boton);
}

void Botonera::sendCodeToEstado(Range *z, QString *boton)
{
    miEstado->setRange(boton);
}

void Botonera::sendCodeToEstado(Threat *z, QString *boton)
{
    miEstado->setThreat(boton);
}

void Botonera::start()
{
    QHBoxLayout *layout = new QHBoxLayout();

    QVBoxLayout *midLay = new QVBoxLayout();
    midLay->addWidget(range_widget);
    midLay->addWidget(qek_widget);
    midLay->addWidget(threat_assesment_widget);
    midLay->addWidget(display_mode_widget);
    midLay->addWidget(label_selection_widget);
    midLay->addWidget(center_widget);

    layout->addWidget(range_widget);
    layout->addWidget(icm_widget);
    layout->addLayout(midLay);

    layout->addWidget(display_selection_widget);

    //QString texto = QString::number(modo);
    //QLabel *label = new QLabel(texto);

    //layout->addWidget(label,0,3);
    this->setLayout(layout);
    this->setFixedWidth(900);
    this->setFixedHeight(600);
    this->show();
}

