#ifndef DISPLAY_MODE_H
#define DISPLAY_MODE_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class display_mode:public Zone
{

public:
   explicit display_mode(Botonera *b);
   void sendCode(QString code) override;

private:
    Botonera *miBotonera;
};

#endif // DISPLAY_MODE_H
