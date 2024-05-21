#ifndef BOTONERA_H
#define BOTONERA_H

#include <QWidget>
#include <range.h>
#include <icm.h>
#include <label.h>
#include <qek.h>
#include <threat.h>
#include <center.h>
#include <display_mode.h>
#include <display_selection.h>

class botonera : public QWidget
{
    Q_OBJECT
public:
   explicit botonera(QWidget *parent = nullptr);
    void setmodo(int i);

public slots:
   void iniciar();

   private:
   range *range_widget;
   label *label_selection_widget;
   qek *qek_widget;
   threat *threat_assesment_widget;
   center *center_widget;
   display_mode *display_mode_widget;
   Display_selection *display_selection_widget;
   icm *icm_widget;
   int modo;
};

#endif // BOTONERA_H
