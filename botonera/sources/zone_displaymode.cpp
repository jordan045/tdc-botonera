#include "zone_displaymode.h"
#include "ui_zone_displaymode.h"
#include "botonera.h"
#include "boton.h"

zone_displayMode::zone_displayMode(Botonera *b):
    ui(new Ui::zone_displayMode)
{
    ui->setupUi(this);
    miBotonera = b;

    QList<QString> labels = {"HM","RR","OWN_CURS","SYMB_LARGE","TM","EMERG","SYST_ALARM"};

    QList<QPushButton *> gui_buttons = this->findChildren<QPushButton*>();
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    for(int i=1;i<=7;i++){
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


void zone_displayMode::sendCode(QString code){
    miBotonera->sendCodeToDisplayMode(code);
}

void zone_displayMode::removeCode(QString code){
    miBotonera->removeCodeFromDisplayMode(code);
}



QString zone_displayMode::getName(){
    return "DISPLAYSELECTION";
}
zone_displayMode::~zone_displayMode(){
    delete ui;
}

void zone_displayMode::interact(QString boton)
{
    QPushButton *button = this->findChild<QPushButton*>(boton);
    button->toggle();
}
