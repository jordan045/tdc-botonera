#include "qek.h"
#include "botonera.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <boton.h>

Qek::Qek(Botonera *b)
{
    miBotonera = b;

    QString overlay = miBotonera->getEstado()->getOverlay();

    QUiLoader loader;
    QString url = QString(":/forms/overlay_140_%1.ui").arg(overlay);
    QFile file(url);

    QWidget *myWidget = loader.load(&file, this);
    file.close();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(myWidget);
    setLayout(layout);

    /*
    QButtonGroup *icm_group = new QButtonGroup();
    auto layoutgral = new QVBoxLayout;
    auto layout1 = new QHBoxLayout;
    auto layout2 = new QHBoxLayout;
    auto layout3 = new QHBoxLayout;
    auto layout4 = new QHBoxLayout;

    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    for(int i=1;i<=32;i++){
        QString code = *new QString("QEK ");
        code.append(QString::number(i));

        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,code);

        gui_button->setCheckable(true);
        gui_button->setFlat(true);
        icm_group->addButton(gui_button,i);

        if(1 <= i && i <= 8)
            layout1->addWidget(gui_button);
        if(9 <= i && i <= 16)
            layout2->addWidget(gui_button);
        if(17 <= i && i <= 24)
            layout3->addWidget(gui_button);
        if(25 <= i && i <= 32)
            layout4->addWidget(gui_button);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        QObject::connect(gui_button, &QPushButton::pressed, logic_button, &Boton::interact);
        QObject::connect(gui_button, &QPushButton::released, logic_button, &Boton::interact);
    }

    layoutgral->addLayout(layout1);
    layoutgral->addLayout(layout2);
    layoutgral->addLayout(layout3);
    layoutgral->addLayout(layout4);

    this->setLayout(layoutgral);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton {image: url(':/qek/img/QEK/qek.png')}"
                        "QPushButton:pressed {image: url(':/qek/img/QEK/qek_pressed.png')}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");
*/
}

void Qek::sendCode(QString code){
    miBotonera->sendCodeToEstado(this, &code);
}
void Qek::removeCode(QString code){
    miBotonera->removeCodeFromEstado(this,&code);
}

void Qek::sendMessage(){
    return;
}
