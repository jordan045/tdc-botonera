#include "botonera.h"
#include <QVBoxLayout>
#include <QLabel>
botonera::botonera(QWidget *parent) :
    QWidget(parent)
{
    r = new range();
    l = new label();
    q = new qek();
    t = new threat();
    c = new center();
    d = new display_mode();
    i = new icm();
}

void botonera::setmodo(int i)
{
    modo = i;
}

void botonera::iniciar()
{
    QHBoxLayout *layout = new QHBoxLayout();
/*
    layout->addWidget(r,0,1);
    layout->addWidget(q,1,1);
    layout->addWidget(t,2,1);
    layout->addWidget(i,0,0);
    layout->addWidget(d,3,1);
    layout->addWidget(l,4,1);
    layout->addWidget(c,0,2);
*/
    QVBoxLayout *midLay = new QVBoxLayout();
    midLay->addWidget(r);
    midLay->addWidget(q);
    midLay->addWidget(t);
    midLay->addWidget(d);
    midLay->addWidget(l);

    layout->addWidget(i);
    layout->addLayout(midLay);
    layout->addWidget(c);

    //QString texto = QString::number(modo);
    //QLabel *label = new QLabel(texto);

    //layout->addWidget(label,0,3);
    this->setLayout(layout);
    this->show();
}
/*
 botonera::lanzar()
{
    modo = 1;
    QGridLayout *layout = new QGridLayout;

    layout->addWidget(r,0,1);
    layout->addWidget(q,1,1);
    layout->addWidget(t,2,1);
    layout->addWidget(i,0,0);
    layout->addWidget(d,3,1);
    layout->addWidget(l,4,1);
    layout->addWidget(c,0,2);

    QLabel *label = new QLabel("1");

    layout->addWidget(label,0,3);
    this->setLayout(layout);
    this->show();

}
*/

