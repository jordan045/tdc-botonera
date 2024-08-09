#include "overlay_360_0101.h"
#include "ui_overlay_360_0101.h"

OVERLAY_360_0101::OVERLAY_360_0101(Botonera *b) :
    ui(new Ui::OVERLAY_360_0101)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_0101::~OVERLAY_360_0101()
{
    delete ui;
}
