#ifndef OVERLAY_360_0010_H
#define OVERLAY_360_0010_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_0010;
}

class OVERLAY_360_0010 : public Qek
{
public:
    explicit OVERLAY_360_0010(Botonera *b);
    ~OVERLAY_360_0010();

private:
    Ui::OVERLAY_360_0010 *ui;
    void shortcuts();
};

#endif // OVERLAY_360_0010_H
