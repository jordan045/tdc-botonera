#ifndef ZONE_DISPLAYSELECTION_H
#define ZONE_DISPLAYSELECTION_H

#include "Zone.h"
#include <QWidget>

namespace Ui {
class zone_displaySelection;
}

class zone_displaySelection : public Zone
{
    Q_OBJECT

public:
    explicit zone_displaySelection(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    QString getName() override;
    ~zone_displaySelection();

private:
    Ui::zone_displaySelection *ui;
    Botonera *miBotonera;
};

#endif // ZONE_DISPLAYSELECTION_H
