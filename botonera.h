#ifndef BOTONERA_H
#define BOTONERA_H

#include "estado.h"
#include <QWidget>
#include "range.h"
#include "icm.h"
#include "label.h"
#include "Zone.h"
#include "qek.h"
#include "threat.h"
#include "center.h"
#include "display_mode.h"
#include "display_selection.h"
#include "formatconcentrator.h"

class Botonera : public QWidget
{
    Q_OBJECT
public:
   explicit Botonera(QWidget *parent = nullptr);
    void setmodo(int i);
    void sendCodeToEstado(Center *z, QString *boton);
    void sendCodeToEstado(DisplayMode *z, QString *boton);
    void sendCodeToEstado(DisplaySelection *z, QString *boton);
    void sendCodeToEstado(Icm *z, QString *boton);
    void sendCodeToEstado(Label *z, QString *boton);
    void sendCodeToEstado(Qek *z, QString *boton);
    void sendCodeToEstado(Range *z, QString *boton);
    void sendCodeToEstado(Threat *z, QString *boton);
    void sendMessage();
public slots:
   void start();

   private:
   Range *range_widget;
   Label *label_selection_widget;
   Qek *qek_widget;
   Threat *threat_assesment_widget;
   Center *center_widget;
   DisplayMode *display_mode_widget;
   DisplaySelection *display_selection_widget;
   Icm *icm_widget;
   FormatConcentrator *concentrator;

   Estado *miEstado;
   int modo;
};

#endif // BOTONERA_H
