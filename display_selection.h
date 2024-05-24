#ifndef DISPLAY_SELECTION_H
#define DISPLAY_SELECTION_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class Display_selection : public Zone
{

public:
    explicit Display_selection(Botonera *b);
    void sendCode(QString code) override;

private:
    Botonera *miBotonera;
};

#endif // DISPLAY_SELECTION_H
