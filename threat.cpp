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
/*
void Threat::createGraphicsButtons()
{
    btn12Sec = new QPushButton("",this);
    btn30Sec = new QPushButton("",this);
    btn6Min = new QPushButton("",this);
    btn15Min = new QPushButton("",this);
    btnReset = new QPushButton("",this);
}

void Threat::createLogicButtons()
{
    logicBtn12Sec  = new Boton(this, "12SEC");
    logicBtn30Sec  = new Boton(this, "30SEC");
    logicBtn6Min   = new Boton(this, "6MIN");
    logicBtn15Min  = new Boton(this, "15MIN");
    logicBtnReset   = new Boton(this, "RESET");
}

void Threat::createButtonGroup()
{
    threatGroup = new QButtonGroup();

    threatGroup->addButton(btn12Sec,1);
    threatGroup->addButton(btn30Sec,2);
    threatGroup->addButton(btn6Min,3);
    threatGroup->addButton(btn15Min,4);
    threatGroup->addButton(btnReset,5);

    btn12Sec->setCheckable(true);
    btn30Sec->setCheckable(true);
    btn6Min->setCheckable(true);
    btn15Min->setCheckable(true);
    btnReset->setCheckable(true);
}

void Threat::connection()
{
    QObject::connect(btn12Sec,&QPushButton::toggled,logicBtn12Sec,&Boton::interact);
    QObject::connect(btn30Sec,&QPushButton::toggled,logicBtn30Sec,&Boton::interact);
    QObject::connect(btn6Min,&QPushButton::toggled,logicBtn6Min,&Boton::interact);
    QObject::connect(btn15Min,&QPushButton::toggled,logicBtn15Min,&Boton::interact);
    QObject::connect(btnReset,&QPushButton::toggled,logicBtnReset,&Boton::interact);
}

void Threat::createLayout()
{
    auto layout = new QHBoxLayout;
    layout->addWidget(btn12Sec);
    layout->addWidget(btn30Sec);
    layout->addWidget(btn6Min);
    layout->addWidget(btn15Min);
    layout->addWidget(btnReset);
    this->setLayout(layout);
}

void Threat::style()
{
    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");

    btn12Sec->setStyleSheet("QPushButton {image: url(':/threat/img/Threat/12_sec.png')}"
                            "QPushButton:checked {image: url(':/threat/img/Threat/12_sec_pressed.png')}");

    btn30Sec->setStyleSheet("QPushButton {image: url(':/threat/img/Threat/30_sec.png')}"
                            "QPushButton:checked {image: url(':/threat/img/Threat/30_sec_pressed.png')}");

    btn6Min->setStyleSheet("QPushButton {image: url(':/threat/img/Threat/6_min.png')}"
                           "QPushButton:checked {image: url(':/threat/img/Threat/6_min_pressed.png')}");

    btn15Min->setStyleSheet("QPushButton {image: url(':/threat/img/Threat/15_min.png')}"
                            "QPushButton:checked {image: url(':/threat/img/Threat/15_min_pressed.png')}");

    btnReset->setStyleSheet("QPushButton {image: url(':/threat/img/Threat/reset.png')}"
                            "QPushButton:pressed {image: url(':/threat/img/Threat/reset_pressed.png')}");

*/

void Threat::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}
void Threat::removeCode(QString code){
    miBotonera->removeCodeFromEstado(this, &code);
}

QString Threat::getName()
{
    return "Threat";
}

