#ifndef INITMENU_H
#define INITMENU_H

#include <QWidget>
#include "botonera.h"
class initMenu : public QWidget
{
    Q_OBJECT
public:
    explicit initMenu(QWidget *parent = nullptr);

private slots:
    void iniciarModo1();
    void iniciarModo2();
    void iniciarModo3();
private:
    botonera *miBotonera;
};

#endif // INITMENU_H
