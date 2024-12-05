#ifndef INITMENU_H
#define INITMENU_H

#include <QWidget>
#include "botonera.h"
#include "alphaNumericDisplay.h"

#include "decoderLPD.h"
#include "qremoteobjectnode.h"
#include "rep_botoneraMaster_replica.h"
#include "transciever_fpga.h"



class InitMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InitMenu(QWidget *parent = nullptr);

private:
    Botonera *myBotonera;
    decoderLPD *myDecoderLPD;
    decoderAND *myDecoderAND;
    transcieverFPGA *comunicationSystem;
    AlphaNumericDisplay *myAlphaNumericDisplay;

    void start();
    QButtonGroup *group;
    int meko;
        //TODO Fijarse si no desaparece al cerrar el initMenu
    QRemoteObjectHost* srcNode;
    QRemoteObjectNode nodoReplica;
    QSharedPointer<botoneraMasterReplica> ptr;

    QJsonArray jsonArray;

    bool master;

    void readFiles();
    void startInterface();
    void startConnection();

private slots:
    void seleccion();



};

#endif // INITMENU_H
