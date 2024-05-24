#include "estado.h"
#include "qdebug.h"

Estado::Estado(botonera *b) {

    qDebug() << "Estado ready";

    miBotonera = b;

    range = new QString();
    label = new QString();
    qek  = new QString();
    threat = new QString();
    center = new QString();
    display = new QString();
    icm = new QString();
}

void Estado::setRange(QString *r){
    range = r;
    refresh();
}

void Estado::setLabel(QString *l){
    label = l;
    refresh();
}

void Estado::setQEK(QString *q){
    qek = q;
    refresh();
}

void Estado::setThreat(QString *t){
    threat = t;
    refresh();
}

void Estado::setCenter(QString *c){
    center = c;
    refresh();
}

void Estado::setDisplay(QString *d){
    display = d;
    refresh();
}

void Estado::setICM(QString *i){
    icm = i;
    refresh();
}

QString Estado::getRange(){return range;}
QString Estado::getLabel(){return label;}
QString Estado::getQEK(){return qek;}
QString Estado::getThreat(){return threat;}
QString Estado::getCenter(){return center;}
QString Estado::getDisplay(){return display;}
QString Estado::getICM(){return icm;}

void Estado::refresh()
{
    qDebug()    << "\nRange Scale: " << *range
                << "\nLabel Selection: " << *label
                << "\nQEK: " << *qek
                << "\nThreat Assesment" << *threat
                << "\nCenter: " << *center
                << "\nDisplay: " << *display
                << "\nICM: " << *icm;
}
