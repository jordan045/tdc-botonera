#include "zone_range.h"
#include "boton.h"
#include "ui_zone_range.h"
#include "botonera.h"

zone_range::zone_range(Botonera *b)
    : ui(new Ui::zone_range)
{

    qDebug() << "Estoy en el constructor de rango";
    ui->setupUi(this);
    miBotonera = b;
    qDebug()<< "ya ligue la botonera desde rango";
    QList<QString> labels = {"2","4","8","16","32","64","128","256"};
    QList<const char*> shortcuts = {"f2","f3","f4","f5","f6","f7","f8","f9"};

    QList<QPushButton *> gui_buttons = this->findChildren<QPushButton *>();

    qDebug()<<"agarre los gui buttons";
    QList<Boton*> logic_buttons = *new QList<Boton*>;
    for(int i=1;i<=8;i++){
        QString code = *new QString("RANGE");
        code.append(labels[i-1]);
        auto *logic_button = new Boton(this,code);
        if(i == 2){
            boton4 = logic_button;
        }
        logic_buttons.append(logic_button);
        QObject::connect(gui_buttons[i-1], &QPushButton::toggled, logic_button, &Boton::interact);
        gui_buttons[i-1]->setShortcut(QKeySequence(tr(shortcuts[i-1])));
        gui_buttons[i-1]->setStyleSheet(gui_buttons[i-1]->styleSheet() + "QPushButton {"
                                                                             "    border: none;"  // Quita el borde
                                                                             "}"
                                                                             "QPushButton:pressed {"
                                                                             "    border: none;"  // Mantén el borde oculto al presionar
                                                                             "}");
    }
    qDebug()<< "ya cree el rango";
}

void zone_range::sendCode(QString code)
{
    QPushButton *button = this->findChild<QPushButton*>(code);
    if(button){
        button->setChecked(true);
        qDebug()<<"se activó el boton visual del rango";
    }else
    {
        qDebug()<<"No se encontró el boton del rango";
    }
    miBotonera->sendCodeToRange(code);

    qDebug()<<"CODIGO RANGE"<<code;
}
void zone_range::removeCode(QString code){
    QPushButton *button = this->findChild<QPushButton*>(code);
    if(button){
        button->setChecked(false);
        qDebug()<<"se desactivo el boton visual del rango";
    }else
    {
        qDebug()<<"No se encontró el boton del rango";
    }
    miBotonera->removeCodeFromRange(code);

}



QString zone_range::getName(){
    return "Range";
}

zone_range::~zone_range(){
    delete ui;
}

void zone_range::start()
{
   boton4->interact();
   boton4->setState(true);
}
