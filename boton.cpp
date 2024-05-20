#include "boton.h"

Boton::Boton(int codigo, QObject *parent): QObject(parent) {
    this->codigo = codigo;
    //connect(miBoton,&QRadioButton::clicked, this, &Boton::pressed);
}

int Boton::getCodigo(){
    return codigo;
}

void Boton::setCodigo(int n){
    codigo = n;
}

void Boton::pressed(){
    qDebug() << "Mi codigo es: " << this->codigo;
}
