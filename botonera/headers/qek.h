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
        QList<QPushButton *> gui_buttons = this->findChildren<QPushButton *>();
        //QList<QLine*> lin = this->findChildren<QLine*>();

        //for(QLine l: this->findChildren<QLine>()){

        //}

        QList<Boton*> logic_buttons = *new QList<Boton*>;
        for(int i=1;i<=32;i++){
            QString code = *new QString("QEK ");
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
        miBotonera->sendCodeToQek(&code);
    }
    void removeCode(QString code){
        miBotonera->removeCodeFromQek(&code);
    }
    void sendMessage(){
         miBotonera->sendMessage();
    }
    QString getName(){
        return "QEK";
    }

    void setOverlay(QString){
        // overlay = o;
        // if(overlay == "0001" || overlay == "0101" || overlay == "0010" || overlay == "0110" || overlay == "0011" || overlay == "1000"){
        //     qek_group->button(32)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
        //     qek_group->button(16)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_E));
        //     qek_group->button(15)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_W));
        //     qek_group->button(14)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
        // }
    }

protected:
    Botonera *miBotonera;
};

#endif // QEK_H
