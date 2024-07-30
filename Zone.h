#ifndef ZONE_H
#define ZONE_H

#include "qwidget.h"
#include <QObject>
#include <QString>
#include <QtCore>

class Zone : public QWidget{

public:
    virtual void sendCode(QString code){}
    virtual void removeCode(QString code){}
    virtual void sendMessage(){}
    virtual QString getName(){}
};

#endif // ZONE_H
