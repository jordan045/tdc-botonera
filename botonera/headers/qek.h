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
        int buttonIndex = 0; // Índice para acceder a los gui_buttons
        for (int i = 20; i <= 57; ++i) {
            // Omitir los números no deseados
            if ((i >= 28 && i <= 29) || (i >= 38 && i <= 39) || (i >= 48 && i <= 49)) {
                continue; // Saltar los números no deseados
            }

            QString code = "QEK_";
            code.append(QString::number(i));

            auto *logic_button = new Boton(this, code);
            logic_buttons.append(logic_button);

            QObject::connect(gui_buttons[buttonIndex], &QPushButton::pressed, logic_button, &Boton::interact);
            QObject::connect(gui_buttons[buttonIndex], &QPushButton::released, logic_button, &Boton::interact);

            gui_buttons[buttonIndex]->setStyleSheet(gui_buttons[buttonIndex]->styleSheet() + "QPushButton {"
                                                                                             "    border: none;"
                                                                                             "}"
                                                                                             "QPushButton:pressed {"
                                                                                             "    border: none;"
                                                                                             "}");

            ++buttonIndex; // Avanzar al siguiente botón de la GUI
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
