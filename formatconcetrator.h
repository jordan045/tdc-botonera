#ifndef FORMATCONCETRATOR_H
#define FORMATCONCETRATOR_H

#include "estado.h"
#include <QBitArray>

class formatConcetrator
{
public:
    formatConcetrator();
    QBitArray* getMessage(estado estadoActual);

private:
    estado    *miEstado;
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

    QJsonObject json;
};


#endif // FORMATCONCETRATOR_H
