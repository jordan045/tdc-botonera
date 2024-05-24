#ifndef THREAT_H
#define THREAT_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class Threat : public Zone
{

public:
    explicit Threat(Botonera *b);
    void sendCode(QString code) override;

private:
    Botonera *miBotonera;
};

#endif // THREAT_H
