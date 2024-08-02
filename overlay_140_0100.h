#ifndef OVERLAY_140_0100_H
#define OVERLAY_140_0100_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_140_0100;
}

class OVERLAY_140_0100 : public Qek
{

public:
    explicit OVERLAY_140_0100(Botonera *b);
    ~OVERLAY_140_0100();

private:
    Ui::OVERLAY_140_0100 *ui;
};

#endif // OVERLAY_140_0100_H
