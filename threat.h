#ifndef THREAT_H
#define THREAT_H

#include "Zone.h"
#include "boton.h"
#include "qpushbutton.h"
#include <QWidget>

class Botonera;
class Threat : public Zone
{

public:
    explicit Threat(Botonera *b);
    void sendCode(QString code) override;
    void sendMessage();
    void removeCode(QString code);

private:
    Botonera *miBotonera;
    QPushButton *btn12Sec;
    QPushButton *btn30Sec;
    QPushButton *btn6Min;
    QPushButton *btn15Min;
    QPushButton *btnReset;

    Boton *logicBtn12Sec;
    Boton *logicBtn30Sec;
    Boton *logicBtn6Min;
    Boton *logicBtn15Min;
    Boton *logicBtnReset;

    QButtonGroup *threatGroup;

    void createGraphicsButtons();
    void createLogicButtons();
    void createButtonGroup();
    void connection();
    void createLayout();
    void style();
};

#endif // THREAT_H
