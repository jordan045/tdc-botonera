#include "estado.h"
#include "qdatetime.h"
#include "qdebug.h"



Estado::Estado(Botonera *b) {

    miBotonera = b;

    this->range             = *new QString("");
    this->label             = *new QString("");
    this->qek               = *new QString("");
    this->threat            = *new QString("");
    this->center            = *new QString("");
    this->icm               = *new QString("");
    this->displayMode       = *new QString("");
    this->displaySelection  = *new QString("");
}

void Estado::setEstado(Range *rango,QString *codigo){
    qDebug() << "Setting Range";
    codigo->append(" ");
    this->range.append(*codigo);
    refresh();
}
void Estado::setEstado(Center *z, QString *codigo)
{
    qDebug() << "Setting Center";
    codigo->append(" ");
    this->center.append(*codigo);
    refresh();
}
void Estado::setEstado(DisplayMode *z, QString *codigo)
{
    qDebug() << "Seteamos" << *codigo;
    codigo->append(" ");
    this->displayMode.append(*codigo);
    refresh();
}
void Estado::setEstado(DisplaySelection *z, QString *codigo)
{
    qDebug() << "Setting DisplaySelection";
    codigo->append(" ");
    this->displaySelection.append(*codigo);
    refresh();
}
void Estado::setEstado(Icm *z, QString *codigo)
{
    qDebug() << "Setting ICM";
    codigo->append(" ");
    this->icm.append(*codigo);
    refresh();
}
void Estado::setEstado(Label *z, QString *codigo)
{
    qDebug() << "Setting Label";
    codigo->append(" ");
    this->label.append(*codigo);
    refresh();
}
void Estado::setEstado(Qek *z, QString *codigo)
{
    codigo->append(" ");
    this->qek.append(*codigo);
    refresh();
}
void Estado::setEstado(Threat *z, QString *codigo){
    qDebug() << "Setting Threat";
    codigo->append(" ");
    this->threat.append(*codigo);
    refresh();
}

void Estado::removeEstado(Icm *z, QString *codigo){
    codigo->append(" ");
    this->icm.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Center *z, QString *codigo){
    codigo->append(" ");
    this->center.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Threat *z, QString *codigo){
    codigo->append(" ");
    this->threat.remove(*codigo);
    refresh();
}
void Estado::removeEstado(DisplayMode *z, QString *codigo){
    qDebug() << "Borramos" << *codigo;
    codigo->append(" ");
    this->displayMode.remove(*codigo);
    refresh();
}
void Estado::removeEstado(DisplaySelection *z, QString *codigo){
    codigo->append(" ");
    this->displaySelection.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Label *z, QString *codigo){
    codigo->append(" ");
    this->label.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Qek *z, QString *codigo){
    codigo->append(" ");
    this->qek.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Range *z, QString *codigo){
    codigo->append(" ");
    this->range.remove(*codigo);
    refresh();
}


QString Estado::getRange(){return range;}
QString Estado::getLabel(){return label;}
QString Estado::getQEK(){return qek;}
QString Estado::getThreat(){return threat;}
QString Estado::getCenter(){return center;}
QString Estado::getDisplayMode(){return displayMode;}
QString Estado::getICM(){return icm;}
QString Estado::getModos(){return displayMode;}
QString Estado::getQekIzq(){return qek;}
QString Estado::getQekDer(){return qek;}

void Estado::refresh()
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

    qDebug() << "---------------------- " << formattedTime << " -----------------------";
    qDebug() << "\nRange Scale:\t " << range
             << "\nLabel Selection:\t " << label
             << "\nQEK:\t\t " << qek
             << "\nThreat Assesment:\t " << threat
             << "\nCenter:\t\t " << center
             << "\nDisplay Mode:\t " << displayMode
             << "\nDisplay Selection:\t " << displaySelection
             << "\nICM:\t\t " << icm;
}
