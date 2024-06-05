#include "estado.h"
#include "qdatetime.h"
#include "qdebug.h"



Estado::Estado(Botonera *b) {

    miBotonera = b;

    this->range = new QString("");
    this->label = new QString("");
    this->qek  = new QString("");
    this->threat = new QString("");
    this->center = new QString("");
    this->display = new QString("");
    this->icm = new QString("");
    this->displayMode = new QString("");
    this->displaySelection = new QString("");
}

void Estado::setEstado(Range *rango,QString *codigo)
{
    qDebug() << "Setting Range";
    *this->range = *codigo;
    refresh();
}

void Estado::setEstado(Center *z, QString *codigo)
{
    qDebug() << "Setting Center";
    *this->center = *codigo;
    refresh();
}
void Estado::setEstado(DisplayMode *z, QString *codigo)
{
    qDebug() << "Setting Display";
    *this->displayMode= *codigo;
    refresh();
}
void Estado::setEstado(DisplaySelection *z, QString *codigo)
{
    qDebug() << "Setting DisplaySelection";
    *this->displaySelection = *codigo;
    refresh();
}
void Estado::setEstado(Icm *z, QString *codigo)
{
    qDebug() << "Setting ICM";
    *this->icm = *codigo;
    refresh();
}
void Estado::setEstado(Label *z, QString *codigo)
{
    qDebug() << "Setting Label";
    *this->label = *codigo;
    refresh();
}
void Estado::setEstado(Qek *z, QString *codigo)
{
    qDebug() << "Setting QEK";
    *this->qek = *codigo;
    refresh();
}
void Estado::setEstado(Threat *z, QString *codigo){
    qDebug() << "Setting Threat";
    *this->threat = *codigo;
    refresh();
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

void Estado::setDisplayMode(QString *d){
    qDebug() << "Setting Display";
    *this->displayMode= *d;
    refresh();
}
void Estado::setDisplaySelection(QString *d){
    qDebug() << "Setting DisplaySelection";
    *this->displaySelection = *d;
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
QString Estado::getDisplayMode(){return *displayMode;}
QString Estado::getICM(){return *icm;}
QString Estado::getModos(){return *displayMode;}
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
