#ifndef STUBESTADO_H
#define STUBESTADO_H

#include "iestado.h"

/**
 * @brief StubEstado class
 *
 *  Sustituto de la clase Estado para la realización de las pruebas
 *  unitarias sobre FormatConcentrator.
 *
 */

class StubEstado : public IEstado
{
public:
    StubEstado();
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

    void setRange(QString r) override;
    void setLabel(QString l) override;
    void setQEK(QString q) override;
    void setThreat(QString t) override;
    void setCenter(QString c) override;
    void setDisplayMode(QString d) override;
    void setDisplaySelection(QString d) override;
    void setICM(QString i) override;

private:
    QString range;
    QString label;
    QString qek;
    QString threat;
    QString center;
    QString icm;
    QString displayMode;
    QString displaySelection;
    QString overlay;
};

#endif // STUBESTADO_H