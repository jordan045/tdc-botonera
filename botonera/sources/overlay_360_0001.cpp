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

void OVERLAY_360_0001::shortcuts()
{
    //     qek_group->button(32)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    //     qek_group->button(16)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_E));
    //     qek_group->button(15)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_W));
    //     qek_group->button(14)->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    ui->GUI_57->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_37->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_36->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->GUI_35->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
}


