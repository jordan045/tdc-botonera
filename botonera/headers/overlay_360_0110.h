#ifndef OVERLAY_360_0110_H
#define OVERLAY_360_0110_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_0110;
}

class OVERLAY_360_0110 : public Qek
{
public:
    explicit OVERLAY_360_0110(Botonera *b);
    ~OVERLAY_360_0110();

private:
    Ui::OVERLAY_360_0110 *ui;
};

#endif // OVERLAY_360_0110_H
