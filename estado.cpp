#include "estado.h"
#include "qdatetime.h"
#include "qdebug.h"

Estado::Estado(botonera *b) {

    miBotonera = b;

    this->range = new QString("");
    this->label = new QString("");
    this->qek  = new QString("");
    this->threat = new QString("");
    this->center = new QString("");
    this->display = new QString("");
    this->icm = new QString("");
    this->display_mode = new QString("");
}

void Estado::setRange(QString *r){
    qDebug() << "Setting Range";
    *this->range = *r;
    refresh();
}

void Estado::setLabel(QString *l){
    qDebug() << "Setting Label";
    *this->label = *l;
    refresh();
}

void Estado::setQEK(QString *q){
    qDebug() << "Setting QEK";
    *this->qek = *q;
    refresh();
}

void Estado::setThreat(QString *t){
    qDebug() << "Setting Threat";
    *this->threat = *t;
    refresh();
}

void Estado::setCenter(QString *c){
    qDebug() << "Setting Center";
    *this->center = *c;
    refresh();
}

void Estado::setDisplay(QString *d){
    qDebug() << "Setting Display";
    *this->display = *d;
    refresh();
}

void Estado::setICM(QString * i){
    qDebug() << "Setting ICM";
    *this->icm = *i;
    refresh();
}

QString Estado::getRange(){return *range;}
QString Estado::getLabel(){return *label;}
QString Estado::getQEK(){return *qek;}
QString Estado::getThreat(){return *threat;}
QString Estado::getCenter(){return *center;}
QString Estado::getDisplay(){return *display;}
QString Estado::getICM(){return *icm;}
QString Estado::getModos(){return *display_mode;}
QString Estado::getQekIzq(){return *qek;}
QString Estado::getQekDer(){return *qek;}

void Estado::refresh()
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

    qDebug() << "---------------------- " << formattedTime << " -----------------------";
    qDebug() << "\nRange Scale:\t " << *range
             << "\nLabel Selection:\t " << *label
             << "\nQEK:\t\t " << *qek
             << "\nThreat Assesment:\t " << *threat
             << "\nCenter:\t\t " << *center
             << "\nDisplay:\t\t " << *display
             << "\nICM:\t\t " << *icm;
}
