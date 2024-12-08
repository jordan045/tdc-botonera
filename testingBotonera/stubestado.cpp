#include "stubestado.h"

StubEstado::StubEstado(){
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

void StubEstado::setOverlay(QString codigo){
    this->overlay = codigo;
}

void StubEstado::removeIcm(QString boton){
    this->icm = "";
}

void StubEstado::removeCenter(QString boton){
    this->center = "";
}

void StubEstado::removeDisplayMode(QString boton){
    this->displayMode = "";
}

void StubEstado::removeDisplaySelection(QString boton){
    this->displaySelection = "";
}

void StubEstado::removeLabel(QString boton){
    this->label = "";
}

void StubEstado::removeQek(QString boton){
    this->qek = "";
}

void StubEstado::removeRange(QString boton){
    this->range = "";
}

void StubEstado::removeThreat(QString boton){
    this->threat = "";
}

void StubEstado::removeMIK(QString c){
    this->mik = "";
}

void StubEstado::removeLabelS(QString l){
    this->labelS = "";
}

void StubEstado::removeQEKS(QString q){
    this->qekS = "";
}

void StubEstado::removeCenterS(QString c){
    this->centerS = "";
}

void StubEstado::removeICMS(QString i){
    this->icmS = "";
}

void StubEstado::removeDisplayModeS(QString d){
    this->displayModeS = "";
}

void StubEstado::removeOverlayS(QString o){
    this->displayModeS = "";
}

QString StubEstado::getRange(){             return range;}
QString StubEstado::getLabel(){             return label;}
QString StubEstado::getQEK(){               return qek;}
QString StubEstado::getThreat(){            return threat;}
QString StubEstado::getCenter(){            return center;}
QString StubEstado::getDisplayMode(){       return displayMode;}
QString StubEstado::getDisplaySelection(){  return displaySelection;}
QString StubEstado::getICM(){               return icm;}
QString StubEstado::getModos(){             return displayMode;}
QString StubEstado::getOverlay(){           return overlay;}
QString StubEstado::getMIK(){               return mik;}

QString StubEstado::getLabelS(){            return labelS;}
QString StubEstado::getQEKS(){              return qekS;}
QString StubEstado::getCenterS(){           return centerS;}
QString StubEstado::getICMS(){              return icmS;}
QString StubEstado::getDisplayModeS(){      return displayModeS;}
QString StubEstado::getOverlayS(){          return overlayS;}

void StubEstado::setRange(QString r){
    this->range = s;
}

void StubEstado::setLabel(QString l){
    this->label = s;
}

void StubEstado::setQEK(QString q){
    this->qek = s;
}

void StubEstado::setThreat(QString t){
    this->threat = s;
}

void StubEstado::setCenter(QString c){
    this->center = s;
}

void StubEstado::setDisplayMode(QString d){
    this->displayMode = s;
}

void StubEstado::setDisplaySelection(QString d){
    this->displaySelection = s;
}

void StubEstado::setICM(QString i){
    this->icm = s;
}

void StubEstado::setMIK(QString m){
    this->mik = m;
}

void StubEstado::setLabelS(QString l){
    this->labelS = l;
}

void StubEstado::setQEKS(QString q){
    this->qekS = q;
}

void StubEstado::setCenterS(QString c){
    this->centerS = c;
}

void StubEstado::setICMS(QString i){
    this->icmS = i;
}

void StubEstado::setDisplayModeS(QString d){
    this->displayModeS = d;
}

void StubEstado::setOverlayS(QString o){
    this->overlayS = o;
}
