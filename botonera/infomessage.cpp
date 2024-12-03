#include "infomessage.h"
#include "ui_infomessage.h"

infoMessage::infoMessage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::infoMessage)
{
    ui->setupUi(this);
}

infoMessage::~infoMessage()
{
    delete ui;
}

void infoMessage::on_pushButton_clicked()
{
    this->close();
}

