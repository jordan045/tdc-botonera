#ifndef THREAT_H
#define THREAT_H

#include "Zone.h"
#include <QWidget>

class botonera;
class threat : public Zone
{

public:
    explicit threat(botonera *b);
    void sendCode(QString code) override;

private:
    botonera *miBotonera;
};

#endif // THREAT_H
