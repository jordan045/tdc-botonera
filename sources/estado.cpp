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

void Estado::setOverlay(QString codigo){
    overlay = codigo;
    qDebug()<<"Set overlay en estado"<<overlay;
}

void Estado::removeIcm(QString *codigo){
    codigo->append(" ");
    this->icm.remove(*codigo);
    refresh();
}
void Estado::removeCenter( QString *codigo){
    codigo->append(" ");
    this->center.remove(*codigo);
    refresh();
}
void Estado::removeThreat(QString *codigo){
    codigo->append(" ");
    this->threat.remove(*codigo);
    refresh();
}
void Estado::removeDisplayMode(QString *codigo){
    qDebug() << "Borramos" << *codigo;
    codigo->append(" ");
    this->displayMode.remove(*codigo);
    refresh();
}
void Estado::removeDisplaySelection(QString *codigo){
    codigo->append(" ");
    this->displaySelection.remove(*codigo);
    refresh();
}
void Estado::removeLabel(QString *codigo){
    codigo->append(" ");
    this->label.remove(*codigo);
    refresh();
}
void Estado::removeQek(QString *codigo){
    codigo->append(" ");
    this->qek.remove(*codigo);
    refresh();
}
void Estado::removeRange(QString *codigo){
    codigo->append(" ");
    this->range.remove(*codigo);
    refresh();
}


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

void Estado::setLabel(QString *s){
    qDebug() <<"Setting Label";
    s->append(" ");
    this->label.append(*s);
    refresh();
}
void Estado::setQEK(QString *s){
    qDebug() << "Setting QEK";
    this->qek.append(*s);
    this->qek.append(" ");
    refresh();
}
void Estado::setThreat(QString *s){
    qDebug() << "Setting Threat";
    s->append(" ");
    this->threat.append(*s);
    refresh();
}
void Estado::setCenter(QString *s){
    qDebug() << "Setting Center";
    s->append(" ");
    this->center.append(*s);
    refresh();
}
void Estado::setDisplayMode(QString *s){
    qDebug() << "Setting Display Mode";
    s->append(" ");
    this->displayMode.append(*s);
    refresh();
}
void Estado::setICM(QString *s){
    qDebug() << "Setting ICM";
    s->append(" ");
    this->icm.append(*s);
    refresh();
}
void Estado::setDisplaySelection(QString *s){
    qDebug() << "Setting DisplaySelection";
    s->append(" ");
    this->displaySelection.append(*s);
    refresh();
}
void Estado::setRange(QString *s){
    qDebug() << "Setting RANGE";
    s->append(" ");
    this->range.append(*s);
    refresh();
}


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
