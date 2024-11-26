#ifndef INITMENU_H
#define INITMENU_H

#include <QWidget>
#include "botonera.h"
#include "andGui.h"
#include "lpdDecoder.h"
#include "transciever_fpga.h"

class InitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InitMenu(QWidget *parent = nullptr);

private:
    Botonera *miBotonera;
    LPDDecoder *lpd;
    AndTranslator *translator;
    Transciever_FPGA *comunicationSystem;

    void start();
    QButtonGroup *group;
    int tipoBuque;


private slots:
    void seleccion();

};

#endif // INITMENU_H
