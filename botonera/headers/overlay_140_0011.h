#ifndef OVERLAY_140_0011_H
#define OVERLAY_140_0011_H

#include <QWidget>
#include "qek.h"

namespace Ui {
class OVERLAY_140_0011;
}

class OVERLAY_140_0011 : public Qek
{

public:
    explicit OVERLAY_140_0011(Botonera *b);
    ~OVERLAY_140_0011();

private:
    Ui::OVERLAY_140_0011 *ui;
};

#endif // OVERLAY_140_0011_H
