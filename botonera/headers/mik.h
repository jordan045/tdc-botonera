#ifndef MIK_H
#define MIK_H

#include "botonera.h"
#include <QObject>

class MIK
{
public:
    MIK(Botonera *b);
    void selectLine(int t);
    void pressKey(QString c);
    void releaseKey(QString c);
    int getTab();

private:
    Botonera *miBotonera;
    QJsonObject teclasObj;
    int tab;

};

#endif // MIK_H
