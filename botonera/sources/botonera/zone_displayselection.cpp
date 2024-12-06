#include "zone_displayselection.h"
#include "ui_zone_displayselection.h"
#include "botonera.h"
#include "boton.h"

zone_displaySelection::zone_displaySelection(Botonera *b)
    : ui (new Ui::zone_displaySelection)
{
    ui->setupUi(this);
    miBotonera = b;

    QList<QString> labels = {"AIR","SURF","SUB_SURF","REF_POS","BEAR_SEL","LINK_SEL","WARF_SEL","FIG"};

    QList<QPushButton *> gui_buttons = this->findChildren<QPushButton*>();
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    for(int i=1;i<=8;i++){
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


void zone_displaySelection::sendCode(QString code){


    miBotonera->sendCodeToDisplaySelection(code);
}

void zone_displaySelection::removeCode(QString code){
    QPushButton *button = this->findChild<QPushButton*>(code);
    miBotonera->removeCodeFromDisplaySelection(code);
}


QString zone_displaySelection::getName(){
    return "DISPLAYSELECTION";
}

zone_displaySelection::~zone_displaySelection(){
    delete ui;
}

void zone_displaySelection::interact(QString boton)
{
    QPushButton *button = this->findChild<QPushButton*>(boton);
    button->toggle();
}

void zone_displaySelection::interactVisual(QString boton)
{
    QPushButton* button = this-> findChild<QPushButton*>(boton);
    qDebug()<<"zone_range::interactVisual";
    blockAllButtonSignals(true);
    button->toggle();
    blockAllButtonSignals(false);

}



void zone_displaySelection::blockAllButtonSignals(bool block)
{
    const QList<QPushButton*> &buttons = this->findChildren<QPushButton*>();
    for(QPushButton * button:buttons){
        if(button){
            button->blockSignals(block);
        }
    }
}

