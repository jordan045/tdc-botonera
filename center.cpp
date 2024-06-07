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


    QObject::connect(curOrOffCent,&QPushButton::toggled,logicCurOrOffCent,&Boton::interact);
    QObject::connect(curOrCent,&QPushButton::toggled,logicCurOrCent,&Boton::interact);
    QObject::connect(offCent,&QPushButton::toggled,logicOffCent,&Boton::interact);
    QObject::connect(cent,&QPushButton::toggled,logicCent,&Boton::interact);
    QObject::connect(reset_obm,&QPushButton::toggled,logicResetObm,&Boton::interact);
    QObject::connect(data_req,&QPushButton::toggled,logicDataReq,&Boton::interact);

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

void Center::sendMessage(){
    return;
}

void Center::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}

