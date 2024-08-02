#include "zone_icm.h"
#include "boton.h"
#include "ui_zone_icm.h"
#include "botonera.h"

zone_icm::zone_icm(Botonera *b)
    : ui(new Ui::zone_icm)
{
    ui->setupUi(this);
    miBotonera = b;
    QList<QPushButton *> gui_buttons = this->findChildren<QPushButton *>();
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
    return;
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
