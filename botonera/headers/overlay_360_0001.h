#ifndef OVERLAY_360_0001_H
#define OVERLAY_360_0001_H

#include "qek.h"
#include <QWidget>

namespace Ui {
class OVERLAY_360_0001;
}

class OVERLAY_360_0001 : public Qek
{
public:
    explicit OVERLAY_360_0001(Botonera *b);
    ~OVERLAY_360_0001();


private:
    Ui::OVERLAY_360_0001 *ui;
    void shortcuts();
};

#endif // OVERLAY_360_0001_H
