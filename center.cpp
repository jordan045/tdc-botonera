#include "center.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

center::center(QWidget *parent) :
    QWidget(parent)
{
    auto *cu_or_off_cent = new QPushButton("",this);
    auto *cu_or_cent = new QPushButton("",this);
    auto *off_cent = new QPushButton("",this);
    auto *cent = new QPushButton("",this);
    auto *reset_obm = new QPushButton("",this);
    auto *data_req = new QPushButton("",this);

    auto layout = new QVBoxLayout;
    layout->addWidget(cu_or_off_cent);
    layout->addWidget(cu_or_cent);
    layout->addWidget(off_cent);
    layout->addWidget(cent);
    layout->addWidget(reset_obm);
    layout->addWidget(data_req);


    this->setLayout(layout);

    //graphic buttons
    auto *logic_cu_or_off_cent   = new Boton(1,this);
    auto *logic_cu_or_cent   = new Boton(2,this);
    auto *logic_off_cent   = new Boton(3,this);
    auto *logic_cent  = new Boton(4,this);
    auto *logic_reset_obm  = new Boton(5,this);
    auto *logic_data_req  = new Boton(6,this);


    QObject::connect(cu_or_off_cent,&QPushButton::clicked,logic_cu_or_off_cent,&Boton::pressed);
    QObject::connect(cu_or_cent,&QPushButton::clicked,logic_cu_or_cent,&Boton::pressed);
    QObject::connect(off_cent,&QPushButton::clicked,logic_off_cent,&Boton::pressed);
    QObject::connect(cent,&QPushButton::clicked,logic_cent,&Boton::pressed);
    QObject::connect(reset_obm,&QPushButton::clicked,logic_reset_obm,&Boton::pressed);
    QObject::connect(data_req,&QPushButton::clicked,logic_data_req,&Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);");

    cu_or_off_cent->setStyleSheet("QPushButton {image: url(':/center/img/Center/cooc.png')}"
                                "QPushButton:pressed {image: url(':/center/img/Center/cooc_pressed.png')}");

    cu_or_cent->setStyleSheet("QPushButton {image: url(':/center/img/Center/coc.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/coc_pressed.png')}");

    off_cent->setStyleSheet("QPushButton {image: url(':/center/img/Center/oc.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/oc_pressed.png')}");

    cent->setStyleSheet("QPushButton {image: url(':/center/img/Center/cent.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/cent_pressed.png')}");

    reset_obm->setStyleSheet("QPushButton {image: url(':/center/img/Center/reset_obm.png')}"
                                  "QPushButton:pressed {image: url(':/center/img/Center/reset_obm_pressed.png')}");
}

