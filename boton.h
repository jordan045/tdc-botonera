#ifndef BOTON_H
#define BOTON_H

#include "Zone.h"
#include <QObject>
#include <QRadioButton>

class Boton: public QObject
{
    Q_OBJECT

public:
    Boton(Zone *z,QString codigo, QObject *parent = nullptr);
    void setCodigo(QString);
    QString getCodigo();
    int getChar();
public slots:
    void pressed();

private:
    QString codigo;
    Zone *zona;
};

#endif // BOTON_H
