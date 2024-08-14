#include "zone_range.h"
#include "boton.h"
#include "ui_zone_range.h"
#include "botonera.h"

zone_range::zone_range(Botonera *b)
    : ui(new Ui::zone_range)
{
    ui->setupUi(this);
    miBotonera = b;

    QList<QString> labels = {"2","4","8","16","32","64","128","256"};
    QList<const char*> shortcuts = {"f2","f3","f4","f5","f6","f7","f8","f9"};

    QList<QPushButton *> gui_buttons = this->findChildren<QPushButton *>();

    QList<Boton*> logic_buttons = *new QList<Boton*>;
    for(int i=1;i<=8;i++){
        QString code = *new QString("RANGE");
        code.append(labels[i-1]);
        auto *logic_button = new Boton(this,code);
        if(i == 2)
            logic_button->setState(true);
        logic_buttons.append(logic_button);
        QObject::connect(gui_buttons[i-1], &QPushButton::toggled, logic_button, &Boton::interact);
        gui_buttons[i-1]->setShortcut(QKeySequence(tr(shortcuts[i-1])));
    }
}

void zone_range::sendCode(QString code)
{
    miBotonera->sendCodeToRange(&code);
}
void zone_range::removeCode(QString code){
    miBotonera->removeCodeFromRange(code);
}



QString zone_range::getName(){
    return "Range";
}

zone_range::~zone_range(){
    delete ui;
}
