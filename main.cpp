#include "mainwindow.h"

#include <QApplication>
#include <zona.h>
#include <range.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    range r;
    r.show();
    return a.exec();
}
