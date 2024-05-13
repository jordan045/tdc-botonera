#include "initmenu.h"

#include <QPushButton>
#include<QHBoxLayout>
#include<QButtonGroup>
initMenu::initMenu(QWidget *parent) :
    QWidget(parent)
{
    miBotonera = new botonera();

    auto *btn_1 = new QPushButton("1",this);
    auto *btn_2 = new QPushButton("2",this);
    auto *btn_3 = new QPushButton("3",this);

    QButtonGroup *modo_group = new QButtonGroup(this);
    modo_group->addButton(btn_1,1);
    modo_group->addButton(btn_2,2);
    modo_group->addButton(btn_3,3);

    auto layout = new QHBoxLayout;
    layout->addWidget(btn_1);
    layout->addWidget(btn_2);
    layout->addWidget(btn_3);


    QObject::connect(btn_1,&QPushButton::clicked,this,&initMenu::iniciarModo);
    QObject::connect(btn_2,&QPushButton::clicked,this,&initMenu::iniciarModo);
    QObject::connect(btn_3,&QPushButton::clicked,this,&initMenu::iniciarModo);



    this->setLayout(layout);
}

void initMenu::iniciarModo(QPushButton b)
{
    miBotonera->setmodo();
    miBotonera->iniciar();
    this->close();
}
