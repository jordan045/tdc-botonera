#include "center.h"
#include "botonera.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

Center::Center(Botonera *b)
{
    miBotonera = b;
    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QButtonGroup *center_group = new QButtonGroup();
    auto layout = new QHBoxLayout;

    QList<QString> labels = {"CU_OR_OFF_CENT",
                             "CU_OR_CENT",
                             "OFF_CENT",
                             "CENT",
                             "RESET_OBM",
                             "DATA_REQ"};

    for(int i=1;i<=6;i++){
        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,labels[i-1]);

        gui_button->setCheckable(true);
        gui_button->setFlat(true);  //No se si va acá
        center_group->addButton(gui_button,i);

        layout->addWidget(gui_button);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        QObject::connect(gui_button, &QPushButton::pressed, logic_button, &Boton::interact);
        QObject::connect(gui_button, &QPushButton::released, logic_button, &Boton::interact);

        QString style = QString("QPushButton {image: url(':/center/img/Center/%1.png')}"
                                "QPushButton:pressed {image: url(':/center/img/Center/%1_pressed.png')}").arg(labels[i-1]);

        gui_button->setStyleSheet(style);

        center_group->button(6)->setShortcut(QKeySequence());
        center_group->button(4)->setShortcut(QKeySequence());
        center_group->button(3)->setShortcut(QKeySequence());

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

