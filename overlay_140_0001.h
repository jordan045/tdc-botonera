#ifndef OVERLAY_140_0001_H
#define OVERLAY_140_0001_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_140_0001;
}

class OVERLAY_140_0001 : public Qek
{

public:
    explicit OVERLAY_140_0001(Botonera *b);
    ~OVERLAY_140_0001();

private:
    Ui::OVERLAY_140_0001 *ui;
};

#endif // OVERLAY_140_0001_H
