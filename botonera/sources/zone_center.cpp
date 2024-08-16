#include "zone_center.h"
#include "boton.h"
#include "ui_zone_center.h"
#include "botonera.h"

zone_center::zone_center(Botonera *b)
    :ui(new Ui::zone_center)
{
    ui->setupUi(this);
    miBotonera = b;
    QList<QPushButton*> gui_buttons = this->findChildren<QPushButton*>();
    QList<Boton*> logic_buttons = *new QList<Boton*>;

    QList<QString> labels = {"CU_OR_OFF_CENT","CU_OR_CENT","OFF_CENT","CENT","RESET_OBM","DATA_REQ"};

    for(int i=1;i<=6;i++){
        auto *logic_button = new Boton(this,labels[i-1]);
        logic_buttons.append(logic_button);
        QObject::connect(gui_buttons[i-1], &QPushButton::pressed, logic_button, &Boton::interact);
        QObject::connect(gui_buttons[i-1], &QPushButton::released, logic_button, &Boton::interact);
        gui_buttons[i-1]->setStyleSheet(gui_buttons[i-1]->styleSheet() + "QPushButton {"
                                                                             "    border: none;"  // Quita el borde
                                                                             "}"
                                                                             "QPushButton:pressed {"
                                                                             "    border: none;"  // Mantén el borde oculto al presionar
                                                                             "}");
    }
}

zone_center::~zone_center(){
    delete ui;
}

void zone_center::sendCode(QString code){
    miBotonera->sendCodeToCenter(code);
}

void zone_center::removeCode(QString code){
    miBotonera->removeCodeFromCenter(code);
}



QString zone_center::getName(){
    return "CENTER";
}
