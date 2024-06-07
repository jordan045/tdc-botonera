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
    void setEstado(Zone *z, QString *Boton);
    void setEstado(Center *z, QString *boton);
    void setEstado(DisplayMode *z, QString *boton);
    void setEstado(DisplaySelection *z, QString *boton);
    void setEstado(Icm *z, QString *boton);
    void setEstado(Label *z, QString *boton);
    void setEstado(Qek *z, QString *boton);
    void setEstado(Range *z, QString *boton);
    void setEstado(Threat *z, QString *boton);

    void removeEstado(Icm *z, QString *boton);
    void removeEstado(Center *z, QString *boton);
    void removeEstado(DisplayMode *z, QString *boton);
    void removeEstado(DisplaySelection *z, QString *boton);
    void removeEstado(Label *z, QString *boton);
    void removeEstado(Qek *z, QString *boton);
    void removeEstado(Range *z, QString *boton);
    void removeEstado(Threat *z, QString *boton);


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

private:
    Botonera *miBotonera;

    QString getInstance();
    //int getEstado();
    QString range;
    QString label;
    QString qek;
    QString threat;
    QString center;
    QString display;
    QString icm;
    QString displayMode;
    QString displaySelection;

    void setRange(QString *r);
    void setLabel(QString *l);
    void setQEK(QString *q);
    void setThreat(QString *t);
    void setCenter(QString *c);
    void setDisplayMode(QString *d);
    void setDisplaySelection(QString *d);
    void setICM(QString *i);

    void refresh();

};

#endif // ESTADO_H
