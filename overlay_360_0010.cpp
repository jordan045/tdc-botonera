#include "overlay_360_0010.h"
#include "ui_overlay_360_0010.h"

overlay_360_0010::overlay_360_0010(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overlay_360_0010)
{
    ui->setupUi(this);
}

overlay_360_0010::~overlay_360_0010()
{
    delete ui;
}
