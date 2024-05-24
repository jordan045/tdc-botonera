#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //rBtn1->setIcon(QIcon(":/spoon.png"));
    //rBtn1->setIconSize(QSize(10,10));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<QRadioButton *> MainWindow::getChildren(){
    QWidget *lista = ui->horizontalLayoutWidget;
    return lista->findChildren<QRadioButton *>();
}
