#ifndef OVERLAY_360_1000_H
#define OVERLAY_360_1000_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_1000;
}

class OVERLAY_360_1000 : public Qek
{
public:
    explicit OVERLAY_360_1000(Botonera *b);
    ~OVERLAY_360_1000();

private:
    Ui::OVERLAY_360_1000 *ui;
};

#endif // OVERLAY_360_1000_H
