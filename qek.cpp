#include "qek.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <boton.h>

qek::qek(QWidget *parent) :
    QWidget(parent)
{
    auto *btn_1 = new QPushButton("1",this);
    auto *btn_2 = new QPushButton("2",this);
    auto *btn_3 = new QPushButton("3",this);
    auto *btn_4 = new QPushButton("4",this);
    auto *btn_5 = new QPushButton("5",this);
    auto *btn_6 = new QPushButton("6",this);
    auto *btn_7 = new QPushButton("7",this);
    auto *btn_8 = new QPushButton("8",this);

    auto *btn_9 = new QPushButton("9",this);
    auto *btn_10 = new QPushButton("10",this);
    auto *btn_11 = new QPushButton("11",this);
    auto *btn_12 = new QPushButton("12",this);
    auto *btn_13 = new QPushButton("13",this);
    auto *btn_14 = new QPushButton("14",this);
    auto *btn_15 = new QPushButton("15",this);
    auto *btn_16 = new QPushButton("16",this);

    auto *btn_17 = new QPushButton("17",this);
    auto *btn_18 = new QPushButton("18",this);
    auto *btn_19 = new QPushButton("19",this);
    auto *btn_20 = new QPushButton("20",this);
    auto *btn_21 = new QPushButton("21",this);
    auto *btn_22 = new QPushButton("22",this);
    auto *btn_23 = new QPushButton("23",this);
    auto *btn_24 = new QPushButton("24",this);

    auto *btn_25 = new QPushButton("25",this);
    auto *btn_26 = new QPushButton("26",this);
    auto *btn_27 = new QPushButton("27",this);
    auto *btn_28 = new QPushButton("28",this);
    auto *btn_29 = new QPushButton("29",this);
    auto *btn_30 = new QPushButton("30",this);
    auto *btn_31 = new QPushButton("31",this);
    auto *btn_32 = new QPushButton("32",this);

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
    auto *logic_btn_1  = new Boton(1, this);
    auto *logic_btn_2  = new Boton(2, this);
    auto *logic_btn_3  = new Boton(3, this);
    auto *logic_btn_4  = new Boton(4, this);
    auto *logic_btn_5  = new Boton(5, this);
    auto *logic_btn_6  = new Boton(6, this);
    auto *logic_btn_7  = new Boton(7, this);
    auto *logic_btn_8  = new Boton(8, this);

    auto *logic_btn_9  = new Boton(9, this);
    auto *logic_btn_10 = new Boton(10, this);
    auto *logic_btn_11 = new Boton(11, this);
    auto *logic_btn_12 = new Boton(12, this);
    auto *logic_btn_13 = new Boton(13, this);
    auto *logic_btn_14 = new Boton(14, this);
    auto *logic_btn_15 = new Boton(15, this);
    auto *logic_btn_16 = new Boton(16, this);

    auto *logic_btn_17 = new Boton(17, this);
    auto *logic_btn_18 = new Boton(18, this);
    auto *logic_btn_19 = new Boton(19, this);
    auto *logic_btn_20 = new Boton(20, this);
    auto *logic_btn_21 = new Boton(21, this);
    auto *logic_btn_22 = new Boton(22, this);
    auto *logic_btn_23 = new Boton(23, this);
    auto *logic_btn_24 = new Boton(24, this);

    auto *logic_btn_25 = new Boton(25, this);
    auto *logic_btn_26 = new Boton(26, this);
    auto *logic_btn_27 = new Boton(27, this);
    auto *logic_btn_28 = new Boton(28, this);
    auto *logic_btn_29 = new Boton(29, this);
    auto *logic_btn_30 = new Boton(30, this);
    auto *logic_btn_31 = new Boton(31, this);
    auto *logic_btn_32 = new Boton(32, this);

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


}

