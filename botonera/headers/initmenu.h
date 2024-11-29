#ifndef INITMENU_H
#define INITMENU_H

#include <QWidget>
#include "botonera.h"
#include "andGui.h"

#include "botoneraMaster.h"
#include "botoneraSlave.h"

#include "decoderLPD.h"
#include "transciever_fpga.h"


class InitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InitMenu(QWidget *parent = nullptr);

private:
    Botonera *myBotonera;
    decoderLPD *decoderLPD;
    decoderAND *decoderAND;
    transcieverFPGA *comunicationSystem;
    andGui *andGui;

    void start();
    QButtonGroup *group;
    int tipoBuque;
        //TODO Fijarse si no desaparece al cerrar el initMenu
    QRemoteObjectHost* srcNode;
    QRemoteObjectNode nodoReplica;
    QSharedPointer<botoneraMasterReplica> ptr;

    QJsonArray jsonArray;

    bool master;

    void leerArchivos();
    void iniciarInterfaz();
    void iniciarConexión();

private slots:
    void seleccion();



};

#endif // INITMENU_H
