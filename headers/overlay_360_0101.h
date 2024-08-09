#ifndef OVERLAY_360_0101_H
#define OVERLAY_360_0101_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_0101;
}

class OVERLAY_360_0101 : public Qek
{
public:
    explicit OVERLAY_360_0101(Botonera *b);
    ~OVERLAY_360_0101();

private:
    Ui::OVERLAY_360_0101 *ui;
};

#endif // OVERLAY_360_0101_H
