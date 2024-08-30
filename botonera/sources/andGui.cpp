#include "andGui.h"
#include "ui_andGui.h"

andGui::andGui(QWidget *parent)
    : QWidget(parent) , ui(new Ui::AND)
{
    ui->setupUi(this);
}

andGui::~andGui()
{
    delete ui;
}
