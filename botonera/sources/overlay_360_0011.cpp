#include "overlay_360_0011.h"
#include "ui_overlay_360_0011.h"

OVERLAY_360_0011::OVERLAY_360_0011(Botonera *b) :
    ui(new Ui::OVERLAY_360_0011)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_0011::~OVERLAY_360_0011()
{
    delete ui;
}

void OVERLAY_360_0011::shortcuts()
{
    ui->GUI_57->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_37->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_E));
    ui->GUI_36->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_W));
}
