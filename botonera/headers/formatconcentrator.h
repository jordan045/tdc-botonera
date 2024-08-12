#ifndef FORMATCONCENTRATOR_H
#define FORMATCONCENTRATOR_H
#include "estado.h"
#include <QBitArray>
#include <QJsonObject>

/*
 * Esta clase lee el contenido de la clase Estado y genera las 9 palabras de 24 bits
 * con el formato del Concentrator (ver Contenido de MensajesTMIO v0.3)
 */
class FormatConcentrator
{

public:
    FormatConcentrator();
    QBitArray* getMessage(Estado *estadoActual);

private:
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

    void setMessage(Estado *estado);

    /*
    void setWord1(Estado *estado);
    void setWord2(Estado *estado);
    void setWord3(Estado *estado);
    void setWord4(Estado *estado);
    void setWord5(Estado *estado);
    void setWord6(Estado *estado);
    void setWord7(Estado *estado);
    void setWord8(Estado *estado);
    void setWord9(Estado *estado);

    void juntar();

    */

    void setRange(Estado *estado);
    void setCenter(Estado *estado);
    void setICM(Estado *estado);
    void setLabel(Estado *estado);
    void setQEK(Estado *estado);
    void setThreat(Estado *estado);
    void setDisplayMode(Estado *estado);
    void setDisplaySelection(Estado *estado);
    void setOverlay(Estado *estado);

    void guardarMensaje(Estado *estado);

    void getMessage();

    void leerJson();

    QJsonObject archivo;
};


#endif // FORMATCONCENTRATOR_H
