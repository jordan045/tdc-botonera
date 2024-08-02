#include "overlay_360_0001.h"
#include "ui_overlay_360_0001.h"

overlay_360_0001::overlay_360_0001(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overlay_360_0001)
{
    ui->setupUi(this);
}

overlay_360_0001::~overlay_360_0001()
{
    delete ui;
}
