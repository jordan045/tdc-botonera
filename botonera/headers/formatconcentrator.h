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

    void removeCenter(QString estado);
    void removeThreat(QString estado);
    void removeDisplayMode(QString estado);
    void removeDisplaySelection(QString estado);
    void removeQEK();


private:
    QBitArray *message;

    void setMessage(Estado *estado);

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
