#ifndef BOTON_H
#define BOTON_H

#include <QObject>
#include <QRadioButton>

class Boton: public QObject
{
    Q_OBJECT

public:
    Boton(int codigo, QObject *parent = nullptr);
    void setCodigo(int);
    int getCodigo();
    int getChar();
public slots:
    void pressed();

private:
    int codigo;
};

#endif // BOTON_H
