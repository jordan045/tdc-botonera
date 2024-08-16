#include "overlay_360_0110.h"
#include "ui_overlay_360_0110.h"

OVERLAY_360_0110::OVERLAY_360_0110(Botonera *b) :
    ui(new Ui::OVERLAY_360_0110)
{
    ui->setupUi(this);
    miBotonera = b;
    initiate();
}

OVERLAY_360_0110::~OVERLAY_360_0110()
{
    delete ui;
}

void OVERLAY_360_0110::shortcuts()
{
    ui->GUI_57->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_37->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_36->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_35->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
}
