#ifndef LABEL_H
#define LABEL_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class Label :public Zone
{

public:
    explicit Label(Botonera *b);
    void sendCode(QString code) override;
    void sendMessage();

private:
    Botonera *miBotonera;
};

#endif // LABEL_H
