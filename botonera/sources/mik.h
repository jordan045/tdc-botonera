#ifndef MIK_H
#define MIK_H

#include "botonera.h"
#include <QObject>

class MIK
{
public:
    MIK(Botonera *b);
    void selLinea(int t);
    void press(QChar c);
    void release(QChar c);

private:
    Botonera *miBotonera;
    QJsonObject teclasObj;
    int tab;

};

#endif // MIK_H
