#ifndef ESTADO_H
#define ESTADO_H

#include "qwidget.h"
#include <QString>
/**
 * @brief The Estado class
 *
 * En esta clase se recibe el estado de cada zona para luego formar el mensaje
 * En esta clase ejerce el astado actual de los botones que estan presionados
 */

class botonera;
class Estado : public QWidget
{
public:
    Estado(botonera *b);
    void setEstado();

    void setRange(QString *r);
    void setLabel(QString *l);
    void setQEK(QString *q);
    void setThreat(QString *t);
    void setCenter(QString *c);
    void setDisplay(QString *d);
    void setICM(QString *i);

    QString getRange();
    QString getLabel();
    QString getQEK();
    QString getThreat();
    QString getCenter();
    QString getDisplay();
    QString getICM();

private:
    botonera *miBotonera;

    QString getInstance();
    //int getEstado();
    QString *range;
    QString *label;
    QString *qek;
    QString *threat;
    QString *center;
    QString *display;
    QString *icm;

    void refresh();

};

#endif // ESTADO_H
