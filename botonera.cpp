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
    qek_widget = new Qek(this);
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
    qDebug()<<"SetOverlay en Botonera"<<codigo;
}
void Botonera::setmodo(int i)
{
    modo = i;
}

void Botonera::sendCodeToEstado(Qek *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::sendCodeToEstado(Icm *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::sendCodeToEstado(Center *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::sendCodeToEstado(DisplayMode *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::sendCodeToEstado(DisplaySelection *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::sendCodeToEstado(Label *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::sendCodeToEstado(Range *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::sendCodeToEstado(Threat *z, QString *boton){
    miEstado->setEstado(z,boton);
}
void Botonera::removeCodeFromEstado(Icm *z, QString *boton){
    miEstado->removeEstado(z,boton);
}
void Botonera::removeCodeFromEstado(Qek *z, QString *boton){
    miEstado->removeEstado(z,boton);
}
void Botonera::removeCodeFromEstado(Range *z, QString *boton){
    miEstado->removeEstado(z,boton);
}
void Botonera::removeCodeFromEstado(Center *z, QString *boton){
    miEstado->removeEstado(z,boton);
}
void Botonera::removeCodeFromEstado(DisplayMode *z, QString *boton){
    miEstado->removeEstado(z,boton);
}

void Botonera::removeCodeFromEstado(Threat *z, QString *boton)
{
    miEstado->removeEstado(z,boton);
}


void Botonera::sendMessage()
{
    qDebug()<<"Me tocaron en botonera";
    concentrator->getMessage(miEstado);
}
void Botonera::start()
{
    QHBoxLayout *layout = new QHBoxLayout();

    QVBoxLayout *midLay = new QVBoxLayout();
    //midLay->addWidget(range_widget);
    midLay->addWidget(qek_widget);
    //midLay->addWidget();
    midLay->addWidget(display_mode_widget);
    midLay->addWidget(label_selection_widget);
    midLay->addWidget(center_widget);

    layout->addWidget(range_widget);
    layout->addWidget(icm_widget);
    layout->addLayout(midLay);

    layout->addWidget(display_selection_widget);
    layout->addWidget(threat_assesment_widget);

    //QString texto = QString::number(modo);
    //QLabel *label = new QLabel(texto);

    //layout->addWidget(label,0,3);
    this->setLayout(layout);
    //this->setFixedWidth(900);
    //this->setFixedHeight(600);
    this->showMaximized();
    this->show();
}

