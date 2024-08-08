#ifndef OVERLAY_360_0100_H
#define OVERLAY_360_0100_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_0100;
}

class OVERLAY_360_0100 : public Qek
{

public:
    explicit OVERLAY_360_0100(Botonera *b);
    ~OVERLAY_360_0100();

private:
    Ui::OVERLAY_360_0100 *ui;
};

#endif // OVERLAY_360_0100_H
