#include "zone_label.h"
#include "boton.h"
#include "botonera.h"
#include "ui_zone_label.h"

zone_label::zone_label(Botonera *b)
    :ui(new Ui::zone_label)
{
    ui->setupUi(this);
    miBotonera = b;
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    QList<QPushButton*> gui_buttons = this->findChildren<QPushButton*>();
    QList<QString> labels = {"ms","trkm","ampl_info","link_stat","tn"};

    for(int i = 1;i<=5;i++){
        auto *logic_button = new Boton(this,labels[i-1]);
        logic_buttons.append(logic_button);
        QObject::connect(gui_buttons[i-1], &QPushButton::toggled, logic_button, &Boton::interact);
        gui_buttons[i-1]->setStyleSheet(gui_buttons[i-1]->styleSheet() + "QPushButton {"
                                                                             "    border: none;"  // Quita el borde
                                                                             "}"
                                                                             "QPushButton:pressed {"
                                                                             "    border: none;"  // Mantén el borde oculto al presionar
                                                                             "}");
    }
}

zone_label::~zone_label(){
    delete ui;
}

void zone_label::sendCode(QString code){
    miBotonera->sendCodeToLabelSelection(&code);
}

void zone_label::removeCode(QString code){
    miBotonera->removeCodeFromLabelSelection(code);
}


QString zone_label::getName(){
    return "LABEL_SELECTION";
}
