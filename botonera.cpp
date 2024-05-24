#include "botonera.h"
#include "display_selection.h"
#include <QVBoxLayout>
#include <QLabel>

botonera::botonera(QWidget *parent) :
    QWidget(parent)
{
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
    modo = i;
}

void botonera::sendCodeToEstado(center *z, QString *boton)
{
    QString * mensaje = new QString("center");
    qDebug() << "Center actualizado";
    miEstado->setCenter(boton);
}

void botonera::sendCodeToEstado(display_mode *z, QString *boton)
{
     QString * mensaje = new QString("center");
    qDebug() << "Display mode actualizado";
    miEstado->setDisplay(boton);
}

void botonera::sendCodeToEstado(Display_selection *z, QString *boton)
{
     QString * mensaje = new QString("center");
    qDebug() << "Display selection actualizado";
    miEstado->setDisplay(boton);
}

void botonera::sendCodeToEstado(icm *z, QString *boton)
{
     QString * mensaje = new QString("icm");
    qDebug() << "ICM actualizado";
    miEstado->setICM(boton);

}

void botonera::sendCodeToEstado(label *z, QString *boton)
{
     QString * mensaje = new QString("label");
    qDebug() << "Label selection actualizado";
    miEstado->setLabel(boton);
}

void botonera::sendCodeToEstado(qek *z, QString *boton)
{
     QString * mensaje = new QString("qek");
    qDebug() << "QEK actualizado";
    miEstado->setQEK(boton);
}

void botonera::sendCodeToEstado(range *z, QString *boton)
{
     QString * mensaje = new QString("range");
    qDebug() << "Range actualizado";
    miEstado->setRange(boton);
}

void botonera::sendCodeToEstado(threat *z, QString *boton)
{
     QString * mensaje = new QString("threat");
    qDebug() << "Threat actualizado";
    miEstado->setThreat(boton);
}

void botonera::iniciar()
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

