#include "overlay_140_0100.h"
#include "ui_overlay_140_0100.h"

OVERLAY_140_0100::OVERLAY_140_0100(Botonera *b)
    : ui(new Ui::OVERLAY_140_0100)
{
    ui->setupUi(this);
    this->setMinimumSize(500,600);
    miBotonera = b;
    initiate();
}

OVERLAY_140_0100::~OVERLAY_140_0100()
{
    delete ui;
}
