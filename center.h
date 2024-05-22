#ifndef CENTER_H
#define CENTER_H

#include "Zone.h"
#include <QWidget>

class botonera;
class center : public Zone
{

public:
    explicit center(botonera *b);
    void sendCode(QString code) override;

private:
    botonera *miBotonera;
};

#endif // CENTER_H
