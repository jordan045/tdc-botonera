#include "zone_threat.h"
#include "botonera.h"
#include "ui_zone_threat.h"
#include "boton.h"

zone_threat::zone_threat(Botonera *b)
    : ui(new Ui::zone_threat)
{
    ui->setupUi(this);
    miBotonera = b;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QList<QPushButton*> gui_buttons = this->findChildren<QPushButton*>();

    QList<QString> labels = {"12_sec","30_sec","6_min","15_min","reset"};

    for(int i=1; i<=5;i++){
        auto *logic_button = new Boton(this,labels[i-1]);
        logic_buttons.append(logic_button);
        QObject::connect(gui_buttons[i-1], &QPushButton::toggled, logic_button, &Boton::interact);
        gui_buttons[i-1]->setStyleSheet(gui_buttons[i-1]->styleSheet() + "QPushButton {"
                                                                             "    border: none;"  // Quita el borde
                                                                             "}"
                                                                             "QPushButton:pressed {"
                                                                             "    border: none;"  // Mantén el borde oculto al presionar
                                                                             "}");
    }

}

void zone_threat::sendCode(QString code)
{
    miBotonera->sendCodeToThreat(code);
}

void zone_threat::removeCode(QString code)
{
    miBotonera->removeCodeFromThreat(code);
}

QString zone_threat::getName(){
    return "THREAT";
}

zone_threat::~zone_threat(){
    delete ui;
}

void zone_threat::on_THREAT_MIN_toggled(bool checked){
    if (checked){
        ui->THREAT_12SEC->setChecked(false);
        ui->THREAT_30SEC->setChecked(false);
        ui->THREAT_6MIN->setChecked(false);
    }
}

void zone_threat::on_THREAT_6MIN_toggled(bool checked){
    if (checked){
        ui->THREAT_12SEC->setChecked(false);
        ui->THREAT_30SEC->setChecked(false);
        ui->THREAT_MIN->setChecked(false);
    }
}


void zone_threat::on_THREAT_30SEC_toggled(bool checked){
    if (checked){
        ui->THREAT_12SEC->setChecked(false);
        ui->THREAT_MIN->setChecked(false);
        ui->THREAT_6MIN->setChecked(false);
    }
}


void zone_threat::on_THREAT_12SEC_toggled(bool checked){
    if (checked){
        ui->THREAT_MIN->setChecked(false);
        ui->THREAT_30SEC->setChecked(false);
        ui->THREAT_6MIN->setChecked(false);
    }
}

