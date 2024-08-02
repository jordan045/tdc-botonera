#include "botonera.h"
#include "display_selection.h"
#include "overlay_140_0001.h"
#include "overlay_140_0010.h"
#include "overlay_140_0011.h"
#include "overlay_140_0100.h"
#include "zone_range.h"
#include "qmessagebox.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QShortcut>

Botonera::Botonera(QWidget *parent) :
    QWidget(parent)
{
    miEstado = new Estado(this);
    range_widget = new zone_range(this);
    label_selection_widget = new Label(this);
    threat_assesment_widget = new Threat(this);
    center_widget = new Center(this);
    display_mode_widget = new DisplayMode(this);
    icm_widget = new zone_icm(this);
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
    int overlay = getOverlay().toInt();
    qDebug() << overlay;

    switch (overlay) {
    case 1:
        qek_widget = new OVERLAY_140_0001(this);
        break;
    case 10:
        qek_widget = new OVERLAY_140_0010(this);
        break;
    case 11:
        qek_widget = new OVERLAY_140_0011(this);
        break;
    case 100:
        qek_widget = new OVERLAY_140_0100(this);
        break;
    }

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

    this->setLayout(layout);
    this->show();
    //infoMessage();
    shortcut = new QShortcut(QKeySequence(Qt::Key_0), this);
    qDebug()<<shortcut->key();
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(infoMessage()));
}

void Botonera::infoMessage(){
    //qDebug()<< "infoMessage()<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    //QMessageBox::about(this,"SHORTCUTS","Aca va el texto");
    QMessageBox msg;

    msg.setWindowTitle("ATAJOS DE TECLADO");
    QString text = "<table style='border-collapse: collapse;'>"
                   "<tr><td style='text-align: left; padding: 8px;'>WIPE</td><td style='text-align: right; padding: 8px;'>Ctrl+R</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>CLOSE/CONTROL</td><td style='text-align: right; padding: 8px;'>Ctrl+E</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>CORRECT</td><td style='text-align: right; padding: 8px;'>Ctrl+W</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>NEXT TRACK</td><td style='text-align: right; padding: 8px;'>Ctrl+Q</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>Data_Req</td><td style='text-align: right; padding: 8px;'>Ctrl+D</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>Center</td><td style='text-align: right; padding: 8px;'>Ctrl+S</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>Off_Cent</td><td style='text-align: right; padding: 8px;'>Ctrl+A</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 2</td><td style='text-align: right; padding: 8px;'>F2</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 4</td><td style='text-align: right; padding: 8px;'>F3</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 8</td><td style='text-align: right; padding: 8px;'>F4</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 16</td><td style='text-align: right; padding: 8px;'>F5</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 32</td><td style='text-align: right; padding: 8px;'>F6</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 64</td><td style='text-align: right; padding: 8px;'>F7</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 128</td><td style='text-align: right; padding: 8px;'>F8</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>RANGE 256</td><td style='text-align: right; padding: 8px;'>F9</td></tr>"

                   "</table>";
    msg.setText(text);



    //msg.setFixedHeight(400);
    //msg.setFixedWidth(600);
    //msg.setStyleSheet("QLabel{min-width: 400px;}");
    msg.exec();
}

Estado* Botonera::getEstado(){
    return miEstado;
}


