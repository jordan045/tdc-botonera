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

void OVERLAY_360_0010::shortcuts()
{
    ui->GUI_57->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_37->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_E));
    ui->GUI_36->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_W));
    ui->GUI_35->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
}
