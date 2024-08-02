#include "zone_center.h"
#include "ui_zone_center.h"

zone_center::zone_center(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::zone_center)
{
    ui->setupUi(this);
}

zone_center::~zone_center()
{
    delete ui;
}
