#include "threat.h"
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>

threat::threat(QWidget *parent) :
    QWidget(parent)
{
    auto *btn_12_sec = new QRadioButton("",this);
    auto *btn_30_sec = new QRadioButton("",this);
    auto *btn_6_min = new QRadioButton("",this);
    auto *btn_15_min = new QRadioButton("",this);
    auto *btn_reset = new QPushButton("",this);

    QButtonGroup *threat_group = new QButtonGroup(this);

    threat_group->addButton(btn_12_sec,1);
    threat_group->addButton(btn_30_sec,2);
    threat_group->addButton(btn_6_min,3);
    threat_group->addButton(btn_15_min,4);
    threat_group->addButton(btn_reset,5);


    auto layout = new QHBoxLayout;
    layout->addWidget(btn_12_sec);
    layout->addWidget(btn_30_sec);
    layout->addWidget(btn_6_min);
    layout->addWidget(btn_15_min);
    layout->addWidget(btn_reset);

    this->setLayout(layout);

    //graphic buttons
    auto *logic_btn_12_sec  = new Boton("12 SEC",this);
    auto *logic_btn_30_sec  = new Boton("30 SEC",this);
    auto *logic_btn_6_min   = new Boton("6 MIN",this);
    auto *logic_btn_15_min  = new Boton("15 MIN",this);
    auto *logic_btn_reset   = new Boton("RESET",this);


    QObject::connect(btn_12_sec,&QRadioButton::clicked,logic_btn_12_sec,&Boton::pressed);
    QObject::connect(btn_30_sec,&QRadioButton::clicked,logic_btn_30_sec,&Boton::pressed);
    QObject::connect(btn_6_min,&QRadioButton::clicked,logic_btn_6_min,&Boton::pressed);
    QObject::connect(btn_15_min,&QRadioButton::clicked,logic_btn_15_min,&Boton::pressed);
    QObject::connect(btn_reset,&QPushButton::clicked,logic_btn_reset,&Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);");

    btn_12_sec->setStyleSheet("QRadioButton::indicator {width: 80px; height: 80px;}"
                         "QRadioButton::indicator::unchecked {image: url(':/threat/img/Threat/12_sec.png')}"
                         "QRadioButton::indicator::checked {image: url(':/threat/img/Threat/12_sec_pressed.png')}");

    btn_30_sec->setStyleSheet("QRadioButton::indicator {width: 80px; height: 80px;}"
                              "QRadioButton::indicator::unchecked {image: url(':/threat/img/Threat/30_sec.png')}"
                              "QRadioButton::indicator::checked {image: url(':/threat/img/Threat/30_sec_pressed.png')}");

    btn_6_min->setStyleSheet("QRadioButton::indicator {width: 80px; height: 80px;}"
                              "QRadioButton::indicator::unchecked {image: url(':/threat/img/Threat/6_min.png')}"
                              "QRadioButton::indicator::checked {image: url(':/threat/img/Threat/6_min_pressed.png')}");

    btn_15_min->setStyleSheet("QRadioButton::indicator {width: 80px; height: 80px;}"
                              "QRadioButton::indicator::unchecked {image: url(':/threat/img/Threat/15_min.png')}"
                              "QRadioButton::indicator::checked {image: url(':/threat/img/Threat/15_min_pressed.png')}");

    btn_reset->setStyleSheet("QPushButton {image: url(':/threat/img/Threat/reset.png')}"
                            "QPushButton:pressed {image: url(':/threat/img/Threat/reset_pressed.png')}");
}

