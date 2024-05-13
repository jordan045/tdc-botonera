#include "threat.h"
#include <QRadioButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>

threat::threat(QWidget *parent) :
    QWidget(parent)
{
    auto *btn_1 = new QRadioButton("1",this);
    auto *btn_2 = new QRadioButton("2",this);
    auto *btn_3 = new QRadioButton("3",this);
    auto *btn_4 = new QRadioButton("4",this);
    auto *btn_5 = new QRadioButton("5",this);

    QButtonGroup *threat_group = new QButtonGroup(this);

    threat_group->addButton(btn_1,1);
    threat_group->addButton(btn_2,2);
    threat_group->addButton(btn_3,3);
    threat_group->addButton(btn_4,4);
    threat_group->addButton(btn_5,5);


    auto layout = new QHBoxLayout;
    layout->addWidget(btn_1);
    layout->addWidget(btn_2);
    layout->addWidget(btn_3);
    layout->addWidget(btn_4);
    layout->addWidget(btn_5);

    this->setLayout(layout);

    //graphic buttons
    auto *logic_btn_1  = new Boton(1,this);
    auto *logic_btn_2  = new Boton(2,this);
    auto *logic_btn_3  = new Boton(3,this);
    auto *logic_btn_4  = new Boton(4,this);
    auto *logic_btn_5  = new Boton(5,this);


    QObject::connect(btn_1,&QRadioButton::clicked,logic_btn_1,&Boton::pressed);
    QObject::connect(btn_2,&QRadioButton::clicked,logic_btn_2,&Boton::pressed);
    QObject::connect(btn_3,&QRadioButton::clicked,logic_btn_3,&Boton::pressed);
    QObject::connect(btn_4,&QRadioButton::clicked,logic_btn_4,&Boton::pressed);
    QObject::connect(btn_5,&QRadioButton::clicked,logic_btn_5,&Boton::pressed);

}

