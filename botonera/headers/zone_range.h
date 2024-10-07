#ifndef ZONE_RANGE_H
#define ZONE_RANGE_H

#include "Zone.h"
#include <QWidget>

namespace Ui {
class zone_range;
}

class Boton;

class zone_range : public Zone
{

public:
    explicit zone_range(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    QString getName() override;
    ~zone_range();
    void start();


private:
    Ui::zone_range *ui;
    Boton *boton4;
};

#endif // ZONE_RANGE_H
