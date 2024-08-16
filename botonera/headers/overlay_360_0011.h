#ifndef OVERLAY_360_0011_H
#define OVERLAY_360_0011_H

#include <QWidget>
#include "qek.h"

namespace Ui {
class OVERLAY_360_0011;
}

class OVERLAY_360_0011 : public Qek
{
public:
    explicit OVERLAY_360_0011(Botonera *b);
    ~OVERLAY_360_0011();

private:
    Ui::OVERLAY_360_0011 *ui;
    void shortcuts();
};

#endif // OVERLAY_360_0011_H
