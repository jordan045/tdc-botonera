#ifndef ZONE_DISPLAYMODE_H
#define ZONE_DISPLAYMODE_H

#include "Zone.h"
#include <QWidget>

namespace Ui {
class zone_displayMode;
}

class zone_displayMode : public Zone
{
    Q_OBJECT

public:
    explicit zone_displayMode(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    void sendMessage() override;
    QString getName() override;
    ~zone_displayMode();

private:
    Ui::zone_displayMode *ui;
    Botonera *miBotonera;
};

#endif // ZONE_DISPLAYMODE_H
