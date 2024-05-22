#include "icm.h"
#include "botonera.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

icm::icm(botonera *b)
{

    qDebug() << "ICM ready";

    miBotonera = b;

    auto *btn_1 = new QPushButton("",this);
    auto *btn_2 = new QPushButton("",this);
    auto *btn_3 = new QPushButton("",this);
    auto *btn_4 = new QPushButton("",this);
    auto *btn_5 = new QPushButton("",this);
    auto *btn_6 = new QPushButton("",this);
    auto *btn_7 = new QPushButton("",this);

    btn_1->setCheckable(true);
    btn_2->setCheckable(true);
    btn_3->setCheckable(true);
    btn_4->setCheckable(true);
    btn_5->setCheckable(true);
    btn_6->setCheckable(true);
    btn_7->setCheckable(true);

    QButtonGroup *icm_group = new QButtonGroup();
    icm_group->setExclusive(false);

    icm_group->addButton(btn_1,1);
    icm_group->addButton(btn_2,2);
    icm_group->addButton(btn_3,3);
    icm_group->addButton(btn_4,4);
    icm_group->addButton(btn_5,5);
    icm_group->addButton(btn_6,6);
    icm_group->addButton(btn_7,7);

    auto layout = new QVBoxLayout;
    layout->addWidget(btn_1);
    layout->addWidget(btn_2);
    layout->addWidget(btn_3);
    layout->addWidget(btn_4);
    layout->addWidget(btn_5);
    layout->addWidget(btn_6);
    layout->addWidget(btn_7);

    this->setLayout(layout);

    //graphic buttons
    auto *logic_btn_1 = new Boton(this, "ICM 1");
    auto *logic_btn_2 = new Boton(this, "ICM 2");
    auto *logic_btn_3 = new Boton(this, "ICM 3");
    auto *logic_btn_4 = new Boton(this, "ICM 4");
    auto *logic_btn_5 = new Boton(this, "ICM 5");
    auto *logic_btn_6 = new Boton(this, "ICM 6");
    auto *logic_btn_7 = new Boton(this, "ICM 7");

    QObject::connect(btn_1,&QPushButton::clicked,logic_btn_1,&Boton::pressed);
    QObject::connect(btn_2,&QPushButton::clicked,logic_btn_2,&Boton::pressed);
    QObject::connect(btn_3,&QPushButton::clicked,logic_btn_3,&Boton::pressed);
    QObject::connect(btn_4,&QPushButton::clicked,logic_btn_4,&Boton::pressed);
    QObject::connect(btn_5,&QPushButton::clicked,logic_btn_5,&Boton::pressed);
    QObject::connect(btn_6,&QPushButton::clicked,logic_btn_6,&Boton::pressed);
    QObject::connect(btn_7,&QPushButton::clicked,logic_btn_7,&Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");

    btn_1->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/1.png')}"
                      "QPushButton:checked {image: url(':/icm/img/ICM/1_pressed.png')}");

    btn_2->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/2.png')}"
                        "QPushButton:checked {image: url(':/icm/img/ICM/2_pressed.png')}");

    btn_3->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/3.png')}"
                             "QPushButton:checked {image: url(':/icm/img/ICM/3_pressed.png')}");

    btn_4->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/4.png')}"
                             "QPushButton:checked {image: url(':/icm/img/ICM/4_pressed.png')}");

    btn_5->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/5.png')}"
                      "QPushButton:checked {image: url(':/icm/img/ICM/5_pressed.png')}");

    btn_6->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/6.png')}"
                         "QPushButton:checked {image: url(':/icm/img/ICM/6_pressed.png')}");

    btn_7->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/7.png')}"
                         "QPushButton:checked {image: url(':/icm/img/ICM/7_pressed.png')}");


}

void icm::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}
