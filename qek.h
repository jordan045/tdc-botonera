#ifndef QEK_H
#define QEK_H

#include "Zone.h"
#include <QWidget>

class botonera;
class qek : public Zone
{

public:
    explicit qek(botonera *b);
    void sendCode(QString code) override;

private:
    botonera *miBotonera;
};

#endif // QEK_H
