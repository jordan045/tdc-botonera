#include "overlay_140_0010.h"
#include "ui_overlay_140_0010.h"

OVERLAY_140_0010::OVERLAY_140_0010(Botonera *b)
    : ui(new Ui::OVERLAY_140_0010)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_140_0010::~OVERLAY_140_0010()
{
    delete ui;
}
