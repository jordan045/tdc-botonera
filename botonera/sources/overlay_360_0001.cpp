#include "overlay_360_0001.h"
#include "ui_overlay_360_0001.h"

OVERLAY_360_0001::OVERLAY_360_0001(Botonera *b) :
    ui(new Ui::OVERLAY_360_0001)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_0001::~OVERLAY_360_0001()
{
    delete ui;
}
