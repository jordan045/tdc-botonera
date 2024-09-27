#include "botonera.h"
#include "andGui.h"
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
#include "QFontDatabase"

Botonera::Botonera(QWidget *parent) :
    QWidget(parent)
{
    miEstado = new Estado(this);
    concentrator = new FormatConcentrator();

    range_widget = new zone_range(this);
    label_selection_widget = new zone_label(this);
    threat_assesment_widget = new zone_threat(this);
    display_mode_widget = new zone_displayMode(this);
    center_widget = new zone_center(this);
    icm_widget = new zone_icm(this);
    display_selection_widget = new zone_displaySelection(this);

    alfanumeric_display = new andGui();
    alfanumeric_display->setBotonera(this);
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

void Botonera::removeCharToMIK(QChar c)
{
    miEstado->removeMIK(c);
    sendMessage();
}

//Setters//
void Botonera::sendCodeToRange(QString boton){
    miEstado->setRange(boton);
    sendMessage();
}
void Botonera::sendCodeToLabelSelection(QString boton){
    miEstado->setLabel(boton);
    sendMessage();
}

void Botonera::sendCodeToQek(QString boton){
    miEstado->setQEK(boton);
    sendMessage();
}

void Botonera::sendCodeToThreat(QString boton){
    miEstado->setThreat(boton);
    sendMessage();
}

void Botonera::sendCodeToCenter(QString boton){
    miEstado->setCenter(boton);
    sendMessage();
}

void Botonera::sendCodeToDisplayMode(QString boton){
    miEstado->setDisplayMode(boton);
    sendMessage();
}

void Botonera::sendCodeToDisplaySelection(QString boton){
    miEstado->setDisplaySelection(boton);
    sendMessage();
}

void Botonera::sendCodeToIcm(QString boton){
    miEstado->setICM(boton);
    sendMessage();
}

void Botonera::sendCharToMIK(QChar c){
    miEstado->setMIK(c);
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

    qDebug() << tipo << overlay;

    crearBotonHelp();
    distribucionLayout();

    this->show();
    alfanumeric_display->show();
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

void Botonera::crearBotonHelp()
{

    help_button->setStyleSheet("QPushButton {image: url(':/ayuda/img/Ayuda/ayuda.png');}"
                               "QPushButton:pressed {image: url(':/ayuda/img/Ayuda/ayuda_pressed.png');}"
                               "QPushButton {width: 40px; height: 40px;}");

    help_button->setToolTip("Ayuda");
    help_button->setFlat(true);
    help_button->setMaximumSize(40,40);
    shortcut = new QShortcut(QKeySequence(Qt::Key_0), this);

    connect(shortcut, SIGNAL(activated()), this, SLOT(infoMessage()));
    connect(help_button, &QPushButton::clicked, this, &Botonera::infoMessage);


}

void Botonera::distribucionLayout()
{
    QFontDatabase::addApplicationFont ( ":/fonts/fonts/bahnschrift.TTF" );
    QFont Bahnschrift("Bahnschrift", 9, QFont::Normal);

    // Creación de la interfaz de botonera
    QHBoxLayout *top_layout = new QHBoxLayout();
    QVBoxLayout *outer_layout = new QVBoxLayout();
    QHBoxLayout *inner_layout = new QHBoxLayout();
    QVBoxLayout *column_layout = new QVBoxLayout();
    QVBoxLayout *qek_layout = new QVBoxLayout();
    QHBoxLayout *global_layout = new QHBoxLayout();

    top_layout->addWidget(range_widget,Qt::AlignCenter);

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
    outer_layout->addWidget(help_button);

    global_layout->addLayout(outer_layout);
    //global_layout->addWidget(alfanumeric_display);
    //global_layout->setAlignment(alfanumeric_display, Qt::AlignCenter);

    this->setLayout(global_layout);
    this->setFont(Bahnschrift);

    // QString mensaje = "0101011100110000001100010010000000110001001100100010000001001100010010010100111001001011001000000011000100110100001000000101010001010010010000110100101100100000001100100011001100110000001000000100110000100000001010110011000000110110000010100101010001011000010100110101010000100001001011010000101001000001001000000010000000100000001011010010110100101101001011010010110100000100000001011010010110100101101001011010010110100000100000001011010010110100101101001011010010110100001010010000100010000000100000001000000010110100101101001011010010110100000100000001011010010110100101101001011010010110100000100000001011010010110100101101001011010010110100001010000110010000000100000001000000010110100101101001011010010110100000100000001011010010110100101101001011010010110100000100000001011010010110100101101001011010010110100001010001000100010000000100000001000000010110100101101001011010010110100000100000001011010010110100101101001011010010110100000100000001011010010110100101101001011010010110100001010001010010100001000000101001101010000001000000010000001000000010110100101101001011010010110101001010";
    // alfanumeric_display->recibirMensaje(mensaje);
}


