#include "display_mode.h"
#include "botonera.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>
DisplayMode::DisplayMode(Botonera *b)
{

    miBotonera = b;

    auto *hm = new QPushButton("",this);
    auto *rr = new QPushButton("",this);
    auto *ownCurs = new QPushButton("",this);
    auto *symbLarge = new QPushButton("",this);
    auto *tm = new QPushButton("",this);
    auto *emerg = new QPushButton("",this);
    auto *systAlarm = new QPushButton("",this);

    hm->setCheckable(true);
    hm->setFlat(true);

    rr->setCheckable(true);
    rr->setFlat(true);

    ownCurs->setCheckable(true);
    ownCurs->setFlat(true);

    symbLarge->setCheckable(true);
    symbLarge->setFlat(true);

    tm->setCheckable(true);
    tm->setFlat(true);

    emerg->setCheckable(true);
    emerg->setFlat(true);

    systAlarm->setCheckable(true);
    systAlarm->setFlat(true);

    QButtonGroup *displayModeGroup = new QButtonGroup();
    displayModeGroup->setExclusive(false);

    displayModeGroup->addButton(hm,1);
    displayModeGroup->addButton(rr,2);
    displayModeGroup->addButton(ownCurs,3);
    displayModeGroup->addButton(symbLarge,4);
    displayModeGroup->addButton(tm,5);
    displayModeGroup->addButton(emerg,6);
    displayModeGroup->addButton(systAlarm,7);

    auto layout = new QHBoxLayout;
    layout->addWidget(hm);
    layout->addWidget(rr);
    layout->addWidget(ownCurs);
    layout->addWidget(symbLarge);
    layout->addWidget(tm);
    layout->addWidget(emerg);
    layout->addWidget(systAlarm);

    this->setLayout(layout);

    //graphic buttons
    auto *logicHm   = new Boton(this, "HM");
    auto *logicRr   = new Boton(this, "RR");
    auto *logicOwnCurs   = new Boton(this, "OWN CURS");
    auto *logicSymbLarge  = new Boton(this, "SYMB LARGE");
    auto *logicTm  = new Boton(this, "TM");
    auto *logicEmerg  = new Boton(this, "EMERG");
    auto *logicSystAlarm = new Boton(this, "SYST ALARM");

    QObject::connect(hm,&QPushButton::clicked,logicHm,&Boton::pressed);
    QObject::connect(rr,&QPushButton::clicked,logicRr,&Boton::pressed);
    QObject::connect(ownCurs,&QPushButton::clicked,logicOwnCurs,&Boton::pressed);
    QObject::connect(symbLarge,&QPushButton::clicked,logicSymbLarge,&Boton::pressed);
    QObject::connect(tm,&QPushButton::clicked,logicTm,&Boton::pressed);
    QObject::connect(emerg,&QPushButton::clicked,logicEmerg,&Boton::pressed);
    QObject::connect(systAlarm,&QPushButton::clicked,logicSystAlarm,&Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:checked {background-color: rgba(0,0,0,0);}");

    hm->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/hm.png')}"
                      "QPushButton:checked {image: url(':/display_mode/img/Display Mode/hm_pressed.png')}");

    rr->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/rr.png')}"
                      "QPushButton:checked {image: url(':/display_mode/img/Display Mode/rr_pressed.png')}");

    ownCurs->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/own_curs.png')}"
                            "QPushButton:checked {image: url(':/display_mode/img/Display Mode/own_curs_pressed.png')}");

    symbLarge->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/symb_large.png')}"
                              "QPushButton:checked {image: url(':/display_mode/img/Display Mode/symb_large_pressed.png')}");

    tm->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/tm.png')}"
                      "QPushButton:checked {image: url(':/display_mode/img/Display Mode/tm_pressed.png')}");

    emerg->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/emerg.png')}"
                         "QPushButton:checked {image: url(':/display_mode/img/Display Mode/emerg_pressed.png')}");

    systAlarm->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/syst_alarm.png')}"
                              "QPushButton:checked {image: url(':/display_mode/img/Display Mode/syst_alarm_pressed.png')}");


}

void DisplayMode::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}
