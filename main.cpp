#include "mainwindow.h"

#include <QApplication>
#include <range.h>
#include <icm.h>
#include <label.h>
#include <qek.h>
#include <threat.h>
#include <center.h>
#include <display.h>
#include <QVBoxLayout>
#include <botonera.h>
#include <initmenu.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initMenu d;
    d.show();

    return a.exec();
}
