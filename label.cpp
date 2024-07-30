#include "label.h"
#include "botonera.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <boton.h>

Label::Label(Botonera *b)
{

    miBotonera = b;

    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QButtonGroup *label_group = new QButtonGroup();

    auto layout = new QHBoxLayout;

    QList<QString> labels = {"ms",
                             "trkm",
                             "ampl_info",
                              "link_stat",
                             "tn"};


    for(int i = 1;i<=5;i++){
        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,labels[i-1]);

        gui_button->setCheckable(true);
        gui_button->setFlat(true);
        label_group->addButton(gui_button,i);

        layout->addWidget(gui_button);

        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);

        QObject::connect(gui_button, &QPushButton::pressed, logic_button, &Boton::interact);
        QObject::connect(gui_button, &QPushButton::released, logic_button, &Boton::interact);

        QString style = QString("QPushButton {image: url(':/label_selection/img/Label Selection/%1.png')}"
                                "QPushButton:pressed {image: url(':/label_selection/img/Label Selection/%1_pressed.png')}").arg(labels[i-1]);

        gui_button->setStyleSheet(style);

    }
    this->setLayout(layout);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");
}

/*
    auto *ms = new QPushButton("",this);
    auto *trkm = new QPushButton("",this);
    auto *ampl_info = new QPushButton("",this);
    auto *link_stat = new QPushButton("",this);
    auto *tn = new QPushButton("",this);

    ms->setCheckable(true);
    trkm->setCheckable(true);
    ampl_info->setCheckable(true);
    link_stat->setCheckable(true);
    tn->setCheckable(true);

    ms->setFlat(true);
    trkm->setFlat(true);
    ampl_info->setFlat(true);
    link_stat->setFlat(true);
    tn->setFlat(true);

    QButtonGroup *label_group = new QButtonGroup();
    label_group->setExclusive(false);

    label_group->addButton(ms,1);
    label_group->addButton(trkm,2);
    label_group->addButton(ampl_info,3);
    label_group->addButton(link_stat,4);
    label_group->addButton(tn,5);

    auto layout = new QHBoxLayout;
    layout->addWidget(ms);
    layout->addWidget(trkm);
    layout->addWidget(ampl_info);
    layout->addWidget(link_stat);
    layout->addWidget(tn);

    this->setLayout(layout);

    //graphic buttons
    auto *logic_ms   = new Boton(this, "MS");
    auto *logic_trkm   = new Boton(this, "TRKM");
    auto *logic_ampl_info   = new Boton(this, "AMPL INFO");
    auto *logic_link_stat  = new Boton(this, "LINK STAT");
    auto *logic_tn  = new Boton(this, "TN");


    QObject::connect(ms,&QPushButton::toggled,logic_ms,&Boton::interact);
    QObject::connect(trkm,&QPushButton::toggled,logic_trkm,&Boton::interact);
    QObject::connect(ampl_info,&QPushButton::toggled,logic_ampl_info,&Boton::interact);
    QObject::connect(link_stat,&QPushButton::toggled,logic_link_stat,&Boton::interact);
    QObject::connect(tn,&QPushButton::toggled,logic_tn,&Boton::interact);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");



    ms->setStyleSheet("QPushButton {image: url(':/label_selection/img/Label Selection/ms.png')}"
                      "QPushButton:checked {image: url(':/label_selection/img/Label Selection/ms_pressed.png')}");


    trkm->setStyleSheet("QPushButton {image: url(':/label_selection/img/Label Selection/trkm.png')}"
                      "QPushButton:checked {image: url(':/label_selection/img/Label Selection/trkm_pressed.png')}");



    ampl_info->setStyleSheet("QPushButton {image: url(':/label_selection/img/Label Selection/ampl_info.png')}"
                      "QPushButton:checked {image: url(':/label_selection/img/Label Selection/ampl_info_pressed.png')}");


    link_stat->setStyleSheet("QPushButton {image: url(':/label_selection/img/Label Selection/link_stat.png')}"
                      "QPushButton:checked {image: url(':/label_selection/img/Label Selection/link_stat_pressed.png')}");


    tn->setStyleSheet("QPushButton {image: url(':/label_selection/img/Label Selection/tn.png')}"
                      "QPushButton:checked {image: url(':/label_selection/img/Label Selection/tn_pressed.png')}");
*/


void Label::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}

void Label::sendMessage(){
    return;
}

QString Label::getName()
{
    return "Label";
}
