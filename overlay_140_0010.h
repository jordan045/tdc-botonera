#ifndef OVERLAY_140_0010_H
#define OVERLAY_140_0010_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_140_0010;
}

class OVERLAY_140_0010 : public Qek
{

public:
    explicit OVERLAY_140_0010(Botonera *b);
    ~OVERLAY_140_0010();

private:
    Ui::OVERLAY_140_0010 *ui;
};

#endif // OVERLAY_140_0010_H
