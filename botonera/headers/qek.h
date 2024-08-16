#ifndef QEK_H
#define QEK_H

#include "Zone.h"
#include "boton.h"
#include "botonera.h"
#include "qpushbutton.h"
#include <QWidget>
#include <QtUiTools/QUiLoader>

class Botonera;
class Qek : public Zone
{

public:    
    void initiate(){
        gui_buttons = this->findChildren<QPushButton *>();
        //QList<QLine*> lin = this->findChildren<QLine*>();

        //for(QLine l: this->findChildren<QLine>()){

        //}

        QList<Boton*> logic_buttons = *new QList<Boton*>;
        for(int i=1;i<=32;i++){

            QString code = *new QString("QEK_");
            code.append(QString::number(i));
            auto *logic_button = new Boton(this,code);
            logic_buttons.append(logic_button);
            QObject::connect(gui_buttons[i-1], &QPushButton::pressed, logic_button, &Boton::interact);
            QObject::connect(gui_buttons[i-1], &QPushButton::released, logic_button, &Boton::interact);
            gui_buttons[i-1]->setStyleSheet(gui_buttons[i-1]->styleSheet() + "QPushButton {"
                                                                                 "    border: none;"  // Quita el borde
                                                                                 "}"
                                                                                 "QPushButton:pressed {"
                                                                                 "    border: none;"  // Mantén el borde oculto al presionar
                                                                                 "}");
        }
    }

    void sendCode(QString code){
        miBotonera->sendCodeToQek(code);
    }
    void removeCode(QString code){
        miBotonera->removeCodeFromQek(code);
    }

    QString getName(){
        return "QEK";
    }



protected:
    Botonera *miBotonera;
    QList<QPushButton *> gui_buttons;
};

#endif // QEK_H
