#include "range.h"
#include "botonera.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>
#

Range::Range(Botonera *b)

{
    miBotonera = b;
    createGraphicsButtons();
    createLogicButtons();
    createButtonGroup();
    connection();
    createLayout();
    style();
}

void Range::sendCode(QString code)
{
    qDebug()<<"Me hicieron sendCode";
    miBotonera->sendCodeToEstado(this, &code);
}

void Range::sendMessage(){
    qDebug()<<"Me tocaron en rango";
    miBotonera->sendMessage();
}


void Range::createGraphicsButtons()
{
    btn_2   = new QPushButton(this);
    btn_4   = new QPushButton(this);
    btn_8   = new QPushButton(this);
    btn_16  = new QPushButton(this);
    btn_32  = new QPushButton(this);
    btn_64  = new QPushButton(this);
    btn_128 = new QPushButton(this);
    btn_256 = new QPushButton(this);
    btnMessage = new QPushButton(this);

    btn_2->setCheckable(true);
    btn_4->setCheckable(true);
    btn_8->setCheckable(true);
    btn_16->setCheckable(true);
    btn_32->setCheckable(true);
    btn_64->setCheckable(true);
    btn_128->setCheckable(true);
    btn_256->setCheckable(true);
}

void Range::createLogicButtons()
{
    QVector<Boton*> logic_buttons = *new QVector<Boton*>();
    logic_btn_2   = new Boton(this,"RANGE 2");
    logic_btn_4   = new Boton(this,"RANGE 4");
    logic_btn_8   = new Boton(this,"RANGE 8");
    logic_btn_16  = new Boton(this,"RANGE 16");
    logic_btn_32  = new Boton(this,"RANGE 32");
    logic_btn_64  = new Boton(this,"RANGE 64");
    logic_btn_128 = new Boton(this,"RANGE 128");
    logic_btn_256 = new Boton(this,"RANGE 256");
    logicBotonMessage = new Boton(this,"mensage");

    logic_buttons.append(logic_btn_2);
}

void Range::createButtonGroup()
{
    range_group = new QButtonGroup();
    range_group->addButton(btn_2,2);
    range_group->addButton(btn_4,4);
    range_group->addButton(btn_8,8);
    range_group->addButton(btn_16,16);
    range_group->addButton(btn_32,32);
    range_group->addButton(btn_64,64);
    range_group->addButton(btn_128,128);
    range_group->addButton(btn_256,256);
    range_group->addButton(btnMessage,512);
    btn_8->setChecked(true);
}

void Range::connection()
{
    QObject::connect(btn_2,&QPushButton::clicked,logic_btn_2,&Boton::pressed);
    QObject::connect(btn_4,&QPushButton::clicked,logic_btn_4,&Boton::pressed);
    QObject::connect(btn_8,&QPushButton::clicked,logic_btn_8,&Boton::pressed);
    QObject::connect(btn_16,&QPushButton::clicked,logic_btn_16,&Boton::pressed);
    QObject::connect(btn_32,&QPushButton::clicked,logic_btn_32,&Boton::pressed);
    QObject::connect(btn_64,&QPushButton::clicked,logic_btn_64,&Boton::pressed);
    QObject::connect(btn_128,&QPushButton::clicked,logic_btn_128,&Boton::pressed);
    QObject::connect(btn_256,&QPushButton::clicked,logic_btn_256,&Boton::pressed);
    QObject::connect(btnMessage,&QPushButton::clicked,logicBotonMessage,&Boton::sendMessage);
}

void Range::createLayout()
{
    auto layout = new QVBoxLayout;
    layout->addWidget(btn_2);
    layout->addWidget(btn_4);
    layout->addWidget(btn_8);
    layout->addWidget(btn_16);
    layout->addWidget(btn_32);
    layout->addWidget(btn_64);
    layout->addWidget(btn_128);
    layout->addWidget(btn_256);
    layout->addWidget(btnMessage);

    this->setLayout(layout);
}

void Range::style()
{
    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}");

    btn_2->setStyleSheet("QPushButton {image: url(':/range/img/Range/2.png')}"
                         "QPushButton:checked {image: url(':/range/img/Range/2_pressed.png')}");

    btn_4->setStyleSheet("QPushButton {image: url(':/range/img/Range/4.png')}"
                         "QPushButton:checked {image: url(':/range/img/Range/4_pressed.png')}");

    btn_8->setStyleSheet("QPushButton {image: url(':/range/img/Range/8.png')}"
                         "QPushButton:checked {image: url(':/range/img/Range/8_pressed.png')}");

    btn_16->setStyleSheet( "QPushButton {image: url(':/range/img/Range/16.png')}"
                          "QPushButton:checked {image: url(':/range/img/Range/16_pressed.png')}");

    btn_32->setStyleSheet( "QPushButton {image: url(':/range/img/Range/32.png')}"
                          "QPushButton:checked {image: url(':/range/img/Range/32_pressed.png')}");

    btn_64->setStyleSheet( "QPushButton {image: url(':/range/img/Range/64.png')}"
                          "QPushButton:checked {image: url(':/range/img/Range/64_pressed.png')}");

    btn_128->setStyleSheet(  "QPushButton {image: url(':/range/img/Range/128.png')}"
                           "QPushButton:checked {image: url(':/range/img/Range/128_pressed.png')}");

    btn_256->setStyleSheet(  "QPushButton {image: url(':/range/img/Range/256.png')}"
                           "QPushButton:checked {image: url(':/range/img/Range/256_pressed.png')}");

    btnMessage->setStyleSheet(  "QPushButton {image: url(':/range/img/Range/256.png')}"
                              "QPushButton:checked {image: url(':/range/img/Range/256_pressed.png')}");

}

