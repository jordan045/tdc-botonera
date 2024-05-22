#ifndef LABEL_H
#define LABEL_H

#include "Zone.h"
#include <QWidget>

class botonera;
class label :public Zone
{

public:
    explicit label(botonera *b);
    void sendCode(QString code) override;

private:
    botonera *miBotonera;
};

#endif // LABEL_H
