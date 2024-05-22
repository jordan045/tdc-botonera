#ifndef DISPLAY_SELECTION_H
#define DISPLAY_SELECTION_H

#include "Zone.h"
#include <QWidget>

class botonera;
class Display_selection : public Zone
{

public:
    explicit Display_selection(botonera *b);
    void sendCode(QString code) override;

private:
    botonera *miBotonera;
};

#endif // DISPLAY_SELECTION_H
