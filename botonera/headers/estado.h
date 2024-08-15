#ifndef ESTADO_H
#define ESTADO_H

#include "iestado.h"

/**
 * @brief The Estado class
 *
 * En esta clase se recibe el estado de cada zona para luego formar el mensaje
 * En esta clase ejerce el astado actual de los botones que estan presionados
 */


class Botonera;
class Estado : public IEstado
{
public:
    Estado(Botonera *b);
    void setOverlay(QString codigo) override;

    void removeIcm(QString boton) override;
    void removeCenter(QString boton) override;
    void removeDisplayMode(QString boton) override;
    void removeDisplaySelection(QString boton) override;
    void removeLabel(QString boton) override;
    void removeQek(QString boton) override;
    void removeRange(QString boton) override;
    void removeThreat(QString boton) override;

    QString getRange() override;
    QString getLabel() override;
    QString getQEK() override;
    QString getThreat() override;
    QString getCenter() override;
    QString getDisplayMode() override;
    QString getDisplaySelection() override;
    QString getICM() override;
    QString getQekIzq() override;
    QString getQekDer() override;
    QString getModos() override;
    QString getOverlay() override;

    void setRange(QString *r) override;
    void setLabel(QString *l) override;
    void setQEK(QString *q) override;
    void setThreat(QString *t) override;
    void setCenter(QString *c) override;
    void setDisplayMode(QString *d) override;
    void setDisplaySelection(QString *d) override;
    void setICM(QString *i) override;


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
