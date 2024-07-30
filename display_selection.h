#ifndef DISPLAY_SELECTION_H
#define DISPLAY_SELECTION_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class DisplaySelection : public Zone
{

public:
    explicit DisplaySelection(Botonera *b);
    void sendCode(QString code) override;
    void sendMessage();
    QString getName() override;

private:
    Botonera *miBotonera;
};

#endif // DISPLAY_SELECTION_H
