#include "icm.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

icm::icm(QWidget *parent) :
    QWidget(parent)
{
    auto *btn_1 = new QPushButton("1",this);
    auto *btn_2 = new QPushButton("2",this);
    auto *btn_3 = new QPushButton("3",this);
    auto *btn_4 = new QPushButton("4",this);
    auto *btn_5 = new QPushButton("5",this);
    auto *btn_6 = new QPushButton("6",this);
    auto *btn_7 = new QPushButton("7",this);

    QButtonGroup *icm_group = new QButtonGroup(this);

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
    auto *logic_btn_1 = new Boton(1,this);
    auto *logic_btn_2 = new Boton(2,this);
    auto *logic_btn_3 = new Boton(3,this);
    auto *logic_btn_4 = new Boton(4,this);
    auto *logic_btn_5 = new Boton(5,this);
    auto *logic_btn_6 = new Boton(6,this);
    auto *logic_btn_7 = new Boton(7,this);

    QObject::connect(btn_1,&QPushButton::clicked,logic_btn_1,&Boton::pressed);
    QObject::connect(btn_2,&QPushButton::clicked,logic_btn_2,&Boton::pressed);
    QObject::connect(btn_3,&QPushButton::clicked,logic_btn_3,&Boton::pressed);
    QObject::connect(btn_4,&QPushButton::clicked,logic_btn_4,&Boton::pressed);
    QObject::connect(btn_5,&QPushButton::clicked,logic_btn_5,&Boton::pressed);
    QObject::connect(btn_6,&QPushButton::clicked,logic_btn_6,&Boton::pressed);
    QObject::connect(btn_7,&QPushButton::clicked,logic_btn_7,&Boton::pressed);

    btn_1->setStyleSheet("QPushButton { width: 80px; height: 80px; background-color: rgb(10,150,10); font: 24pt}"
                         "QPushButton::pressed {background-color: rgb(10,240,10);}");
    btn_2->setStyleSheet("QPushButton { width: 80px; height: 80px; background-color: rgb(10,150,10); font: 24pt}"
                         "QPushButton::pressed {background-color: rgb(10,240,10);}");
    btn_3->setStyleSheet("QPushButton { width: 80px; height: 80px; background-color: rgb(10,150,10); font: 24pt}"
                         "QPushButton::pressed {background-color: rgb(10,240,10);}");
    btn_4->setStyleSheet("QPushButton { width: 80px; height: 80px; background-color: rgb(10,150,10); font: 24pt}"
                         "QPushButton::pressed {background-color: rgb(10,240,10);}");
    btn_5->setStyleSheet("QPushButton { width: 80px; height: 80px; background-color: rgb(10,150,10); font: 24pt}"
                         "QPushButton::pressed {background-color: rgb(10,240,10);}");
    btn_6->setStyleSheet("QPushButton { width: 80px; height: 80px; background-color: rgb(10,150,10); font: 24pt}"
                         "QPushButton::pressed {background-color: rgb(10,240,10);}");
    btn_7->setStyleSheet("QPushButton { width: 80px; height: 80px; background-color: rgb(10,150,10); font: 24pt}"
                         "QPushButton::pressed {background-color: rgb(10,240,10);}");
    btn_1->setMaximumHeight(80);
    btn_1->setMaximumWidth(80);
    btn_1->setMinimumHeight(80);
    btn_1->setMinimumWidth(80);

    btn_2->setMaximumHeight(80);
    btn_2->setMaximumWidth(80);
    btn_2->setMinimumHeight(80);
    btn_2->setMinimumWidth(80);


    btn_3->setMaximumHeight(80);
    btn_3->setMaximumWidth(80);
    btn_3->setMinimumHeight(80);
    btn_3->setMinimumWidth(80);


    btn_4->setMaximumHeight(80);
    btn_4->setMaximumWidth(80);
    btn_4->setMinimumHeight(80);
    btn_4->setMinimumWidth(80);

    btn_5->setMaximumHeight(80);
    btn_5->setMaximumWidth(80);
    btn_5->setMinimumHeight(80);
    btn_5->setMinimumWidth(80);

    btn_6->setMaximumHeight(80);
    btn_6->setMaximumWidth(80);
    btn_6->setMinimumHeight(80);
    btn_6->setMinimumWidth(80);

    btn_7->setMaximumHeight(80);
    btn_7->setMaximumWidth(80);
    btn_7->setMinimumHeight(80);
    btn_7->setMinimumWidth(80);

}
