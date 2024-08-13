#include "boton.h"

Boton::Boton(Zone *z, QString codigo, QObject *parent): QObject(parent) {
    this->codigo = codigo;
    this->zona = z;
    this->state = false;
}

void Boton::setState(bool state){
    this->state = state;
}

void Boton::interact(){
    if(!state){
        QString mensaje = *new QString(this->codigo);
        this->zona->sendCode(mensaje);
        this->zona->sendMessage();
    }
    else{
        QString mensaje = *new QString(this->codigo);
        this->zona->removeCode(mensaje);
    }
    state = !state;
}
