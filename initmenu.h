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
    void iniciarModo(int m);

private:
    botonera *miBotonera;
};

#endif // INITMENU_H
