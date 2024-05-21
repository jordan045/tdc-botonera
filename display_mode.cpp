#include "display_mode.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>

display_mode::display_mode(QWidget *parent) :
    QWidget(parent)
{
    auto *hm = new QPushButton("",this);
    auto *rr = new QPushButton("",this);
    auto *own_curs = new QPushButton("",this);
    auto *symb_large = new QPushButton("",this);
    auto *tm = new QPushButton("",this);
    auto *emerg = new QPushButton("",this);
    auto *syst_alarm = new QPushButton("",this);

    hm->setCheckable(true);
    hm->setFlat(true);

    rr->setCheckable(true);
    rr->setFlat(true);

    own_curs->setCheckable(true);
    own_curs->setFlat(true);

    symb_large->setCheckable(true);
    symb_large->setFlat(true);

    tm->setCheckable(true);
    tm->setFlat(true);

    emerg->setCheckable(true);
    emerg->setFlat(true);

    syst_alarm->setCheckable(true);
    syst_alarm->setFlat(true);

    QButtonGroup *display_mode_group = new QButtonGroup(this);
    display_mode_group->setExclusive(false);

    display_mode_group->addButton(hm,1);
    display_mode_group->addButton(rr,2);
    display_mode_group->addButton(own_curs,3);
    display_mode_group->addButton(symb_large,4);
    display_mode_group->addButton(tm,5);
    display_mode_group->addButton(emerg,6);
    display_mode_group->addButton(syst_alarm,7);

    auto layout = new QHBoxLayout;
    layout->addWidget(hm);
    layout->addWidget(rr);
    layout->addWidget(own_curs);
    layout->addWidget(symb_large);
    layout->addWidget(tm);
    layout->addWidget(emerg);
    layout->addWidget(syst_alarm);

    this->setLayout(layout);

    //graphic buttons
    auto *logic_hm   = new Boton("HM",this);
    auto *logic_rr   = new Boton("RR",this);
    auto *logic_own_curs   = new Boton("OWN CURS",this);
    auto *logic_symb_large  = new Boton("SYMB LARGE",this);
    auto *logic_tm  = new Boton("TM",this);
    auto *logic_emerg  = new Boton("EMERG",this);
    auto *logic_syst_alarm = new Boton("SYST ALARM",this);

    QObject::connect(hm,&QPushButton::clicked,logic_hm,&Boton::pressed);
    QObject::connect(rr,&QPushButton::clicked,logic_rr,&Boton::pressed);
    QObject::connect(own_curs,&QPushButton::clicked,logic_own_curs,&Boton::pressed);
    QObject::connect(symb_large,&QPushButton::clicked,logic_symb_large,&Boton::pressed);
    QObject::connect(tm,&QPushButton::clicked,logic_tm,&Boton::pressed);
    QObject::connect(emerg,&QPushButton::clicked,logic_emerg,&Boton::pressed);
    QObject::connect(syst_alarm,&QPushButton::clicked,logic_syst_alarm,&Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:checked {background-color: rgba(0,0,0,0);");

    hm->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/hm.png')}"
                      "QPushButton:checked {image: url(':/display_mode/img/Display Mode/hm_pressed.png')}");

    rr->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/rr.png')}"
                      "QPushButton:checked {image: url(':/display_mode/img/Display Mode/rr_pressed.png')}");

    own_curs->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/own_curs.png')}"
                            "QPushButton:checked {image: url(':/display_mode/img/Display Mode/own_curs_pressed.png')}");

    symb_large->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/symb_large.png')}"
                              "QPushButton:checked {image: url(':/display_mode/img/Display Mode/symb_large_pressed.png')}");

    tm->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/tm.png')}"
                      "QPushButton:checked {image: url(':/display_mode/img/Display Mode/tm_pressed.png')}");

    emerg->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/emerg.png')}"
                         "QPushButton:checked {image: url(':/display_mode/img/Display Mode/emerg_pressed.png')}");

    syst_alarm->setStyleSheet("QPushButton {image: url(':/display_mode/img/Display Mode/syst_alarm.png')}"
                              "QPushButton:checked {image: url(':/display_mode/img/Display Mode/syst_alarm_pressed.png')}");


}
