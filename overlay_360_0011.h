#ifndef OVERLAY_360_0011_H
#define OVERLAY_360_0011_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_0011;
}

class OVERLAY_360_0011 : public QWidget
{
public:
    explicit OVERLAY_360_0011(Botonera *b);
    ~OVERLAY_360_0011();

private:
    Ui::OVERLAY_360_0011 *ui;
};

#endif // OVERLAY_360_0011_H
