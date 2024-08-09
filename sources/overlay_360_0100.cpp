#include "overlay_360_0100.h"
#include "ui_overlay_360_0100.h"

OVERLAY_360_0100::OVERLAY_360_0100(Botonera *b) :
    ui(new Ui::OVERLAY_360_0100)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_0100::~OVERLAY_360_0100()
{
    delete ui;
}
