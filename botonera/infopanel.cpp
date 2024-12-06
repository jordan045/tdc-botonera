#include "infopanel.h"
#include "ui_infopanel.h"

infoPanel::infoPanel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::infoPanel)
{
    ui->setupUi(this);
}

infoPanel::~infoPanel()
{
    delete ui;
}

void infoPanel::on_pushButton_clicked()
{
    this->close();
}

