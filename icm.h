#ifndef ICM_H
#define ICM_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class Icm : public Zone
{
public:
    explicit Icm(botonera *b);
    void sendCode(QString code) override;

private:
    Botonera *miBotonera;
};

#endif // ICM_H
