#include "botonera.h"
#include "overlay_140_0001.h"
#include "overlay_140_0010.h"
#include "overlay_140_0011.h"
#include "overlay_140_0100.h"
#include "zone_label.h"
#include "zone_range.h"
#include "zone_displayselection.h"
#include "qmessagebox.h"
#include "zone_threat.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QShortcut>
#include "overlay_360_0001.h"
#include "overlay_360_0010.h"
#include "overlay_360_0011.h"
#include "overlay_360_0100.h"
#include "overlay_360_0101.h"
#include "overlay_360_0110.h"
#include "overlay_360_0111.h"
#include "overlay_360_1000.h"

Botonera::Botonera(QWidget *parent) :
    QWidget(parent)
{
    miEstado = new Estado(this);
    range_widget = new zone_range(this);
    label_selection_widget = new zone_label(this);
    threat_assesment_widget = new zone_threat(this);
    display_mode_widget = new zone_displayMode(this);
    center_widget = new zone_center(this);
    icm_widget = new zone_icm(this);
    display_selection_widget = new zone_displaySelection(this);
    concentrator = new FormatConcentrator();
}

void Botonera::setOverlay(QString codigo){
    miEstado->setOverlay(codigo);
}
void Botonera::setmodo(int i){
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

void Botonera::sendCodeToRange(QString *boton){
    miEstado->setRange(boton);
}
void Botonera::sendCodeToLabelSelection(QString *boton){
    miEstado->setLabel(boton);
}

void Botonera::sendCodeToQek(QString *boton){
    miEstado->setQEK(boton);
}

void Botonera::sendCodeToThreat(QString *boton){
    miEstado->setThreat(boton);
}

void Botonera::sendCodeToCenter(QString *boton){
    miEstado->setCenter(boton);
}

void Botonera::sendCodeToDisplayMode(QString *boton){
    miEstado->setDisplayMode(boton);
}

void Botonera::sendCodeToDisplaySelection(QString *boton){
    miEstado->setDisplaySelection(boton);
}

void Botonera::sendCodeToIcm(QString *boton){
    miEstado->setICM(boton);
}

void Botonera::sendMessage(){
    concentrator->getMessage(miEstado);
}

QString Botonera::getOverlay(){
    return miEstado->getOverlay();
}

void Botonera::start(int tipo)
{
    int overlay = getOverlay().toInt();
    if (tipo == 140){
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
    }
    else if (tipo == 360)
        {
        switch (overlay) {
        case 1:
            qek_widget = new OVERLAY_360_0001(this);
            break;
        case 10:
            qek_widget = new OVERLAY_360_0010(this);
            break;
        case 11:
            qek_widget = new OVERLAY_360_0011(this);
            break;
        case 100:
            qek_widget = new OVERLAY_360_0100(this);
            break;
        case 101:
            qek_widget = new OVERLAY_360_0101(this);
            break;
        case 110:
            qek_widget = new OVERLAY_360_0110(this);
            break;
        case 111:
            qek_widget = new OVERLAY_360_0111(this);
            break;
        case 1000:
            qek_widget = new OVERLAY_360_1000(this);
        }
        }

    QPushButton *help_button = new QPushButton("");
    help_button->setStyleSheet("QPushButton {image: url(':/ayuda/img/Ayuda/ayuda.png'); background-color: rgba(0,0,0,0);}"
                               "QPushButton:pressed {image: url(':/ayuda/img/Ayuda/ayuda_pressed.png'); background-color: rgba(0,0,0,0);}"
                               "QPushButton:hover {background-color: rgba(0,0,0,0);}"
                               "QPushButton {width: 40px; height: 40px;}");

    QPushButton *buddy_button = new QPushButton();
    buddy_button->setFlat(true);

    QHBoxLayout *top_layout = new QHBoxLayout();

    QVBoxLayout *outer_layout = new QVBoxLayout();   
    top_layout->addWidget(buddy_button);
    top_layout->addWidget(range_widget);
    top_layout->addWidget(help_button);
    QHBoxLayout *inner_layout = new QHBoxLayout();
    inner_layout->addWidget(display_selection_widget);
    QVBoxLayout *column_layout = new QVBoxLayout();
    column_layout->addWidget(label_selection_widget);
    column_layout->addWidget(threat_assesment_widget);
    inner_layout->addLayout(column_layout);
    inner_layout->addWidget(qek_widget);
    inner_layout->addWidget(icm_widget);
    inner_layout->addWidget(center_widget);
    outer_layout->addLayout(top_layout);
    outer_layout->addWidget(display_mode_widget);
    outer_layout->addLayout(inner_layout);

    outer_layout->setAlignment(display_mode_widget,Qt::AlignCenter);

    this->setLayout(outer_layout);
    this->show();
    shortcut = new QShortcut(QKeySequence(Qt::Key_0), this);

    connect(shortcut, SIGNAL(activated()), this, SLOT(infoMessage()));
    connect(help_button, &QPushButton::clicked, this, &Botonera::infoMessage);
}

void Botonera::infoMessage(){
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
    msg.exec();
}

Estado* Botonera::getEstado(){
    return miEstado;
}


