#ifndef BOTONERAMASTER_H
#define BOTONERAMASTER_H

#include "rep_botoneraMaster_source.h"

#include "botonera.h"

class BotoneraMaster:public Botonera, public botoneraMasterSource{

private:
    FormatConcentrator *concentrator;
    Estado *estadoActual;

public:
        explicit BotoneraMaster(QWidget *parent = nullptr);
        void removeCodeFromRange(QString boton)             override;
        void removeCodeFromLabelSelection(QString boton)    override;
        void removeCodeFromQek(QString boton)               override;
        void removeCodeFromThreat(QString boton)            override;
        void removeCodeFromCenter(QString boton)            override;
        void removeCodeFromDisplayMode(QString boton)       override;
        void removeCodeFromDisplaySelection(QString boton)  override;
        void removeCodeFromIcm(QString boton)               override;

        //--Removers Slave--//
        void removeCodeFromCenterSlave(QString boton);
        void removeCodeFromMIKSlave(QString caracter);
        void removeCodeFromIcmSlave(QString boton);
        void removeCodeFromQekSlave(QString boton);

        void setOverlay(QString codigo) override;

        void sendCodeToRange(QString boton) override;
        void sendCodeToLabelSelection(QString boton) override;
        void sendCodeToQek(QString boton) override;
        void sendCodeToThreat(QString boton) override;
        void sendCodeToCenter(QString boton) override;
        void sendCodeToDisplayMode(QString boton) override;
        void sendCodeToDisplaySelection(QString boton)override;
        void sendCodeToIcm(QString boton) override;

        void sendCharToMIK(QString caracter) override;


        //Los metodo que son slots de .rep
        void sendCodeToRangeFromSlave(QString code);
        void sendCodeToLabelSelectionFromSlave(QString boton);
        void sendCodeToThreatFromSlave(QString boton);
        void sendCodeToDisplayModeFromSlave(QString boton);
        void sendCodeToDisplaySelectionFromSlave(QString boton);

        //-- Los Setters de Slave //
        void sendCodeToCenterSlave(QString boton);
        void sendCharToMIKSlave(QString caracter);
        void sendCodeToIcmSlave(QString boton);
        void sendCodeToQekSlave(QString boton);
        void sendCodeToOverlaySlave(QString codigo);

        QByteArray getConcentrator();
        QString getOverlay();

        void synchronize() override;

};
#endif // BOTONERAMASTER_H
