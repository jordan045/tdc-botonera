#ifndef INITMENU_H
#define INITMENU_H

#include <QWidget>
#include "botonera.h"
#include "andGui.h"
#include "decoderLPD.h"
#include "transciever_fpga.h"

class InitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InitMenu(QWidget *parent = nullptr);

private:
    Botonera *botonera;
    decoderLPD *decoderLPD_;
    decoderAND *decoderAND_;
    transcieverFPGA *comunicationSystem;
    andGui *andGui_;

    void start();
    QButtonGroup *group;
    int tipoBuque;


private slots:
    void seleccion();

};

#endif // INITMENU_H
