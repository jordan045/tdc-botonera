#include "center.h"
#include "botonera.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

Center::Center(Botonera *b)
{
    miBotonera = b;

    auto *curOrOffCent = new QPushButton("",this);
    auto *curOrCent = new QPushButton("",this);
    auto *offCent = new QPushButton("",this);
    auto *cent = new QPushButton("",this);
    auto *reset_obm = new QPushButton("",this);
    auto *data_req = new QPushButton("",this);

    auto layout = new QHBoxLayout;
    layout->addWidget(curOrOffCent);
    layout->addWidget(curOrCent);
    layout->addWidget(offCent);
    layout->addWidget(cent);
    layout->addWidget(reset_obm);
    layout->addWidget(data_req);


    this->setLayout(layout);

    //graphic buttons
    auto *logicCurOrOffCent   = new Boton(this, "CU OR OFF CENT");
    auto *logicCurOrCent   = new Boton(this, "CU OR CENT");
    auto *logicOffCent   = new Boton(this, "OFF CENT");
    auto *logicCent  = new Boton(this, "CENT");
    auto *logicResetObm  = new Boton(this, "RESET OBM");
    auto *logicDataReq  = new Boton(this, "DATA REQ");


    QObject::connect(curOrOffCent,&QPushButton::pressed,logicCurOrOffCent,&Boton::pressed);
    QObject::connect(curOrCent,&QPushButton::pressed,logicCurOrCent,&Boton::pressed);
    QObject::connect(offCent,&QPushButton::pressed,logicOffCent,&Boton::pressed);
    QObject::connect(cent,&QPushButton::pressed,logicCent,&Boton::pressed);
    QObject::connect(reset_obm,&QPushButton::pressed,logicResetObm,&Boton::pressed);
    QObject::connect(data_req,&QPushButton::pressed,logicDataReq,&Boton::pressed);

    QObject::connect(curOrOffCent,&QPushButton::released,logicCurOrOffCent,&Boton::unpressed);
    QObject::connect(curOrCent,&QPushButton::released,logicCurOrCent,&Boton::unpressed);
    QObject::connect(offCent,&QPushButton::released,logicOffCent,&Boton::unpressed);
    QObject::connect(cent,&QPushButton::released,logicCent,&Boton::unpressed);
    QObject::connect(reset_obm,&QPushButton::released,logicResetObm,&Boton::unpressed);
    QObject::connect(data_req,&QPushButton::released,logicDataReq,&Boton::unpressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");

    curOrOffCent->setStyleSheet("QPushButton {image: url(':/center/img/Center/cooc.png')}"
                                "QPushButton:pressed {image: url(':/center/img/Center/cooc_pressed.png')}");

    curOrCent->setStyleSheet("QPushButton {image: url(':/center/img/Center/coc.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/coc_pressed.png')}");

    offCent->setStyleSheet("QPushButton {image: url(':/center/img/Center/oc.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/oc_pressed.png')}");

    cent->setStyleSheet("QPushButton {image: url(':/center/img/Center/cent.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/cent_pressed.png')}");

    reset_obm->setStyleSheet("QPushButton {image: url(':/center/img/Center/reset_obm.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/reset_obm_pressed.png')}");
}

void Center::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}

