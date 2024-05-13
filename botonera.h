#ifndef BOTONERA_H
#define BOTONERA_H

#include <QWidget>
#include <range.h>
#include <icm.h>
#include <label.h>
#include <qek.h>
#include <threat.h>
#include <center.h>
#include <display.h>

class botonera : public QWidget
{
    Q_OBJECT
public:
   explicit botonera(QWidget *parent = nullptr);
    void setmodo(int i);

public slots:
   void iniciar();

   private:
   range *r;
   label *l;
   qek *q;
   threat *t;
   center *c;
   display *d;
   icm *i;
   int modo;
};

#endif // BOTONERA_H
