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
    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QButtonGroup *range_group = new QButtonGroup();

    auto layout = new QVBoxLayout;

    QList<QString> labels = {"2","4","8","16","32","64","128","256"};

    for(int i=1;i<=7;i++){
        QString code = *new QString("RANGE ");
        code.append(labels[i-1]);

        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,code);

        gui_button->setCheckable(true);
        gui_button->setFlat(true);  //No se si va acá
        range_group->addButton(gui_button,i);

        layout->addWidget(gui_button);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        QObject::connect(gui_button, &QPushButton::toggled, logic_button, &Boton::interact);

        QString style = QString("QPushButton {image: url(':/range/img/Range/%1.png')}"
                                "QPushButton:checked {image: url(':/range/img/Range/%1_pressed.png')}").arg(labels[i-1]);

        gui_button->setStyleSheet(style);
    }
    this->setLayout(layout);
    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}");
}

void Range::sendCode(QString code)
{
    qDebug()<<"Me hicieron sendCode";
    miBotonera->sendCodeToEstado(this, &code);
}
void Range::removeCode(QString code){
    miBotonera->removeCodeFromEstado(this, &code);
}

void Range::sendMessage(){
    qDebug()<<"Me tocaron en rango";
    miBotonera->sendMessage();
}



