#include "botonera.h"
#include "display_selection.h"
#include <QVBoxLayout>
#include <QLabel>

botonera::botonera(QWidget *parent) :
    QWidget(parent)
{
    range_widget = new range();
    label_selection_widget = new label();
    qek_widget = new qek();
    threat_assesment_widget = new threat();
    center_widget = new center();
    display_mode_widget = new display_mode();
    icm_widget = new icm();
    display_selection_widget = new Display_selection();
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
    midLay->addWidget(range_widget);
    midLay->addWidget(qek_widget);
    midLay->addWidget(threat_assesment_widget);
    midLay->addWidget(display_mode_widget);
    midLay->addWidget(label_selection_widget);
    midLay->addWidget(display_selection_widget);

    layout->addWidget(icm_widget);
    layout->addLayout(midLay);
    layout->addWidget(center_widget);

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

