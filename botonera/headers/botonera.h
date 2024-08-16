#ifndef BOTONERA_H
#define BOTONERA_H

#include "estado.h"
#include <QWidget>
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

    void setOverlay(QString codigo);

    void removeCodeFromRange(QString boton);
    void removeCodeFromLabelSelection(QString boton);
    void removeCodeFromQek(QString boton);
    void removeCodeFromThreat(QString boton);
    void removeCodeFromCenter(QString boton);
    void removeCodeFromDisplayMode(QString boton);
    void removeCodeFromDisplaySelection(QString boton);
    void removeCodeFromIcm(QString boton);

    void sendCodeToRange(QString *boton);
    void sendCodeToLabelSelection(QString *boton);
    void sendCodeToQek(QString *boton);
    void sendCodeToThreat(QString *boton);
    void sendCodeToCenter(QString *boton);
    void sendCodeToDisplayMode(QString *boton);
    void sendCodeToDisplaySelection(QString *boton);
    void sendCodeToIcm(QString *boton);
    void sendMessage();
    QString getOverlay();
    
public slots:
    void start(int tipo);
    void infoMessage();

private:
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
};

#endif // BOTONERA_H
