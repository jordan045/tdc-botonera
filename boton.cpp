#include "boton.h"

Boton::Boton(Zone *z, QString codigo, QObject *parent): QObject(parent) {
    this->codigo = codigo;
    this->zona = z;

}

QString Boton::getCodigo(){
    return codigo;
}

void Boton::setCodigo(QString n){
    codigo = n;
}

void Boton::pressed(){
    qDebug() << "Mi codigo es: " << this->codigo;
    this->zona->sendCode(this->codigo);
}
