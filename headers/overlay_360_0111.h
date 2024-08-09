#ifndef OVERLAY_360_0111_H
#define OVERLAY_360_0111_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_0111;
}

class OVERLAY_360_0111 : public Qek
{
public:
    explicit OVERLAY_360_0111(Botonera *b);
    ~OVERLAY_360_0111();

private:
    Ui::OVERLAY_360_0111 *ui;
};

#endif // OVERLAY_360_0111_H
