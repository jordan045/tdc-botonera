#ifndef BOTONERAMASTER_H
#define BOTONERAMASTER_H

#include "botonera.h"

class BotoneraMaster:public Botonera{

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

        void setOverlay(QString codigo) override;

        void sendCodeToRange(QString boton) override;
        void sendCodeToLabelSelection(QString boton) override;
        void sendCodeToQek(QString boton) override;
        void sendCodeToThreat(QString boton) override;
        void sendCodeToCenter(QString boton) override;
        void sendCodeToDisplayMode(QString boton) override;
        void sendCodeToDisplaySelection(QString boton)override;
        void sendCodeToIcm(QString boton) override;
        QByteArray getConcentrator();
        QString getOverlay();

};
#endif // BOTONERAMASTER_H
