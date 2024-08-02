#ifndef ZONE_ICM_H
#define ZONE_ICM_H

#include "Zone.h"
#include <QWidget>

namespace Ui {
class zone_icm;
}

class zone_icm : public Zone
{

public:
    explicit zone_icm(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    void sendMessage();
    QString getName() override;
    ~zone_icm();

private:
    Ui::zone_icm *ui;
};

#endif // ZONE_ICM_H
