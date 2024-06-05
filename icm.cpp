#include "icm.h"
#include "botonera.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <boton.h>

Icm::Icm(Botonera *b)
{

    miBotonera = b;

    auto *btn1 = new QPushButton("",this);
    auto *btn2 = new QPushButton("",this);
    auto *btn3 = new QPushButton("",this);
    auto *btn4 = new QPushButton("",this);
    auto *btn5 = new QPushButton("",this);
    auto *btn6 = new QPushButton("",this);
    auto *btn7 = new QPushButton("",this);

    btn1->setCheckable(true);
    btn2->setCheckable(true);
    btn3->setCheckable(true);
    btn4->setCheckable(true);
    btn5->setCheckable(true);
    btn6->setCheckable(true);
    btn7->setCheckable(true);

    QButtonGroup *icmGroup = new QButtonGroup();
    icmGroup->setExclusive(false);

    icmGroup->addButton(btn1,1);
    icmGroup->addButton(btn2,2);
    icmGroup->addButton(btn3,3);
    icmGroup->addButton(btn4,4);
    icmGroup->addButton(btn5,5);
    icmGroup->addButton(btn6,6);
    icmGroup->addButton(btn7,7);

    auto layout = new QVBoxLayout;
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    layout->addWidget(btn4);
    layout->addWidget(btn5);
    layout->addWidget(btn6);
    layout->addWidget(btn7);

    this->setLayout(layout);

    //graphic buttons
    auto *logicBtn1 = new Boton(this, "ICM 1");
    auto *logicBtn2 = new Boton(this, "ICM 2");
    auto *logicBtn3 = new Boton(this, "ICM 3");
    auto *logicBtn4 = new Boton(this, "ICM 4");
    auto *logicBtn5 = new Boton(this, "ICM 5");
    auto *logicBtn6 = new Boton(this, "ICM 6");
    auto *logicBtn7 = new Boton(this, "ICM 7");

    QObject::connect(btn1,&QPushButton::clicked,logicBtn1,&Boton::pressed);
    QObject::connect(btn2,&QPushButton::clicked,logicBtn2,&Boton::pressed);
    QObject::connect(btn3,&QPushButton::clicked,logicBtn3,&Boton::pressed);
    QObject::connect(btn4,&QPushButton::clicked,logicBtn4,&Boton::pressed);
    QObject::connect(btn5,&QPushButton::clicked,logicBtn5,&Boton::pressed);
    QObject::connect(btn6,&QPushButton::clicked,logicBtn6,&Boton::pressed);
    QObject::connect(btn7,&QPushButton::clicked,logicBtn7,&Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");
    btn1->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/1.png')}"
                     "QPushButton:checked {image: url(':/icm/img/ICM/1_pressed.png')}");
    btn2->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/2.png')}"
                       "QPushButton:checked {image: url(':/icm/img/ICM/2_pressed.png')}");
    btn3->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/3.png')}"
                            "QPushButton:checked {image: url(':/icm/img/ICM/3_pressed.png')}");
    btn4->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/4.png')}"
                            "QPushButton:checked {image: url(':/icm/img/ICM/4_pressed.png')}");
    btn5->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/5.png')}"
                     "QPushButton:checked {image: url(':/icm/img/ICM/5_pressed.png')}");
    btn6->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/6.png')}"
                        "QPushButton:checked {image: url(':/icm/img/ICM/6_pressed.png')}");
    btn7->setStyleSheet("QPushButton {image: url(':/icm/img/ICM/7.png')}"
                        "QPushButton:checked {image: url(':/icm/img/ICM/7_pressed.png')}");


}

void Icm::sendMessage(){
    return;
}
void Icm::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}
