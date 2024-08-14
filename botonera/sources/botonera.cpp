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
//---------Removers----------------------------//
void Botonera::setOverlay(QString codigo){
    miEstado->setOverlay(codigo);
    sendMessage();
}
void Botonera::removeCodeFromRange(QString boton){
    miEstado->removeRange(boton);
    sendMessage();
}
void Botonera::removeCodeFromLabelSelection(QString boton){
    miEstado->removeLabel(boton);
    concentrator->removeDisplaySelection(boton);
    sendMessage();
}
void Botonera::removeCodeFromQek(QString boton){
    miEstado->removeQek(boton);
    concentrator->removeQEK();
    sendMessage();
}
void Botonera::removeCodeFromThreat(QString boton){
    miEstado->removeThreat(boton);
    concentrator->removeThreat(boton);
    sendMessage();
}
void Botonera::removeCodeFromCenter(QString boton){
    miEstado->removeCenter(boton);
    concentrator->removeCenter(boton);
    sendMessage();
}
void Botonera::removeCodeFromDisplayMode(QString boton){
    miEstado->removeDisplayMode(boton);
    concentrator->removeDisplayMode(boton);
    sendMessage();
}
void Botonera::removeCodeFromDisplaySelection(QString boton){
    miEstado->removeDisplaySelection(boton);
    concentrator->removeDisplaySelection(boton);
    sendMessage();
}
void Botonera::removeCodeFromIcm(QString boton){
    miEstado->removeIcm(boton);
    sendMessage();
}

//Setters//
void Botonera::sendCodeToRange(QString *boton){
    miEstado->setRange(boton);
}
void Botonera::sendCodeToLabelSelection(QString *boton){
    miEstado->setLabel(boton);
    sendMessage();
}

void Botonera::sendCodeToQek(QString *boton){
    miEstado->setQEK(boton);
    sendMessage();
}

void Botonera::sendCodeToThreat(QString *boton){
    miEstado->setThreat(boton);
    sendMessage();
}

void Botonera::sendCodeToCenter(QString *boton){
    miEstado->setCenter(boton);
    sendMessage();
}

void Botonera::sendCodeToDisplayMode(QString *boton){
    miEstado->setDisplayMode(boton);
    sendMessage();
}

void Botonera::sendCodeToDisplaySelection(QString *boton){
    miEstado->setDisplaySelection(boton);
    sendMessage();
}

void Botonera::sendCodeToIcm(QString *boton){
    miEstado->setICM(boton);
    sendMessage();
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

    help_button->setToolTip("Ayuda");

    // El buddy button no se muestra, es para espaciar correctamente los elementos en el layout
    QPushButton *buddy_button = new QPushButton();
    buddy_button->setFlat(true);

    // Creación de la interfaz de botonera
    QHBoxLayout *top_layout = new QHBoxLayout();
    QVBoxLayout *outer_layout = new QVBoxLayout();
    QHBoxLayout *inner_layout = new QHBoxLayout();
    QVBoxLayout *column_layout = new QVBoxLayout();
    QVBoxLayout *qek_layout = new QVBoxLayout();

    top_layout->addWidget(buddy_button);
    top_layout->addWidget(range_widget);
    top_layout->addWidget(help_button);

    column_layout->addWidget(label_selection_widget);
    column_layout->addWidget(threat_assesment_widget);

    qek_layout->addWidget(display_mode_widget);
    qek_layout->addWidget(qek_widget);
    qek_layout->setAlignment(display_mode_widget,Qt::AlignCenter);
    qek_layout->setAlignment(qek_widget,Qt::AlignCenter);

    inner_layout->addWidget(display_selection_widget);
    inner_layout->addLayout(column_layout);
    inner_layout->addLayout(qek_layout);
    inner_layout->addWidget(icm_widget);
    inner_layout->addWidget(center_widget);

    outer_layout->addLayout(top_layout);
    outer_layout->addLayout(inner_layout);

    this->setLayout(outer_layout);

    shortcut = new QShortcut(QKeySequence(Qt::Key_0), this);

    connect(shortcut, SIGNAL(activated()), this, SLOT(infoMessage()));
    connect(help_button, &QPushButton::clicked, this, &Botonera::infoMessage);

    this->show();
}

void Botonera::infoMessage(){
    // Genera el mensaje de ayuda con los atajos de teclado
    QMessageBox msg;

    msg.setWindowTitle("ATAJOS DE TECLADO");
    QString text = "<table style='border-collapse: collapse;'>"
                   "<tr><td style='text-align: left; padding: 8px;'>WIPE</td><td style='text-align: right; padding: 8px;'>Ctrl+R</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>CLOSE CONTROL</td><td style='text-align: right; padding: 8px;'>Ctrl+E</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>CORRECT</td><td style='text-align: right; padding: 8px;'>Ctrl+W</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>NEXT TRACK</td><td style='text-align: right; padding: 8px;'>Ctrl+Q</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>DATA REQUEST</td><td style='text-align: right; padding: 8px;'>Ctrl+D</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>CENTER</td><td style='text-align: right; padding: 8px;'>Ctrl+S</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>OFF CENTER</td><td style='text-align: right; padding: 8px;'>Ctrl+A</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>2 DM</td><td style='text-align: right; padding: 8px;'>F2</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>4 DM</td><td style='text-align: right; padding: 8px;'>F3</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>8 DM</td><td style='text-align: right; padding: 8px;'>F4</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>16 DM</td><td style='text-align: right; padding: 8px;'>F5</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>32 DM</td><td style='text-align: right; padding: 8px;'>F6</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>64 DM</td><td style='text-align: right; padding: 8px;'>F7</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>128 DM</td><td style='text-align: right; padding: 8px;'>F8</td></tr>"
                   "<tr><td style='text-align: left; padding: 8px;'>256 DM</td><td style='text-align: right; padding: 8px;'>F9</td></tr>"

                   "</table>";
    msg.setText(text);
    msg.exec();
}


