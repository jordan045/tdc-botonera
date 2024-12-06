#ifndef BOTONERA_H
#define BOTONERA_H

#include "estado.h"
#include <QWidget>
#include "infopanel.h"
#include "qdialog.h"
#include "qpushbutton.h"
#include "qshortcut.h"
#include "formatconcentrator.h"
#include "zone_center.h"
#include "zone_icm.h"
#include "zone_label.h"
#include "zone_range.h"
#include "zone_threat.h"
#include "zone_displayselection.h"
#include "zone_displaymode.h"

class Qek;
class Botonera : public QWidget
{
    Q_OBJECT
public:
    explicit Botonera(QWidget *parent = nullptr);

    virtual void setOverlay(QString codigo)                 = 0;
    virtual void sendCodeToRange(QString boton)             = 0;
    virtual void sendCodeToLabelSelection(QString boton)    = 0;
    virtual void sendCodeToQek(QString boton)               = 0;
    virtual void sendCodeToThreat(QString boton)            = 0;
    virtual void sendCodeToCenter(QString boton)            = 0;
    virtual void sendCodeToDisplayMode(QString boton)       = 0;
    virtual void sendCodeToDisplaySelection(QString boton)  = 0;
    virtual void sendCodeToIcm(QString boton)               = 0;
    virtual void sendCharToMIK(QString c)                   = 0;

    virtual void removeCodeFromRange(QString boton)             = 0;
    virtual void removeCodeFromLabelSelection(QString boton)    = 0;
    virtual void removeCodeFromQek(QString boton)               = 0;
    virtual void removeCodeFromThreat(QString boton)            = 0;
    virtual void removeCodeFromCenter(QString boton)            = 0;
    virtual void removeCodeFromDisplayMode(QString boton)       = 0;
    virtual void removeCodeFromDisplaySelection(QString boton)  = 0;
    virtual void removeCodeFromIcm(QString boton)               = 0;

public slots:
    void start(int tipo);
    void info();

protected:
    int overlay;
    zone_range *range_widget;
    zone_label *label_selection_widget;
    Qek *qek_widget;
    zone_threat *threat_assesment_widget;
    zone_displayMode *display_mode_widget;
    zone_displaySelection *display_selection_widget;
    zone_center *center_widget;
    zone_icm *icm_widget;
    FormatConcentrator *concentrator;
    QShortcut *shortcut;
    Estado *miEstado;
    QPushButton *help_button = new QPushButton("");
    void crearBotonHelp();
    void distribucionLayout();

    infoPanel *infoP;

};

#endif // BOTONERA_H
