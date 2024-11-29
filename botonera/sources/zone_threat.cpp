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

    QList<QString> labels = {"12_SEC","30_SEC","6_MIN","15_MIN","RESET"};

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
    QString codigo = "THREAT_";
    codigo.append(code);
    qDebug()<<"El codigo threatAssesment es:" <<codigo;
    QPushButton *button = this->findChild<QPushButton*>(codigo);
    if(button){
        button->setChecked(true);
        qDebug()<<"se activó el boton visual del displaySelection";
    }else
    {
        qDebug()<<"No se encontró el boton del displaySelection";
    }
    miBotonera->sendCodeToThreat(code);
}

void zone_threat::removeCode(QString code)
{
    QString codigo = "THREAT_";
    codigo.append(code);
    qDebug()<<"El codigo threatAssesment es:" <<codigo;
    QPushButton *button = this->findChild<QPushButton*>(codigo);
    if(button){
        button->setChecked(false);
        qDebug()<<"se activó el boton visual del displaySelection";
    }else
    {
        qDebug()<<"No se encontró el boton del displaySelection";
    }
    miBotonera->sendCodeToThreat(code);

    miBotonera->removeCodeFromThreat(code);
}

QString zone_threat::getName(){
    return "THREAT";
}

void zone_threat::interact(QString boton)
{
    QString codigo = "THREAT_";
    codigo.append(boton);
    qDebug()<<"El codigo threatAssesment es:" <<codigo;
    QPushButton *button = this->findChild<QPushButton*>(codigo);
    button->toggle();
}

zone_threat::~zone_threat(){
    delete ui;
}

void zone_threat::on_THREAT_4_15MIN_toggled(bool checked){
    if (checked){
        ui->THREAT_12_SEC->setChecked(false);
        ui->THREAT_30_SEC->setChecked(false);
        ui->THREAT_6_MIN->setChecked(false);
        ui->THREAT_RESET->setChecked(false);
    }
}

void zone_threat::on_THREAT_3_6MIN_toggled(bool checked){
    if (checked){
        ui->THREAT_12_SEC->setChecked(false);
        ui->THREAT_30_SEC->setChecked(false);
        ui->THREAT_15_MIN->setChecked(false);
        ui->THREAT_RESET->setChecked(false);
    }
}


void zone_threat::on_THREAT_2_30SEC_toggled(bool checked){
    if (checked){
        ui->THREAT_12_SEC->setChecked(false);
        ui->THREAT_15_MIN->setChecked(false);
        ui->THREAT_6_MIN->setChecked(false);
        ui->THREAT_RESET->setChecked(false);
    }
}


void zone_threat::on_THREAT_1_12SEC_toggled(bool checked){
    if (checked){
        ui->THREAT_15_MIN->setChecked(false);
        ui->THREAT_30_SEC->setChecked(false);
        ui->THREAT_6_MIN->setChecked(false);
        ui->THREAT_RESET->setChecked(false);
    }
}


void zone_threat::on_THREAT_5_RESET_toggled(bool checked)
{
    if (checked){
        ui->THREAT_12_SEC->setChecked(false);
        ui->THREAT_15_MIN->setChecked(false);
        ui->THREAT_30_SEC->setChecked(false);
        ui->THREAT_6_MIN->setChecked(false);
    }
}

