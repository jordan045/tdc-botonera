#ifndef FORMATCONCETRATOR_H
#define FORMATCONCETRATOR_H

#include "estado.h"
#include <QBitArray>
#include <QJsonObject>

/*
 * Esta clase lee el contenido de la clase Estado y genera las 9 palabras de 24 bits
 * con el formato del Concentrator (ver Contenido de MensajesTMIO v0.3)
 */
class formatConcetrator
{

public:
    formatConcetrator();
    QBitArray* getMessage(Estado *estadoActual);

private:
    Estado    miEstado;
    QBitArray *message;
    QBitArray *word1;
    QBitArray *word2;
    QBitArray *word3;
    QBitArray *word4;
    QBitArray *word5;
    QBitArray *word6;
    QBitArray *word7;
    QBitArray *word8;
    QBitArray *word9;

    void setMessage();
    void setWord1();
    void setWord2();
    void setWord3();
    void setWord4();
    void setWord5();
    void setWord6();
    void setWord7();
    void setWord8();
    void setWord9();

    void leerJson();

    QJsonObject archivo;
};


#endif // FORMATCONCETRATOR_H
