#include "mainwindow.h"

#include <QApplication>
#include <zona.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Zona(w.getChildren());
    w.show();
    return a.exec();
}
