#ifndef MIK_H
#define MIK_H

#include "botonera.h"
#include <QObject>

#define SELECTABLE_LINES 13

class MIK
{
public:
    MIK(Botonera *b);
    void goToLine(int t);
    void pressKey(QString c);
    void releaseKey(QString c);
    int getActualLine();

private:
    Botonera *miBotonera;
    QJsonObject dataKeys;
    int actualLine;

};

#endif // MIK_H
