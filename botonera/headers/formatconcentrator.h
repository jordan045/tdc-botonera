#ifndef FORMATCONCENTRATOR_H
#define FORMATCONCENTRATOR_H
//#include "estado.h"
#include <QBitArray>
#include <QJsonObject>
#include "iestado.h"

/*
 * Esta clase lee el contenido de la clase Estado y genera las 9 palabras de 24 bits
 * con el formato del Concentrator (ver Contenido de MensajesTMIO v0.3)
 */

class FormatConcentrator
{

public:
    FormatConcentrator();
    QBitArray* getMessage(IEstado *estadoActual);

    void removeCenter(QString estado);
    void removeThreat(QString estado);
    void removeDisplayMode(QString estado);
    void removeDisplaySelection(QString estado);
    void removeQEK();

    void removeCenterS(QString estado);
    void removeDisplayModeS(QString estado);
    void removeQEKS();


private:
    QBitArray *message;

    void setMessage(IEstado *estado);

    void setRange(IEstado *estado);
    void setCenter(IEstado *estado);
    void setICM(IEstado *estado);
    void setLabel(IEstado *estado);
    void setQEK(IEstado *estado);
    void setThreat(IEstado *estado);
    void setDisplayMode(IEstado *estado);
    void setDisplaySelection(IEstado *estado);
    void setOverlay(IEstado *estado);
    void setMIK(IEstado *estado);

    void setQekS(IEstado            *estado);
    void setCenterS(IEstado         *estado);
    void setIcmS(IEstado            *estado);
    void setDisplayModeS(IEstado    *estado);
    void setOverlayS(IEstado        *estado);

    void guardarMensaje(IEstado *estado);

    void getMessage();

    void leerJson();

    QJsonObject buttonJson;
    QJsonObject MIKJson;
};


#endif // FORMATCONCENTRATOR_H
