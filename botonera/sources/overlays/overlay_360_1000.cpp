#include "overlay_360_1000.h"
#include "ui_overlay_360_1000.h"

OVERLAY_360_1000::OVERLAY_360_1000(Botonera *b) :
    ui(new Ui::OVERLAY_360_1000)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_1000::~OVERLAY_360_1000()
{
    delete ui;
}

