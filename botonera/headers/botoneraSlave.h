#ifndef BOTONERASLAVE_H
#define BOTONERASLAVE_H
#include <botonera.h>
#include "rep_botoneraMaster_replica.h"
class BotoneraSlave: public Botonera{
    Q_OBJECT

public:
    explicit BotoneraSlave(QWidget *parent = nullptr, QSharedPointer<botoneraMasterReplica> ptr = nullptr);
    void removeCodeFromRange(QString boton)             override;
    void removeCodeFromLabelSelection(QString boton)    override;
    void removeCodeFromQek(QString boton)               override;
    void removeCodeFromThreat(QString boton)            override;
    void removeCodeFromCenter(QString boton)            override;
    void removeCodeFromDisplayMode(QString boton)       override;
    void removeCodeFromDisplaySelection(QString boton)  override;
    void removeCodeFromIcm(QString boton)               override;

    void setOverlay(QString codigo) override;

    void sendCodeToRange(QString boton) override;
    void sendCodeToLabelSelection(QString boton) override;
    void sendCodeToQek(QString boton) override;
    void sendCodeToThreat(QString boton) override;
    void sendCodeToCenter(QString boton) override;
    void sendCodeToDisplayMode(QString boton) override;
    void sendCodeToDisplaySelection(QString boton)override;
    void sendCodeToIcm(QString boton) override;
    void sendMessage();
    QString getOverlay();

    void initConnections();

signals:
    void emitCodeToRange(QString boton);
    void emitCodeToLabelSelection(QString boton);
    void emitCodeToQek(QString boton);
    void emitCodeToThreat(QString boton);
    void emitCodeToCenter(QString boton);
    void emitCodeToDisplayMode(QString boton);
    void emitCodeToDisplaySelection(QString boton);
    void emitCodeToIcm(QString boton);
    void emitCodeTo(QString boton);
    void emitCodeToOverlay();

private:
    QSharedPointer<botoneraMasterReplica> reptr;
};

#endif // BOTONERASLAVE_H
