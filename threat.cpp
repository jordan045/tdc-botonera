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
    createGraphicsButtons();
    createLogicButtons();
    createButtonGroup();
    connection();
    createLayout();
    style();
}

void Threat::sendMessage(){
    return;
}

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
    logicBtn12Sec  = new Boton(this, "12 SEC");
    logicBtn30Sec  = new Boton(this, "30 SEC");
    logicBtn6Min   = new Boton(this, "6 MIN");
    logicBtn15Min  = new Boton(this, "15 MIN");
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
    QObject::connect(btn12Sec,&QPushButton::clicked,logicBtn12Sec,&Boton::pressed);
    QObject::connect(btn30Sec,&QPushButton::clicked,logicBtn30Sec,&Boton::pressed);
    QObject::connect(btn6Min,&QPushButton::clicked,logicBtn6Min,&Boton::pressed);
    QObject::connect(btn15Min,&QPushButton::clicked,logicBtn15Min,&Boton::pressed);
    QObject::connect(btnReset,&QPushButton::clicked,logicBtnReset,&Boton::pressed);
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

}
void Threat::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}

