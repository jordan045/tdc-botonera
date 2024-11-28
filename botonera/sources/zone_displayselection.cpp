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

    qDebug()<<"El codigo displaySelection es:" <<code;
    QPushButton *button = this->findChild<QPushButton*>(code);
    if(button){
        button->setChecked(true);
        qDebug()<<"se activó el boton visual del displaySelection";
    }else
    {
        qDebug()<<"No se encontró el boton del displaySelection";
    }

    miBotonera->sendCodeToDisplaySelection(code);
}

void zone_displaySelection::removeCode(QString code){
    QPushButton *button = this->findChild<QPushButton*>(code);
    if(button){
        button->setChecked(false);
        qDebug()<<"se desactivó el boton visual del displaySelection";
    }else
    {
        qDebug()<<"No se encontró el boton del displaySelection";
    }
    miBotonera->removeCodeFromDisplaySelection(code);
}


QString zone_displaySelection::getName(){
    return "DISPLAYSELECTION";
}

zone_displaySelection::~zone_displaySelection(){
    delete ui;
}
