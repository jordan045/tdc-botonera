#include "display_selection.h"
#include "boton.h"
#include "botonera.h"
#include "qboxlayout.h"
#include "qbuttongroup.h"
#include "qpushbutton.h"

DisplaySelection::DisplaySelection(Botonera *b)
{

    miBotonera = b;

    QButtonGroup *displaySelection_group = new QButtonGroup();
    displaySelection_group->setExclusive(false);

    auto layout = new QVBoxLayout;

    QList<QPushButton*> gui_buttons = *new QList<QPushButton*>;
    QList<Boton*> logic_buttons = *new QList<Boton*>;


    /*
     * AIR");
    auto *logicSurf = new Boton(this, "SURF");
    auto *logicSubSurf = new Boton(this, "SUBSURF");
    auto *logicRefPos = new Boton(this, "REFPOS");
    auto *logicBearSel = new Boton(this, "BEARSEL");
    auto *logicLinkSel = new Boton(this, "LINKSEL");
    auto *logicWarfSel = new Boton(this, "WARFSEL");
    auto *logicFig = new Boton(this, "FIG");
     */

    QList<QString> labels = {"air","surf","sub_surf",
                             "ref_pos","bear_sel","link_sel",
                             "warf_sel","fig"};

    for(int i = 1; i<=8;i++){
        auto *gui_button = new QPushButton("",this);
        auto *logic_button = new Boton(this,labels[i-1]);

        gui_button->setCheckable(true);
        gui_button->setFlat(true);  //No se si va acá
        displaySelection_group->addButton(gui_button,i);

        layout->addWidget(gui_button);


        gui_buttons.append(gui_button);
        logic_buttons.append(logic_button);


        layout->addWidget(gui_button);

        QObject::connect(gui_button, &QPushButton::toggled, logic_button, &Boton::interact);

        QString style = QString("QPushButton {image: url(':/display_selection/img/Display Selection/%1.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/%1_pressed.png')}").arg(labels[i-1]);

        gui_button->setStyleSheet(style);
        gui_button->setMinimumSize(80,80); // TAMAÑO A LA FUERZA
    }
    this->setLayout(layout);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0);}"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");
}

void DisplaySelection::sendCode(QString code)
{
    miBotonera->sendCodeToDisplaySelection(&code);
}
void DisplaySelection::sendMessage(){
    return;
}

QString DisplaySelection::getName()
{
    return "Display Selection";
}
