#ifndef INITMENU_H
#define INITMENU_H

#include <QWidget>
#include "botonera.h"
class InitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InitMenu(QWidget *parent = nullptr);

private slots:
    void iniciarModo1();
    void iniciarModo2();
    void iniciarModo3();
private:
    Botonera *miBotonera;
};

#endif // INITMENU_H
