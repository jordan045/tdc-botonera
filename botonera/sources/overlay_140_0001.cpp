#include "overlay_140_0001.h"
#include <ui_overlay_140_0001.h>

OVERLAY_140_0001::OVERLAY_140_0001(Botonera *b)
    : ui(new Ui::OVERLAY_140_0001)
{
    ui->setupUi(this);
    this->setMinimumSize(500,600);
    miBotonera = b;

    initiate();

}

OVERLAY_140_0001::~OVERLAY_140_0001(){
    delete ui;
}
