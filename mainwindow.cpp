#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->setStyleSheet("QRadioButton::indicator {width: 80px; height: 80px;}"
                        "QRadioButton#RS2::indicator::unchecked {image: url(':/img/range/img/2.png')}"
                        "QRadioButton#RS4::indicator::unchecked {image: url(':/img/range/img/4.png')}"
                        "QRadioButton#RS8::indicator::unchecked {image: url(':/img/range/img/8.png')}"
                        "QRadioButton#RS16::indicator::unchecked {image: url(':/img/range/img/16.png')}"
                        "QRadioButton#RS32::indicator::unchecked {image: url(':/img/range/img/32.png')}"
                        "QRadioButton#RS64::indicator::unchecked {image: url(':/img/range/img/64.png')}"
                        "QRadioButton#RS128::indicator::unchecked {image: url(':/img/range/img/128.png')}"
                        "QRadioButton#RS256::indicator::unchecked {image: url(':/img/range/img/256.png')}"

                        "QRadioButton#RS2::indicator::checked {image: url(':/img/range/img/2_pressed.png')}"
                        "QRadioButton#RS4::indicator::checked {image: url(':/img/range/img/4_pressed.png')}"
                        "QRadioButton#RS8::indicator::checked {image: url(':/img/range/img/8_pressed.png')}"
                        "QRadioButton#RS16::indicator::checked {image: url(':/img/range/img/16_pressed.png')}"
                        "QRadioButton#RS32::indicator::checked {image: url(':/img/range/img/32_pressed.png')}"
                        "QRadioButton#RS64::indicator::checked {image: url(':/img/range/img/64_pressed.png')}"
                        "QRadioButton#RS128::indicator::checked {image: url(':/img/range/img/128_pressed.png')}"
                        "QRadioButton#RS256::indicator::checked {image: url(':/img/range/img/256_pressed.png')}"
                        );

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
