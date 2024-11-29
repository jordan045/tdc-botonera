#ifndef ZONE_LABEL_H
#define ZONE_LABEL_H

#include "Zone.h"
#include <QWidget>

namespace Ui {
class zone_label;
}

class zone_label : public Zone {
    Q_OBJECT

public:
    explicit zone_label(Botonera *b);
    ~zone_label();
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    QString getName() override;
    void interact(QString boton) override;

private:
    Ui::zone_label *ui;
};

#endif // ZONE_LABEL_H
