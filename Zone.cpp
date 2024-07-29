#include "Zone.h"
#include "center.h"
#include "botonera.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

Zone::Zone(Botonera *b, QList<QString> labels, QString style, bool checkable, QBoxLayout *layout)
{
    miBotonera = b;
    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QButtonGroup *group = new QButtonGroup();

    for(int i=1;i<=labels.length();i++){
        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,labels[i-1]);

        gui_button->setCheckable(checkable);
        gui_button->setFlat(true);  //No se si va acá
        group->addButton(gui_button,i);

        layout->addWidget(gui_button);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        if(checkable){
            QObject::connect(gui_button, &QPushButton::toggled, logic_button, &Boton::interact);
        }
        else{
            QObject::connect(gui_button, &QPushButton::pressed, logic_button, &Boton::interact);
            QObject::connect(gui_button, &QPushButton::released, logic_button, &Boton::interact);
        }

        gui_button->setStyleSheet(style);
    }

    this->setLayout(layout);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");
}

void Center::sendMessage(){
    return;
}

void Center::sendCode(QString code){
    miBotonera->sendCodeToEstado(this, &code);
}
void Center::removeCode(QString code){
    miBotonera->removeCodeFromEstado(this, &code);
}


