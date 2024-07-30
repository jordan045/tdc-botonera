#include "icm.h"
#include "botonera.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

Icm::Icm(Botonera *b)
{

    miBotonera = b;
    QButtonGroup *icm_group = new QButtonGroup();


    auto layout = new QVBoxLayout;

    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    for(int i=1;i<=7;i++){
        QString code = *new QString("ICM ");
        code.append(QString::number(i));

        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,code);

        gui_button->setCheckable(true);
        gui_button->setFlat(true);
        icm_group->addButton(gui_button,i);

        layout->addWidget(gui_button);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        QObject::connect(gui_button, &QPushButton::toggled, logic_button, &Boton::interact);

        QString style = QString("QPushButton {image: url(':/icm/img/ICM/%1.png')}"
                                "QPushButton:checked {image: url(':/icm/img/ICM/%1_pressed.png')}").arg(i);

        gui_button->setStyleSheet(style);
    }

    this->setLayout(layout);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");

}
void Icm::sendMessage(){
    return;
}

QString Icm::getName()
{
    return "ICM";
}

void Icm::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}
void Icm::removeCode(QString code){
    miBotonera->removeCodeFromEstado(this, &code);
}
