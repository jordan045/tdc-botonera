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




    /*
    auto *air = new QPushButton("",this);
    auto *surf = new QPushButton("",this);
    auto *subSurf = new QPushButton("",this);
    auto *refPos = new QPushButton("",this);
    auto *bearSel = new QPushButton("",this);
    auto *linkSel = new QPushButton("",this);
    auto *warfSel = new QPushButton("",this);
    auto *fig = new QPushButton("",this);

    air->setCheckable(true);
    air->setFlat(true);

    surf->setCheckable(true);
    surf->setFlat(true);

    subSurf->setCheckable(true);
    subSurf->setFlat(true);

    refPos->setCheckable(true);
    refPos->setFlat(true);

    bearSel->setCheckable(true);
    bearSel->setFlat(true);

    linkSel->setCheckable(true);
    linkSel->setFlat(true);

    warfSel->setCheckable(true);
    warfSel->setFlat(true);

    fig->setCheckable(true);
    fig->setFlat(true);

    // Create a new QButtonGroup
    QButtonGroup *displaySelection = new QButtonGroup();

    // Set exclusive property to false
    displaySelection->setExclusive(false);

    // Add all buttons to the group
    displaySelection->addButton(air);
    displaySelection->addButton(surf);
    displaySelection->addButton(subSurf);
    displaySelection->addButton(refPos);
    displaySelection->addButton(bearSel);
    displaySelection->addButton(linkSel);
    displaySelection->addButton(warfSel);
    displaySelection->addButton(fig);

    auto layout = new QVBoxLayout;
    layout->addWidget(air);
    layout->addWidget(surf);
    layout->addWidget(subSurf);
    layout->addWidget(refPos);
    layout->addWidget(bearSel);
    layout->addWidget(linkSel);
    layout->addWidget(warfSel);
    layout->addWidget(fig);

    this->setLayout(layout);

    auto *logicAir = new Boton(this, "AIR");
    auto *logicSurf = new Boton(this, "SURF");
    auto *logicSubSurf = new Boton(this, "SUBSURF");
    auto *logicRefPos = new Boton(this, "REFPOS");
    auto *logicBearSel = new Boton(this, "BEARSEL");
    auto *logicLinkSel = new Boton(this, "LINKSEL");
    auto *logicWarfSel = new Boton(this, "WARFSEL");
    auto *logicFig = new Boton(this, "FIG");

    QObject::connect(air, &QPushButton::toggled, logicAir, &Boton::interact);
    QObject::connect(surf, &QPushButton::toggled, logicSurf, &Boton::interact);
    QObject::connect(subSurf, &QPushButton::toggled, logicSubSurf, &Boton::interact);
    QObject::connect(refPos, &QPushButton::toggled, logicRefPos, &Boton::interact);
    QObject::connect(bearSel, &QPushButton::toggled, logicBearSel, &Boton::interact);
    QObject::connect(linkSel, &QPushButton::toggled, logicLinkSel, &Boton::interact);
    QObject::connect(warfSel, &QPushButton::toggled, logicWarfSel, &Boton::interact);
    QObject::connect(fig, &QPushButton::toggled, logicFig, &Boton::interact);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");

    air->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/air.png')}"
                       "QPushButton:checked {image: url(':/display_selection/img/Display Selection/air_pressed.png')}");

    surf->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/surf.png')}"
                        "QPushButton:checked {image: url(':/display_selection/img/Display Selection/surf_pressed.png')}");

    subSurf->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/sub_surf.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/sub_surf_pressed.png')}");

    refPos->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/ref_pos.png')}"
                           "QPushButton:checked {image: url(':/display_selection/img/Display Selection/ref_pos_pressed.png')}");

    bearSel->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/bear_sel.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/bear_sel_pressed.png')}");

    linkSel->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/link_sel.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/link_sel_pressed.png')}");

    warfSel->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/warf_sel.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/warf_sel_pressed.png')}");

    fig->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/fig.png')}"
                       "QPushButton:checked {image: url(':/display_selection/img/Display Selection/fig_pressed.png')}");
    */
}

void DisplaySelection::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}
void DisplaySelection::sendMessage(){
    return;
}

QString DisplaySelection::getName()
{
    return "Display Selection";
}
