#ifndef BOTONERA_H
#define BOTONERA_H

#include "estado.h"
#include <QWidget>
#include <range.h>
#include <icm.h>
#include <label.h>
#include <qek.h>
#include <threat.h>
#include <center.h>
#include <display_mode.h>
#include <display_selection.h>

class Botonera : public QWidget
{
    Q_OBJECT
public:
   explicit Botonera(QWidget *parent = nullptr);
    void setmodo(int i);
    void sendCodeToEstado(Center *z, QString *boton);
    void sendCodeToEstado(display_mode *z, QString *boton);
    void sendCodeToEstado(Display_selection *z, QString *boton);
    void sendCodeToEstado(icm *z, QString *boton);
    void sendCodeToEstado(label *z, QString *boton);
    void sendCodeToEstado(qek *z, QString *boton);
    void sendCodeToEstado(range *z, QString *boton);
    void sendCodeToEstado(threat *z, QString *boton);

public slots:
   void start();

   private:
   Zone *range_widget;
   label *label_selection_widget;
   qek *qek_widget;
   threat *threat_assesment_widget;
   center *center_widget;
   display_mode *display_mode_widget;
   Display_selection *display_selection_widget;
   icm *icm_widget;

   Estado *miEstado;
   int modo;
};

#endif // BOTONERA_H
