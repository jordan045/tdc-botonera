#ifndef RANGE_H
#define RANGE_H

#include "boton.h"
#include "qbuttongroup.h"
#include <QWidget>

class range : public QWidget
{
    Q_OBJECT
public:
    explicit range(QWidget *parent = nullptr);

private:

    QAbstractButton *btn_2;
    QAbstractButton *btn_4;
    QAbstractButton *btn_8;
    QAbstractButton *btn_16;
    QAbstractButton *btn_32;
    QAbstractButton *btn_64;
    QAbstractButton *btn_128;
    QAbstractButton *btn_256;

    Boton *logic_btn_2;
    Boton *logic_btn_4;
    Boton *logic_btn_8;
    Boton *logic_btn_16;
    Boton *logic_btn_32;
    Boton *logic_btn_64;
    Boton *logic_btn_128;
    Boton *logic_btn_256;

    QButtonGroup *range_group;
    void createGraphicsButtons();
    void createLogicButtons();
    void createButtonGroup();
    void connection();
    void createLayout();
    void style();
};

#endif // RANGE_H
