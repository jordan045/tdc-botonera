#ifndef ESTADO_H
#define ESTADO_H

#include "qwidget.h"
#include <QString>
#include "Zone.h"
#include "range.h"
#include "center.h"
#include "display_mode.h"
#include "display_selection.h"
#include "threat.h"
#include "qek.h"
#include "label.h"
#include "icm.h"
/**
 * @brief The Estado class
 *
 * En esta clase se recibe el estado de cada zona para luego formar el mensaje
 * En esta clase ejerce el astado actual de los botones que estan presionados
 */


class Botonera;
class Estado : public QWidget
{
public:
    Estado(Botonera *b);
    void setOverlay(QString codigo);

    void removeIcm(QString *boton);
    void removeCenter(QString *boton);
    void removeDisplayMode(QString *boton);
    void removeDisplaySelection(QString *boton);
    void removeLabel(QString *boton);
    void removeQek(QString *boton);
    void removeRange(QString *boton);
    void removeThreat(QString *boton);

    QString getRange();
    QString getLabel();
    QString getQEK();
    QString getThreat();
    QString getCenter();
    QString getDisplayMode();
    QString getDisplaySelection();
    QString getICM();
    QString getQekIzq();
    QString getQekDer();
    QString getModos();
    QString getOverlay();

    void setRange(QString *r);
    void setLabel(QString *l);
    void setQEK(QString *q);
    void setThreat(QString *t);
    void setCenter(QString *c);
    void setDisplayMode(QString *d);
    void setDisplaySelection(QString *d);
    void setICM(QString *i);

private:
    Botonera *miBotonera;

    QString getInstance();
    //int getEstado();
    QString range;
    QString label;
    QString qek;
    QString threat;
    QString center;
    QString icm;
    QString displayMode;
    QString displaySelection;
    QString overlay;

    void refresh();

};

#endif // ESTADO_H
