#include "display_selection.h"
#include "boton.h"
#include "botonera.h"
#include "qboxlayout.h"
#include "qbuttongroup.h"
#include "qpushbutton.h"

Display_selection::Display_selection(botonera *b)
{

    miBotonera = b;

    auto *air = new QPushButton("",this);
    auto *surf = new QPushButton("",this);
    auto *sub_surf = new QPushButton("",this);
    auto *ref_pos = new QPushButton("",this);
    auto *bear_sel = new QPushButton("",this);
    auto *link_sel = new QPushButton("",this);
    auto *warf_sel = new QPushButton("",this);
    auto *fig = new QPushButton("",this);

    air->setCheckable(true);
    air->setFlat(true);

    surf->setCheckable(true);
    surf->setFlat(true);

    sub_surf->setCheckable(true);
    sub_surf->setFlat(true);

    ref_pos->setCheckable(true);
    ref_pos->setFlat(true);

    bear_sel->setCheckable(true);
    bear_sel->setFlat(true);

    link_sel->setCheckable(true);
    link_sel->setFlat(true);

    warf_sel->setCheckable(true);
    warf_sel->setFlat(true);

    fig->setCheckable(true);
    fig->setFlat(true);

    // Create a new QButtonGroup
    QButtonGroup *display_selection = new QButtonGroup();

    // Set exclusive property to false
    display_selection->setExclusive(false);

    // Add all buttons to the group
    display_selection->addButton(air);
    display_selection->addButton(surf);
    display_selection->addButton(sub_surf);
    display_selection->addButton(ref_pos);
    display_selection->addButton(bear_sel);
    display_selection->addButton(link_sel);
    display_selection->addButton(warf_sel);
    display_selection->addButton(fig);

    auto layout = new QHBoxLayout;
    layout->addWidget(air);
    layout->addWidget(surf);
    layout->addWidget(sub_surf);
    layout->addWidget(ref_pos);
    layout->addWidget(bear_sel);
    layout->addWidget(link_sel);
    layout->addWidget(warf_sel);
    layout->addWidget(fig);

    this->setLayout(layout);

    auto *logic_air = new Boton(this, "AIR");
    auto *logic_surf = new Boton(this, "SURF");
    auto *logic_sub_surf = new Boton(this, "SUB SURF");
    auto *logic_ref_pos = new Boton(this, "REF POS");
    auto *logic_bear_sel = new Boton(this, "BEAR SEL");
    auto *logic_link_sel = new Boton(this, "LINK SEL");
    auto *logic_warf_sel = new Boton(this, "WARF SEL");
    auto *logic_fig = new Boton(this, "FIG");

    QObject::connect(air, &QPushButton::clicked, logic_air, &Boton::pressed);
    QObject::connect(surf, &QPushButton::clicked, logic_surf, &Boton::pressed);
    QObject::connect(sub_surf, &QPushButton::clicked, logic_sub_surf, &Boton::pressed);
    QObject::connect(ref_pos, &QPushButton::clicked, logic_ref_pos, &Boton::pressed);
    QObject::connect(bear_sel, &QPushButton::clicked, logic_bear_sel, &Boton::pressed);
    QObject::connect(link_sel, &QPushButton::clicked, logic_link_sel, &Boton::pressed);
    QObject::connect(warf_sel, &QPushButton::clicked, logic_warf_sel, &Boton::pressed);
    QObject::connect(fig, &QPushButton::clicked, logic_fig, &Boton::pressed);

    this->setStyleSheet("QPushButton {width: 80px; height: 80px; background-color: rgba(0,0,0,0)}"
                        "QPushButton:hover {background-color: rgba(0,0,0,0); }"
                        "QPushButton:pressed {background-color: rgba(0,0,0,0);}");

    air->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/air.png')}"
                       "QPushButton:checked {image: url(':/display_selection/img/Display Selection/air_pressed.png')}");

    surf->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/surf.png')}"
                        "QPushButton:checked {image: url(':/display_selection/img/Display Selection/surf_pressed.png')}");

    sub_surf->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/sub_surf.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/sub_surf_pressed.png')}");

    ref_pos->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/ref_pos.png')}"
                           "QPushButton:checked {image: url(':/display_selection/img/Display Selection/ref_pos_pressed.png')}");

    bear_sel->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/bear_sel.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/bear_sel_pressed.png')}");

    link_sel->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/link_sel.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/link_sel_pressed.png')}");

    warf_sel->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/warf_sel.png')}"
                            "QPushButton:checked {image: url(':/display_selection/img/Display Selection/warf_sel_pressed.png')}");

    fig->setStyleSheet("QPushButton {image: url(':/display_selection/img/Display Selection/fig.png')}"
                       "QPushButton:checked {image: url(':/display_selection/img/Display Selection/fig_pressed.png')}");

}

void Display_selection::sendCode(QString code)
{
    miBotonera->sendCodeToEstado(this, &code);
}
