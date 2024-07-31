#include "display_mode.h"
#include "botonera.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>
DisplayMode::DisplayMode(Botonera *b)
{

    miBotonera = b;

    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QButtonGroup *display_mode_group = new QButtonGroup();
    display_mode_group->setExclusive(false);

    auto layout = new QHBoxLayout;

    QList<QString> labels = {"HM",
                             "RR",
                             "OWN_CURS",
                             "SYMB_LARGE",
                             "TM",
                             "EMERG",
                             "SYST_ALARM"};

    for(int i=1;i<=7;i++){
        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,labels[i-1]);

        gui_button->setCheckable(true);
        gui_button->setFlat(true);  //No se si va acá
        display_mode_group->addButton(gui_button,i);

        layout->addWidget(gui_button);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        QObject::connect(gui_button, &QPushButton::toggled, logic_button, &Boton::interact);

        QString style = QString("QPushButton {image: url(':/display_mode/img/Display Mode/%1.png')}"
                                "QPushButton:checked {image: url(':/display_mode/img/Display Mode/%1_pressed.png')}").arg(labels[i-1]);

        gui_button->setStyleSheet(style);
    }

    this->setLayout(layout);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:checked {background-color: rgba(0,0,0,0);}");
}

void DisplayMode::sendCode(QString code){
    miBotonera->sendCodeToDisplayMode(&code);
}
void DisplayMode::removeCode(QString code){
    miBotonera->removeCodeFromDisplayMode(&code);
}
void DisplayMode::sendMessage(){
    return;
}

QString DisplayMode::getName()
{
    return "DisplayMode";
}
