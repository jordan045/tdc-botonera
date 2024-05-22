#include "botonera.h"
#include "display_selection.h"
#include <QVBoxLayout>
#include <QLabel>

botonera::botonera(QWidget *parent) :
    QWidget(parent)
{
    qDebug() << "botonera ready";
    miEstado = new Estado(this);
    range_widget = new range(this);
    label_selection_widget = new label(this);
    qek_widget = new qek(this);
    threat_assesment_widget = new threat(this);
    center_widget = new center(this);
    display_mode_widget = new display_mode(this);
    icm_widget = new icm(this);
    display_selection_widget = new Display_selection(this);
}

void botonera::setmodo(int i)
{
    qDebug() << "botonera modo: "<< i;
    modo = i;
}

void botonera::sendCodeToEstado(center *z, QString *boton)
{
    miEstado->setCenter(boton);
    z->isVisible();
}

void botonera::sendCodeToEstado(display_mode *z, QString *boton)
{
    miEstado->setDisplay(boton);
    z->isVisible();
}

void botonera::sendCodeToEstado(Display_selection *z, QString *boton)
{
    miEstado->setDisplay(boton);
    z->isVisible();
}

void botonera::sendCodeToEstado(icm *z, QString *boton)
{
    miEstado->setICM(boton);
    z->isVisible();
}

void botonera::sendCodeToEstado(label *z, QString *boton)
{
    miEstado->setLabel(boton);
    z->isVisible();
}

void botonera::sendCodeToEstado(qek *z, QString *boton)
{
    miEstado->setQEK(boton);
    z->isVisible();
}

void botonera::sendCodeToEstado(range *z, QString *boton)
{
    miEstado->setRange(boton);
    z->isVisible();
}

void botonera::sendCodeToEstado(threat *z, QString *boton)
{
    miEstado->setThreat(boton);
    z->isVisible();
}

void botonera::iniciar()
{
     qDebug() << "INICIO BOTONERA";
    QHBoxLayout *layout = new QHBoxLayout();

    QVBoxLayout *midLay = new QVBoxLayout();
    midLay->addWidget(range_widget);
    midLay->addWidget(qek_widget);
    midLay->addWidget(threat_assesment_widget);
    midLay->addWidget(display_mode_widget);
    midLay->addWidget(label_selection_widget);
    midLay->addWidget(display_selection_widget);

    layout->addWidget(icm_widget);
    layout->addLayout(midLay);
    layout->addWidget(center_widget);

    //QString texto = QString::number(modo);
    //QLabel *label = new QLabel(texto);

    //layout->addWidget(label,0,3);
    this->setLayout(layout);
    qDebug() << "SHOW BOTONERA";
    this->show();
}

