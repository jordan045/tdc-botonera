#ifndef ICM_H
#define ICM_H

#include "Zone.h"
#include <QWidget>

class botonera;
class icm : public Zone
{
public:
    explicit icm(botonera *b);
    void sendCode(QString code) override;

private:
    botonera *miBotonera;
};

#endif // ICM_H
