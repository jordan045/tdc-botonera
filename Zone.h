#ifndef ZONE_H
#define ZONE_H

#include "qwidget.h"
#include <QObject>
#include <QString>
#include <QtCore>

class Zone : public QWidget{

    public:
        virtual void sendCode(QString){}
        virtual void removeCode(QString){}
        virtual void sendMessage(){}
        virtual QString getName(){return "";}
};

#endif // ZONE_H
