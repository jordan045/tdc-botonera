#include "threat.h"
#include "botonera.h"
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>

Threat::Threat(Botonera *b)
{
    miBotonera = b;
   //createGraphicsButtons();
   //createLogicButtons();
   //createButtonGroup();
   //connection();
   //createLayout();
   //style();
    QList<QPushButton*>  gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QButtonGroup *threat_group = new QButtonGroup();
    auto layout = new QVBoxLayout;

    QList<QString> labels = {"12_sec",
                             "30_sec",
                             "6_min",
                             "15_min",
                             "reset"};
    for(int i=1; i<=5;i++){
        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,labels[i-1]);

        gui_button->setFlat(true);
        threat_group->addButton(gui_button,i);

        layout->addWidget(gui_button);

        gui_button->setCheckable(true);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        QObject::connect(gui_button, &QPushButton::toggled, logic_button, &Boton::interact);

        QString style = QString("QPushButton {image: url(':/threat/img/Threat/%1.png')}"
                                "QPushButton:checked {image: url(':/threat/img/Threat/%1_pressed.png')}").arg(labels[i-1]);

        gui_button->setStyleSheet(style);

        qDebug()<<"LISTO: " << labels[i-1] << i;
    }

    this->setLayout(layout);
    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}");
    qDebug() << "TERMINO THREAT";
}

void Threat::sendMessage(){
    return;
}

void Threat::sendCode(QString code)
{
    miBotonera->sendCodeToThreat(&code);
}
void Threat::removeCode(QString code){
    miBotonera->removeCodeFromThreat(&code);
}

QString Threat::getName()
{
    return "Threat";
}

