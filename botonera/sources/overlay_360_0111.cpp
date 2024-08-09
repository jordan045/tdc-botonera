#include "overlay_360_0111.h"
#include "ui_overlay_360_0111.h"

OVERLAY_360_0111::OVERLAY_360_0111(Botonera *b) :
    ui(new Ui::OVERLAY_360_0111)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_0111::~OVERLAY_360_0111()
{
    delete ui;
}
