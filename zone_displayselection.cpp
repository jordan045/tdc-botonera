#include "zone_displayselection.h"
#include "ui_zone_displayselection.h"
#include "botonera.h"

zone_displaySelection::zone_displaySelection(Botonera *b)
    : ui (new Ui::zone_displaySelection)
{
    ui->setupUi(this);
    miBotonera = b;

    QList<QString> labels = {"air","surf","sub_surf",
                             "ref_pos","bear_sel","link_sel",
                             "warf_sel","fig"};

    QList<QPushButton *> gui_buttons = this->findChildren<QPushButton*>();
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    for(int i=1;i<=8;i++){

        auto *logic_button = new Boton(this,labels[i-1]);

        logic_buttons.append(logic_button);

        QObject::connect(gui_buttons[i-1], &QPushButton::toggled, logic_button, &Boton::interact);

        qDebug()<<"LISTO: " << labels[i-1] << i;

    }
}


void zone_displaySelection::sendCode(QString code)
{
    miBotonera->sendCodeToDisplaySelection(&code);
}

void zone_displaySelection::removeCode(QString code)
{
    miBotonera->removeCodeFromDisplaySelection(&code);
}

void zone_displaySelection::sendMessage()
{

}

QString zone_displaySelection::getName()
{
    return "DISPLAYSELECTION";
}

zone_displaySelection::~zone_displaySelection()
{
    delete ui;
}
