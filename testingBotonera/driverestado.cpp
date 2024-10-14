#include "driverestado.h"

DriverEstado::DriverEstado(){
    this->range             = *new QString("");
    this->label             = *new QString("");
    this->qek               = *new QString("");
    this->threat            = *new QString("");
    this->center            = *new QString("");
    this->icm               = *new QString("");
    this->displayMode       = *new QString("");
    this->displaySelection  = *new QString("");
    this->labelS            = *new QString("");
    this->qekS              = *new QString("");
    this->centerS           = *new QString("");
    this->icmS              = *new QString("");
    this->displayModeS      = *new QString("");
    this->overlayS          = *new QString("");
}

void DriverEstado::setOverlay(QString codigo){
    this->overlay = codigo;
}

void DriverEstado::removeIcm(QString codigo){
    this->icm = "";
}

void DriverEstado::removeCenter(QString codigo){
    this->center = "";
}

void DriverEstado::removeThreat(QString codigo){
    this->threat = "";
}

void DriverEstado::removeDisplayMode(QString codigo){
    this->displayMode = "";
}

void DriverEstado::removeDisplaySelection(QString codigo){
    this->displaySelection = "";
}

void DriverEstado::removeLabel(QString codigo){
    this->label = "";
}

void DriverEstado::removeQek(QString codigo){
    this->qek = "";
}

void DriverEstado::removeRange(QString codigo){
    this->range = "";
}

QString DriverEstado::getLabel(){             return label;}
QString DriverEstado::getQEK(){               return qek;}
QString DriverEstado::getThreat(){            return threat;}
QString DriverEstado::getCenter(){            return center;}
QString DriverEstado::getDisplayMode(){       return displayMode;}
QString DriverEstado::getICM(){               return icm;}
QString DriverEstado::getModos(){             return displayMode;}
QString DriverEstado::getOverlay(){           return overlay;}
QString DriverEstado::getDisplaySelection(){  return displaySelection;}
QString DriverEstado::getRange(){             return range;}

QString DriverEstado::getLabelS(){            return labelS;}
QString DriverEstado::getQEKS(){              return qekS;}
QString DriverEstado::getCenterS(){           return centerS;}
QString DriverEstado::getICMS(){              return icmS;}
QString DriverEstado::getDisplayModeS(){      return displayModeS;}
QString DriverEstado::getOverlayS(){          return overlayS;}

void DriverEstado::setLabel(QString s){
    this->label = s;
}

void DriverEstado::setQEK(QString s){
    this->qek = s;
}

void DriverEstado::setThreat(QString s){
    this->threat = s;
}

void DriverEstado::setCenter(QString s){
    this->center = s;
}

void DriverEstado::setDisplayMode(QString s){
    this->displayMode = s;
}

void DriverEstado::setICM(QString s){
    this->icm = s;
}

void DriverEstado::setLabelS(QString l){
    this->labelS = l;
}

void DriverEstado::setQEKS(QString q){
    this->qekS = q;
}

void DriverEstado::setCenterS(QString c){
    this->centerS = c;
}

void DriverEstado::setICMS(QString i){
    this->icmS = i;
}

void DriverEstado::setDisplayModeS(QString d){
    this->displayModeS = d;
}

void DriverEstado::setOverlayS(QString o){
    this->overlayS = o;
}

void DriverEstado::setDisplaySelection(QString s){
    this->displaySelection = s;
}

void DriverEstado::setRange(QString s){
    this->range = s;
}
