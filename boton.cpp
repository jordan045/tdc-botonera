#include "boton.h"

Boton::Boton(QString codigo, QObject *parent): QObject(parent) {
    this->codigo = codigo;
    //connect(miBoton,&QRadioButton::clicked, this, &Boton::pressed);
}

QString Boton::getCodigo(){
    return codigo;
}

void Boton::setCodigo(QString n){
    codigo = n;
}

void Boton::pressed(){
    qDebug() << "Mi codigo es: " << this->codigo;
}
