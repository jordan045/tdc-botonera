#ifndef INITMENU_H
#define INITMENU_H

#include <QWidget>
#include "botonera.h"
#include "andGui.h"
#include "botoneraMaster.h"

class InitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InitMenu(QWidget *parent = nullptr);

private:
    Botonera *miBotonera;
    void start();
    QButtonGroup *group;
    int tipoBuque;
        //TODO Fijarse si no desaparece al cerrar el initMenu
    QRemoteObjectHost* srcNode;


private slots:
    void seleccion();

};

#endif // INITMENU_H
