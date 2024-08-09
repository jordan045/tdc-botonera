#include "overlay_140_0011.h"
#include "ui_overlay_140_0011.h"

OVERLAY_140_0011::OVERLAY_140_0011(Botonera *b)
    : ui(new Ui::OVERLAY_140_0011)
{
    ui->setupUi(this);
    this->setMinimumSize(500,600);
    miBotonera = b;
    initiate();
}

OVERLAY_140_0011::~OVERLAY_140_0011()
{
    delete ui;
}
