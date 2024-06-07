#ifndef RANGE_H
#define RANGE_H

#include "Zone.h"
#include "boton.h"

#include "qbuttongroup.h"
#include <QWidget>

class Botonera;
class Range : public Zone
{

public:
    explicit Range(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    void sendMessage() override;

private:

    Botonera *miBotonera;

    QAbstractButton *btn_2;
    QAbstractButton *btn_4;
    QAbstractButton *btn_8;
    QAbstractButton *btn_16;
    QAbstractButton *btn_32;
    QAbstractButton *btn_64;
    QAbstractButton *btn_128;
    QAbstractButton *btn_256;
    QAbstractButton *btnMessage;


    Boton *logic_btn_2;
    Boton *logic_btn_4;
    Boton *logic_btn_8;
    Boton *logic_btn_16;
    Boton *logic_btn_32;
    Boton *logic_btn_64;
    Boton *logic_btn_128;
    Boton *logic_btn_256;
    Boton *logicBotonMessage;

    QButtonGroup *range_group;
    void createGraphicsButtons();
    void createLogicButtons();
    void createButtonGroup();
    void connection();
    void createLayout();
    void style();
};

#endif // RANGE_H
