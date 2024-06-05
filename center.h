#ifndef CENTER_H
#define CENTER_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class Center : public Zone
{

public:
    explicit Center(Botonera *b);
    void sendCode(QString code) override;
    void sendMessage();

private:
    Botonera *miBotonera;
};

#endif // CENTER_H
