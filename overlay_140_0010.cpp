#include "overlay_140_0010.h"
#include "ui_overlay_140_0010.h"

OVERLAY_140_0010::OVERLAY_140_0010(Botonera *b)
    : ui(new Ui::OVERLAY_140_0010)
{
    ui->setupUi(this);
    this->setMinimumSize(500,600);
    miBotonera = b;
    initiate();
}

OVERLAY_140_0010::~OVERLAY_140_0010()
{
    delete ui;
}
