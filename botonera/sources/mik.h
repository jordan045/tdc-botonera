#ifndef MIK_H
#define MIK_H

#include "botonera.h"
#include <QObject>

class MIK
{
public:
    MIK(Botonera *b);
    void selectLine(int t);
    void pressKey(QChar c);
    void releaseKey(QChar c);

private:
    Botonera *miBotonera;
    QJsonObject teclasObj;
    int tab;

};

#endif // MIK_H
