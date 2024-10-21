#ifndef IESTADO_H
#define IESTADO_H

#include "qwidget.h"
#include <QString>
#include "Zone.h"

/**
 * @brief The IEstado abstract class
 *
 *  Clase abstracta definida sobre clase Estado.
 *  Requerida para lograr el correcto aislamiento sobre
 *  la clase FormatConcentrator.
 *
 */

class IEstado : public QWidget
{
public:
    virtual void setOverlay(QString codigo) = 0;

    virtual void removeIcm(QString boton) = 0;
    virtual void removeCenter(QString boton) = 0;
    virtual void removeDisplayMode(QString boton) = 0;
    virtual void removeDisplaySelection(QString boton) = 0;
    virtual void removeLabel(QString boton) = 0;
    virtual void removeQek(QString boton) = 0;
    virtual void removeRange(QString boton) = 0;
    virtual void removeThreat(QString boton) = 0;

    virtual QString getRange() = 0;
    virtual QString getLabel() = 0;
    virtual QString getQEK() = 0;
    virtual QString getThreat() = 0;
    virtual QString getCenter() = 0;
    virtual QString getDisplayMode() = 0;
    virtual QString getDisplaySelection() = 0;
    virtual QString getICM() = 0;
    virtual QString getModos() = 0;
    virtual QString getOverlay() = 0;
    virtual QString getMIK() = 0;
    virtual QString getLabelS()        = 0;
    virtual QString getQEKS()          = 0;
    virtual QString getCenterS()       = 0;
    virtual QString getICMS()          = 0;
    virtual QString getDisplayModeS()  = 0;
    virtual QString getOverlayS()      = 0;


    virtual void setRange(QString r) = 0;
    virtual void setLabel(QString l) = 0;
    virtual void setQEK(QString q) = 0;
    virtual void setThreat(QString t) = 0;
    virtual void setCenter(QString c) = 0;
    virtual void setDisplayMode(QString d) = 0;
    virtual void setDisplaySelection(QString d) = 0;
    virtual void setICM(QString i) = 0;
    virtual void setLabelS(QString l)      = 0;
    virtual void setQEKS(QString q)        = 0;
    virtual void setCenterS(QString c)     = 0;
    virtual void setICMS(QString i)        = 0;
    virtual void setDisplayModeS(QString d)= 0;
    virtual void setOverlayS(QString o)    = 0;

};

#endif // IESTADO_H
