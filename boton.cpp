#include "boton.h"

Boton::Boton(Zone *z, QString codigo, QObject *parent): QObject(parent) {
    this->codigo = codigo;
    this->zona = z;
    this->state = false;
}

QString Boton::getCodigo(){
    return codigo;
}

void Boton::setCodigo(QString n){
    codigo = n;
}

void Boton::sendMessage(){
    qDebug()<<"me active en boton";
    this->zona->sendMessage();
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
