#include "zona.h"
#include "boton.h"
#include <mainwindow.h>

Zona::Zona(QList<QRadioButton *> children) {
    Boton *range_2 = new Boton(children.at(0),2);
    Boton *range_4 = new Boton(children.at(1),4);
    Boton *range_8 = new Boton(children.at(2),8);
    Boton *range_16 = new Boton(children.at(3),16);
    Boton *range_32 = new Boton(children.at(4),32);
    Boton *range_64 = new Boton(children.at(5),64);
    Boton *range_128 = new Boton(children.at(6),128);
    Boton *range_256 = new Boton(children.at(7),256);
}
