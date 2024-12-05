#include "estado.h"
#include <QDebug>

Estado::Estado(Botonera *b)
{
    miBotonera = b;

    this->range             = *new QString("");
    this->label             = *new QString("");
    this->qek               = *new QString("");
    this->threat            = *new QString("");
    this->center            = *new QString("");
    this->icm               = *new QString("");
    this->displayMode       = *new QString("");
    this->displaySelection  = *new QString("");
    this->mik               = *new QString("");
    this->labelS            = *new QString("");
    this->qekS              = *new QString("");
    this->centerS           = *new QString("");
    this->icmS              = *new QString("");
    this->displayModeS      = *new QString("");
    this->overlayS          = *new QString("");
}

void Estado::setOverlay(QString codigo){
    overlay = codigo;
}

void Estado::removeIcm(QString codigo){
    codigo.append(" ");
    this->icm.remove(codigo);
    refresh();
}
void Estado::removeCenter( QString codigo){
    codigo.append(" ");
    this->center.remove(codigo);
    refresh();
}
void Estado::removeThreat(QString codigo){
    codigo.append(" ");
    this->threat.remove(codigo);
    refresh();
}
void Estado::removeMIK(QString c){
    this->mik.clear();
    refresh();
}

void Estado::removeLabelS(QString codigo)
{
    codigo.append("");
    this->labelS.remove(codigo);
    refresh();
}

void Estado::removeQEKS(QString codigo){
    codigo.append("");
    this->qekS.remove(codigo);
    refresh();
}

void Estado::removeCenterS(QString codigo){
    codigo.append("");
    this->centerS.remove(codigo);
    refresh();
}

void Estado::removeICMS(QString codigo){
    codigo.append("");
    this->icmS.remove(codigo);
    refresh();
}

void Estado::removeDisplayModeS(QString codigo){
    codigo.append("");
    this->displayModeS.remove(codigo);
    refresh();
}

void Estado::removeOverlayS(QString codigo){
    codigo.append("");
    this->overlayS.remove(codigo);
    refresh();
}

void Estado::removeDisplayMode(QString codigo){
    codigo.append(" ");
    this->displayMode.remove(codigo);
    refresh();
}
void Estado::removeDisplaySelection(QString codigo){
    QStringList estado = this->displaySelection.split(" ", Qt::SkipEmptyParts);
    if (estado.contains(codigo))
        estado.removeAll(codigo);
    this->displaySelection = estado.join(" ");
    refresh();
}
void Estado::removeLabel(QString codigo){
    codigo.append(" ");
    this->label.remove(codigo);
    refresh();
}
void Estado::removeQek(QString codigo){
    codigo.append(" ");
    this->qek.remove(codigo);
    refresh();
}
void Estado::removeRange(QString codigo){
    codigo.append(" ");
    this->range.remove(codigo);
    refresh();
}

QString Estado::getLabel(){             return label;}
QString Estado::getQEK(){               return qek;}
QString Estado::getThreat(){            return threat;}
QString Estado::getCenter(){            return center;}
QString Estado::getDisplayMode(){       return displayMode;}
QString Estado::getICM(){               return icm;}
QString Estado::getModos(){             return displayMode;}
QString Estado::getOverlay(){           return overlay;}


QString Estado::getMIK(){
    mik = mik.trimmed(); // Elimina espacios en blanco al inicio y al final

    int index = mik.indexOf(' ');
    QString token;

    if (index == -1) {
        // No hay espacios, es el último token
        token = mik;
        mik.clear();
    } else {
        token = mik.left(index);
        mik = mik.mid(index + 1);
    }
    // qDebug()<<"Llamé a getMIK()"<<token;
    return token;
}

QString Estado::getDisplaySelection(){  return displaySelection;}
QString Estado::getRange(){             return range;}
QString Estado::getLabelS()        {return labelS      ;}
QString Estado::getQEKS()          {return qekS        ;}
QString Estado::getCenterS()       {return centerS     ;}
QString Estado::getICMS()          {return icmS        ;}
QString Estado::getDisplayModeS()  {return displayModeS;}
QString Estado::getOverlayS()      {return overlayS    ;}

void Estado::setLabel(QString s){
    s.append(" ");
    this->label.append(s);
    refresh();
}
void Estado::setQEK(QString s){
    this->qek.append(s);
    this->qek.append(" ");
    refresh();
}
void Estado::setThreat(QString s){
    s.append(" ");
    this->threat.append(s);
    refresh();
}
void Estado::setCenter(QString s){
    s.append(" ");
    this->center.append(s);
    refresh();
}
void Estado::setDisplayMode(QString s){
    s.append(" ");
    this->displayMode.append(s);
    refresh();
}
void Estado::setICM(QString s){
    s.append(" ");
    this->icm.append(s);
    refresh();
}

void Estado::setMIK(QString s){
    this->mik.append(" ");
    // s.append(" ");
    this->mik.append(s);
    // qDebug()<<"agregue a" << s;
    // qDebug()<<"la mik es:" << mik;
    refresh();
}

void Estado::setLabelS(QString l)
{
    l.append(" ");
    this->labelS.append(l);
    refresh();
}

void Estado::setQEKS(QString q)
{
    q.append(" ");
    this->qekS.append(q);
    refresh();
}

void Estado::setCenterS(QString c)
{
    c.append(" ");
    this->centerS.append(c);
    refresh();
}

void Estado::setICMS(QString i)
{
    i.append(" ");
    this->icmS.append(i);
    refresh();
}

void Estado::setDisplayModeS(QString d)
{
    d.append(" ");
    this->displayModeS.append(d);
    refresh();
}

void Estado::setOverlayS(QString o)
{
    o.append(" ");
    this->overlayS.append(o);
    refresh();
}

void Estado::setDisplaySelection(QString s){
    if (!this->displaySelection.isEmpty() && !this->displaySelection.endsWith(" ")) {
        this->displaySelection.append(" ");
    }
    this->displaySelection.append(s);
    refresh();
}
void Estado::setRange(QString s){
    s.append(" ");
    this->range.append(s);
    refresh();
}

void Estado::refresh()
{
    // QDateTime date = QDateTime::currentDateTime();
    // QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");

    //  qDebug()        << "---------------------- " << formattedTime << " -----------------------";
    //  qDebug()        << "\nRange Scale:\t " << range
    //                  << "\nLabel Selection:\t " << label
    //                  << "\nQEK:\t\t " << qek
    //                  << "\nThreat Assesment:\t " << threat
    //                  << "\nCenter:\t\t " << center
    //                  << "\nDisplay Mode:\t " << displayMode
    //                  << "\nDisplay Selection:\t " << displaySelection
    //                  << "\nICM:\t\t " << icm
    //                  << "\nMIK:\t\t " << mik
    //                  << "\nSLAVE"
    //                  << "\nLabels Selection:\t " << labelS
    //                  << "\nQEKs:\t\t " << qekS
    //                  << "\nCenters:\t\t " << centerS
    //                  << "\nDisplay Mode:\t " << displayModeS
    //                  << "\nICM:\t\t " << icm
    //                  <<  "\nOverlayS \t\t"<< overlayS
    //                  << "\n";
}
