#ifndef ZONE_CENTER_H
#define ZONE_CENTER_H

#include "Zone.h"
#include <QWidget>

namespace Ui {
class zone_center;
}

class zone_center : public Zone
{
    Q_OBJECT

public:
    explicit zone_center(Botonera *b);
    ~zone_center();
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    void sendMessage() override;
    QString getName() override;

private:
    Ui::zone_center *ui;
};

#endif // ZONE_CENTER_H
