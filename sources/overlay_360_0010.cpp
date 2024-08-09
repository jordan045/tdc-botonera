#include "overlay_360_0010.h"
#include "ui_overlay_360_0010.h"

OVERLAY_360_0010::OVERLAY_360_0010(Botonera *b) :
    ui(new Ui::OVERLAY_360_0010)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_0010::~OVERLAY_360_0010()
{
    delete ui;
}
