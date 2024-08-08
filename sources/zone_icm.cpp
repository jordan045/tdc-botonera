#include "zone_icm.h"
#include "boton.h"
#include "ui_zone_icm.h"
#include "botonera.h"

zone_icm::zone_icm(Botonera *b)
    : ui(new Ui::zone_icm)
{
    ui->setupUi(this);
    miBotonera = b;
    QList<QPushButton *> gui_buttons = this->findChildren<QPushButton*>();
    QList<Boton*> logic_buttons = *new QList<Boton*>;

    for(int i=1;i<=7;i++){

        QString code = *new QString("ICM ");
        code.append(QString::number(i));

        auto *logic_button = new Boton(this,code);

        logic_buttons.append(logic_button);

        QObject::connect(gui_buttons[i-1], &QPushButton::toggled, logic_button, &Boton::interact);
    }
}

void zone_icm::sendMessage(){
     miBotonera->sendMessage();
}

QString zone_icm::getName()
{
    return "ICM";
}

void zone_icm::sendCode(QString code)
{
    miBotonera->sendCodeToIcm(&code);
}
void zone_icm::removeCode(QString code){
    miBotonera->removeCodeFromIcm(&code);
}

zone_icm::~zone_icm()
{
    delete ui;
}

void zone_icm::on_ICM_1_toggled(bool checked)
{
    if(checked){
        ui->ICM_2->setChecked(false);
        ui->ICM_3->setChecked(false);
        ui->ICM_4->setChecked(false);
        ui->ICM_5->setChecked(false);
        ui->ICM_6->setChecked(false);
        ui->ICM_7->setChecked(false);
    }
}



void zone_icm::on_ICM_2_toggled(bool checked)
{
    if(checked){
        ui->ICM_1->setChecked(false);
        ui->ICM_3->setChecked(false);
        ui->ICM_4->setChecked(false);
        ui->ICM_5->setChecked(false);
        ui->ICM_6->setChecked(false);
        ui->ICM_7->setChecked(false);
    }
}


void zone_icm::on_ICM_3_toggled(bool checked)
{
    if(checked){
        ui->ICM_1->setChecked(false);
        ui->ICM_2->setChecked(false);
        ui->ICM_4->setChecked(false);
        ui->ICM_5->setChecked(false);
        ui->ICM_6->setChecked(false);
        ui->ICM_7->setChecked(false);
    }
}


void zone_icm::on_ICM_4_toggled(bool checked)
{
    if(checked){
        ui->ICM_1->setChecked(false);
        ui->ICM_2->setChecked(false);
        ui->ICM_3->setChecked(false);
        ui->ICM_5->setChecked(false);
        ui->ICM_6->setChecked(false);
        ui->ICM_7->setChecked(false);
    }
}


void zone_icm::on_ICM_5_toggled(bool checked)
{
    if(checked){
        ui->ICM_1->setChecked(false);
        ui->ICM_2->setChecked(false);
        ui->ICM_3->setChecked(false);
        ui->ICM_4->setChecked(false);
        ui->ICM_6->setChecked(false);
        ui->ICM_7->setChecked(false);
    }
}


void zone_icm::on_ICM_6_toggled(bool checked)
{
    if(checked){
        ui->ICM_1->setChecked(false);
        ui->ICM_2->setChecked(false);
        ui->ICM_3->setChecked(false);
        ui->ICM_4->setChecked(false);
        ui->ICM_5->setChecked(false);
        ui->ICM_7->setChecked(false);
    }
}


void zone_icm::on_ICM_7_toggled(bool checked)
{
    if(checked){
        ui->ICM_1->setChecked(false);
        ui->ICM_2->setChecked(false);
        ui->ICM_3->setChecked(false);
        ui->ICM_4->setChecked(false);
        ui->ICM_5->setChecked(false);
        ui->ICM_6->setChecked(false);
    }
}

