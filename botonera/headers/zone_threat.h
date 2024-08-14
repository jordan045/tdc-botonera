#ifndef ZONE_THREAT_H
#define ZONE_THREAT_H

#include "Zone.h"
#include <QWidget>

namespace Ui {
class zone_threat;
}

class zone_threat : public Zone
{
    Q_OBJECT

public:
    explicit zone_threat(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    QString getName() override;
    ~zone_threat();

private slots:
    void on_THREAT_MIN_toggled(bool checked);

    void on_THREAT_6MIN_toggled(bool checked);

    void on_THREAT_30SEC_toggled(bool checked);

    void on_THREAT_12SEC_toggled(bool checked);

private:
    Ui::zone_threat *ui;
    Botonera *miBotonera;
};

#endif // ZONE_THREAT_H
