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

void Estado::setEstado(Zone *z,QString *codigo){
    QString nombreZona = z->getName();
    codigo->append(" ");
    if (nombreZona == "Threat") {
        qDebug() << "Setting Threat";
        qDebug()<<"se llamo a setEstado";
        this->threat.append(*codigo);
    }  if (nombreZona == "Center") {
        qDebug() << "Setting Center";
        codigo->append(" ");
        this->center.append(*codigo);
    }  if (nombreZona == "DisplayMode") {
        qDebug() << "Setting DisplayMode" << *codigo;
        this->displayMode.append(*codigo);
    }  if (nombreZona == "DisplaySelection") {
        qDebug() << "Setting DisplaySelection";
        this->displaySelection.append(*codigo);
    }   if (nombreZona == "ICM") {
        qDebug() << "Setting ICM";
        this->icm.append(*codigo);
    }  if (nombreZona == "Label") {
        qDebug() << "Setting Label";
        this->label.append(*codigo);
    }  if (nombreZona == "QEK") {
        qDebug() << "Setting QEK";
        this->qek.append(*codigo);
    }  if (nombreZona == "Range") {
        qDebug() << "Setting Range";
        this->range.append(*codigo);
    }
    refresh();
}


void Estado::setOverlay(QString codigo){
    overlay = codigo;
    qDebug()<<"Set overlay en estado"<<overlay;
}

void Estado::removeEstado(Zone *z, QString *codigo){
    QString nombreZona = z->getName();
    codigo->append(" ");
    if (nombreZona == "Threat") {
        qDebug() << "Removing Threat";
        this->threat.remove(*codigo);
    }  if (nombreZona == "Center") {
        qDebug() << "Removing Center";
        codigo->append(" ");
        this->center.remove(*codigo);
    }  if (nombreZona == "DisplayMode") {
        qDebug() << "Removing DisplayMode" << *codigo;
        this->displayMode.remove(*codigo);
    }  if (nombreZona == "DisplaySelection") {
        qDebug() << "Removing DisplaySelection";
        this->displaySelection.remove(*codigo);
    }   if (nombreZona == "ICM") {
        qDebug() << "Removing ICM";
        this->icm.remove(*codigo);
    }  if (nombreZona == "Label") {
        qDebug() << "Removing Label";
        this->label.remove(*codigo);
    }  if (nombreZona == "QEK") {
        qDebug() << "Removing QEK";
        this->qek.remove(*codigo);
    }  if (nombreZona == "Range") {
        qDebug() << "Removing Range";
        this->range.remove(*codigo);
    }
    refresh();
}

/*
void Estado::removeEstado(Icm *z, QString *codigo){
    Q_UNUSED(z);
    codigo->append(" ");
    this->icm.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Center *z, QString *codigo){
    Q_UNUSED(z);
    codigo->append(" ");
    this->center.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Threat *z, QString *codigo){
    Q_UNUSED(z);
    codigo->append(" ");
    this->threat.remove(*codigo);
    refresh();
}
void Estado::removeEstado(DisplayMode *z, QString *codigo){
    Q_UNUSED(z);
    qDebug() << "Borramos" << *codigo;
    codigo->append(" ");
    this->displayMode.remove(*codigo);
    refresh();
}
void Estado::removeEstado(DisplaySelection *z, QString *codigo){
    Q_UNUSED(z);
    codigo->append(" ");
    this->displaySelection.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Label *z, QString *codigo){
    Q_UNUSED(z);
    codigo->append(" ");
    this->label.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Qek *z, QString *codigo){
    Q_UNUSED(z);
    codigo->append(" ");
    this->qek.remove(*codigo);
    refresh();
}
void Estado::removeEstado(Range *z, QString *codigo){
    Q_UNUSED(z);
    codigo->append(" ");
    this->range.remove(*codigo);
    refresh();
}

*/
QString Estado::getLabel(){return label;}
QString Estado::getQEK(){return qek;}
QString Estado::getThreat(){return threat;}
QString Estado::getCenter(){return center;}
QString Estado::getDisplayMode(){return displayMode;}
QString Estado::getICM(){return icm;}
QString Estado::getModos(){return displayMode;}
QString Estado::getOverlay(){return overlay;}
QString Estado::getQekIzq(){return qek;}
QString Estado::getQekDer(){return qek;}
QString Estado::getDisplaySelection(){return displaySelection;}
QString Estado::getRange(){return range;}


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
