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
}

void StubEstado::setOverlay(QString codigo){
    this->overlay = codigo;
}

void StubEstado::removeIcm(QString codigo){
    this->icm = "";
}

void StubEstado::removeCenter(QString codigo){
    this->center = "";
}

void StubEstado::removeThreat(QString codigo){
    this->threat = "";
}

void StubEstado::removeDisplayMode(QString codigo){
    this->displayMode = "";
}

void StubEstado::removeDisplaySelection(QString codigo){
    this->displaySelection = "";
}

void StubEstado::removeLabel(QString codigo){
    this->label = "";
}

void StubEstado::removeQek(QString codigo){
    this->qek = "";
}

void StubEstado::removeRange(QString codigo){
    this->range = "";
}

QString StubEstado::getLabel(){             return label;}
QString StubEstado::getQEK(){               return qek;}
QString StubEstado::getThreat(){            return threat;}
QString StubEstado::getCenter(){            return center;}
QString StubEstado::getDisplayMode(){       return displayMode;}
QString StubEstado::getICM(){               return icm;}
QString StubEstado::getModos(){             return displayMode;}
QString StubEstado::getOverlay(){           return overlay;}
QString StubEstado::getQekIzq(){            return qek;}
QString StubEstado::getQekDer(){            return qek;}
QString StubEstado::getDisplaySelection(){  return displaySelection;}
QString StubEstado::getRange(){             return range;}

void StubEstado::setLabel(QString s){
    this->label = s;
}

void StubEstado::setQEK(QString s){
    this->qek = "";
}

void StubEstado::setThreat(QString s){
    this->threat = s;
}

void StubEstado::setCenter(QString s){
    this->center = s;
}

void StubEstado::setDisplayMode(QString s){
    this->displayMode = s;
}

void StubEstado::setICM(QString s){
    this->icm = s;
}

void StubEstado::setDisplaySelection(QString s){
    this->displaySelection = s;
}

void StubEstado::setRange(QString s){
    this->range = s;
}