#include "qek.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <boton.h>

qek::qek(QWidget *parent) :
    QWidget(parent)
{
    auto *btn_1 = new QPushButton("",this);
    auto *btn_2 = new QPushButton("",this);
    auto *btn_3 = new QPushButton("",this);
    auto *btn_4 = new QPushButton("",this);
    auto *btn_5 = new QPushButton("",this);
    auto *btn_6 = new QPushButton("",this);
    auto *btn_7 = new QPushButton("",this);
    auto *btn_8 = new QPushButton("",this);

    auto *btn_9 = new QPushButton("",this);
    auto *btn_10 = new QPushButton("",this);
    auto *btn_11 = new QPushButton("",this);
    auto *btn_12 = new QPushButton("",this);
    auto *btn_13 = new QPushButton("",this);
    auto *btn_14 = new QPushButton("",this);
    auto *btn_15 = new QPushButton("",this);
    auto *btn_16 = new QPushButton("",this);

    auto *btn_17 = new QPushButton("",this);
    auto *btn_18 = new QPushButton("",this);
    auto *btn_19 = new QPushButton("",this);
    auto *btn_20 = new QPushButton("",this);
    auto *btn_21 = new QPushButton("",this);
    auto *btn_22 = new QPushButton("",this);
    auto *btn_23 = new QPushButton("",this);
    auto *btn_24 = new QPushButton("",this);

    auto *btn_25 = new QPushButton("",this);
    auto *btn_26 = new QPushButton("",this);
    auto *btn_27 = new QPushButton("",this);
    auto *btn_28 = new QPushButton("",this);
    auto *btn_29 = new QPushButton("",this);
    auto *btn_30 = new QPushButton("",this);
    auto *btn_31 = new QPushButton("",this);
    auto *btn_32 = new QPushButton("",this);

    btn_1->setCheckable(true); btn_1->setFlat(true);
    btn_2->setCheckable(true); btn_2->setFlat(true);
    btn_3->setCheckable(true); btn_3->setFlat(true);
    btn_4->setCheckable(true); btn_4->setFlat(true);
    btn_5->setCheckable(true); btn_5->setFlat(true);
    btn_6->setCheckable(true); btn_6->setFlat(true);
    btn_7->setCheckable(true); btn_7->setFlat(true);
    btn_8->setCheckable(true); btn_8->setFlat(true);
    btn_9->setCheckable(true); btn_9->setFlat(true);
    btn_10->setCheckable(true); btn_10->setFlat(true);
    btn_11->setCheckable(true); btn_11->setFlat(true);
    btn_12->setCheckable(true); btn_12->setFlat(true);
    btn_13->setCheckable(true); btn_13->setFlat(true);
    btn_14->setCheckable(true); btn_14->setFlat(true);
    btn_15->setCheckable(true); btn_15->setFlat(true);
    btn_16->setCheckable(true); btn_16->setFlat(true);
    btn_17->setCheckable(true); btn_17->setFlat(true);
    btn_18->setCheckable(true); btn_18->setFlat(true);
    btn_19->setCheckable(true); btn_19->setFlat(true);
    btn_20->setCheckable(true); btn_20->setFlat(true);
    btn_21->setCheckable(true); btn_21->setFlat(true);
    btn_22->setCheckable(true); btn_22->setFlat(true);
    btn_23->setCheckable(true); btn_23->setFlat(true);
    btn_24->setCheckable(true); btn_24->setFlat(true);
    btn_25->setCheckable(true); btn_25->setFlat(true);
    btn_26->setCheckable(true); btn_26->setFlat(true);
    btn_27->setCheckable(true); btn_27->setFlat(true);
    btn_28->setCheckable(true); btn_28->setFlat(true);
    btn_29->setCheckable(true); btn_29->setFlat(true);
    btn_30->setCheckable(true); btn_30->setFlat(true);
    btn_31->setCheckable(true); btn_31->setFlat(true);
    btn_32->setCheckable(true); btn_32->setFlat(true);



    QButtonGroup *icm_group = new QButtonGroup(this);

    icm_group->addButton(btn_1,1);
    icm_group->addButton(btn_2,2);
    icm_group->addButton(btn_3,3);
    icm_group->addButton(btn_4,4);
    icm_group->addButton(btn_5,5);
    icm_group->addButton(btn_6,6);
    icm_group->addButton(btn_7,7);

    icm_group->addButton(btn_8,8);
    icm_group->addButton(btn_9,9);
    icm_group->addButton(btn_10,11);
    icm_group->addButton(btn_12,12);
    icm_group->addButton(btn_13,13);
    icm_group->addButton(btn_14,14);
    icm_group->addButton(btn_15,15);

    icm_group->addButton(btn_16, 16);
    icm_group->addButton(btn_17, 17);
    icm_group->addButton(btn_18, 18);
    icm_group->addButton(btn_19, 19);
    icm_group->addButton(btn_20, 20);
    icm_group->addButton(btn_21, 21);
    icm_group->addButton(btn_22, 22);
    icm_group->addButton(btn_23, 23);
    icm_group->addButton(btn_24, 24);

    icm_group->addButton(btn_25, 25);
    icm_group->addButton(btn_26, 26);
    icm_group->addButton(btn_27, 27);
    icm_group->addButton(btn_28, 28);
    icm_group->addButton(btn_29, 29);
    icm_group->addButton(btn_30, 30);
    icm_group->addButton(btn_31, 31);
    icm_group->addButton(btn_32, 32);

    auto layoutgral = new QVBoxLayout;

    auto layout1 = new QHBoxLayout;
    layout1->addWidget(btn_1);
    layout1->addWidget(btn_2);
    layout1->addWidget(btn_3);
    layout1->addWidget(btn_4);
    layout1->addWidget(btn_5);
    layout1->addWidget(btn_6);
    layout1->addWidget(btn_7);
    layout1->addWidget(btn_8);

    layoutgral->addLayout(layout1);

    auto layout2 = new QHBoxLayout;
    layout2->addWidget(btn_9);
    layout2->addWidget(btn_10);
    layout2->addWidget(btn_11);
    layout2->addWidget(btn_12);
    layout2->addWidget(btn_13);
    layout2->addWidget(btn_14);
    layout2->addWidget(btn_15);
    layout2->addWidget(btn_16);

    layoutgral->addLayout(layout2);

    auto layout3 = new QHBoxLayout;
    layout3->addWidget(btn_17);
    layout3->addWidget(btn_18);
    layout3->addWidget(btn_19);
    layout3->addWidget(btn_20);
    layout3->addWidget(btn_21);
    layout3->addWidget(btn_22);
    layout3->addWidget(btn_23);
    layout3->addWidget(btn_24);

    layoutgral->addLayout(layout3);

    auto layout4 = new QHBoxLayout;
    layout4->addWidget(btn_25);
    layout4->addWidget(btn_26);
    layout4->addWidget(btn_27);
    layout4->addWidget(btn_28);
    layout4->addWidget(btn_29);
    layout4->addWidget(btn_30);
    layout4->addWidget(btn_31);
    layout4->addWidget(btn_32);

    layoutgral->addLayout(layout4);

    this->setLayout(layoutgral);

    //graphic buttons
    auto *logic_btn_1  = new Boton("QEK 1", this);
    auto *logic_btn_2  = new Boton("QEK 2", this);
    auto *logic_btn_3  = new Boton("QEK 3", this);
    auto *logic_btn_4  = new Boton("QEK 4", this);
    auto *logic_btn_5  = new Boton("QEK 5", this);
    auto *logic_btn_6  = new Boton("QEK 6", this);
    auto *logic_btn_7  = new Boton("QEK 7", this);
    auto *logic_btn_8  = new Boton("QEK 8", this);

    auto *logic_btn_9  = new Boton("QEK 9", this);
    auto *logic_btn_10 = new Boton("QEK 10", this);
    auto *logic_btn_11 = new Boton("QEK 11", this);
    auto *logic_btn_12 = new Boton("QEK 12", this);
    auto *logic_btn_13 = new Boton("QEK 13", this);
    auto *logic_btn_14 = new Boton("QEK 14", this);
    auto *logic_btn_15 = new Boton("QEK 15", this);
    auto *logic_btn_16 = new Boton("QEK 16", this);

    auto *logic_btn_17 = new Boton("QEK 17", this);
    auto *logic_btn_18 = new Boton("QEK 18", this);
    auto *logic_btn_19 = new Boton("QEK 19", this);
    auto *logic_btn_20 = new Boton("QEK 20", this);
    auto *logic_btn_21 = new Boton("QEK 21", this);
    auto *logic_btn_22 = new Boton("QEK 22", this);
    auto *logic_btn_23 = new Boton("QEK 23", this);
    auto *logic_btn_24 = new Boton("QEK 24", this);

    auto *logic_btn_25 = new Boton("QEK 25", this);
    auto *logic_btn_26 = new Boton("QEK 26", this);
    auto *logic_btn_27 = new Boton("QEK 27", this);
    auto *logic_btn_28 = new Boton("QEK 28", this);
    auto *logic_btn_29 = new Boton("QEK 29", this);
    auto *logic_btn_30 = new Boton("QEK 30", this);
    auto *logic_btn_31 = new Boton("QEK 31", this);
    auto *logic_btn_32 = new Boton("QEK 32", this);

    QObject::connect(btn_1, &QPushButton::clicked, logic_btn_1, &Boton::pressed);
    QObject::connect(btn_2, &QPushButton::clicked, logic_btn_2, &Boton::pressed);
    QObject::connect(btn_3, &QPushButton::clicked, logic_btn_3, &Boton::pressed);
    QObject::connect(btn_4, &QPushButton::clicked, logic_btn_4, &Boton::pressed);
    QObject::connect(btn_5, &QPushButton::clicked, logic_btn_5, &Boton::pressed);
    QObject::connect(btn_6, &QPushButton::clicked, logic_btn_6, &Boton::pressed);
    QObject::connect(btn_7, &QPushButton::clicked, logic_btn_7, &Boton::pressed);
    QObject::connect(btn_8, &QPushButton::clicked, logic_btn_8, &Boton::pressed);

    QObject::connect(btn_9, &QPushButton::clicked, logic_btn_9, &Boton::pressed);
    QObject::connect(btn_10, &QPushButton::clicked, logic_btn_10, &Boton::pressed);
    QObject::connect(btn_11, &QPushButton::clicked, logic_btn_11, &Boton::pressed);
    QObject::connect(btn_12, &QPushButton::clicked, logic_btn_12, &Boton::pressed);
    QObject::connect(btn_13, &QPushButton::clicked, logic_btn_13, &Boton::pressed);
    QObject::connect(btn_14, &QPushButton::clicked, logic_btn_14, &Boton::pressed);
    QObject::connect(btn_15, &QPushButton::clicked, logic_btn_15, &Boton::pressed);
    QObject::connect(btn_16, &QPushButton::clicked, logic_btn_16, &Boton::pressed);

    QObject::connect(btn_17, &QPushButton::clicked, logic_btn_17, &Boton::pressed);
    QObject::connect(btn_18, &QPushButton::clicked, logic_btn_18, &Boton::pressed);
    QObject::connect(btn_19, &QPushButton::clicked, logic_btn_19, &Boton::pressed);
    QObject::connect(btn_20, &QPushButton::clicked, logic_btn_20, &Boton::pressed);
    QObject::connect(btn_21, &QPushButton::clicked, logic_btn_21, &Boton::pressed);
    QObject::connect(btn_22, &QPushButton::clicked, logic_btn_22, &Boton::pressed);
    QObject::connect(btn_23, &QPushButton::clicked, logic_btn_23, &Boton::pressed);
    QObject::connect(btn_24, &QPushButton::clicked, logic_btn_24, &Boton::pressed);

    QObject::connect(btn_25, &QPushButton::clicked, logic_btn_25, &Boton::pressed);
    QObject::connect(btn_26, &QPushButton::clicked, logic_btn_26, &Boton::pressed);
    QObject::connect(btn_27, &QPushButton::clicked, logic_btn_27, &Boton::pressed);
    QObject::connect(btn_28, &QPushButton::clicked, logic_btn_28, &Boton::pressed);
    QObject::connect(btn_29, &QPushButton::clicked, logic_btn_29, &Boton::pressed);
    QObject::connect(btn_30, &QPushButton::clicked, logic_btn_30, &Boton::pressed);
    QObject::connect(btn_31, &QPushButton::clicked, logic_btn_31, &Boton::pressed);
    QObject::connect(btn_32, &QPushButton::clicked, logic_btn_32, &Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton {image: url(':/qek/img/QEK/qek.png')}"
                        "QPushButton:pressed {image: url(':/qek/img/QEK/qek_pressed.png')}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);");

}

