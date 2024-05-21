#ifndef BOTON_H
#define BOTON_H

#include <QObject>
#include <QRadioButton>

class Boton: public QObject
{
    Q_OBJECT

public:
    Boton(QString codigo, QObject *parent = nullptr);
    void setCodigo(QString);
    QString getCodigo();
    int getChar();
public slots:
    void pressed();

private:
    QString codigo;
};

#endif // BOTON_H
