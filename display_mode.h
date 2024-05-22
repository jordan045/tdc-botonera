#ifndef DISPLAY_MODE_H
#define DISPLAY_MODE_H

#include "Zone.h"
#include <QWidget>

class botonera;
class display_mode:public Zone
{

public:
   explicit display_mode(botonera *b);
   void sendCode(QString code) override;

private:
    botonera *miBotonera;
};

#endif // DISPLAY_MODE_H
