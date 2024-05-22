#include "mainwindow.h"

#include <QApplication>
#include <range.h>
#include <icm.h>
#include <label.h>
#include <qek.h>
#include <threat.h>
#include <center.h>
#include <display_mode.h>
#include <QVBoxLayout>
#include <botonera.h>
#include <initmenu.h>
#include <QSharedMemory>
#include <iostream>
#include <QBitArray>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSharedMemory shared("62d60669-bb94-4a94-88bb-b964890a7e04");
    if( !shared.create( 512, QSharedMemory::ReadWrite) )
    {
        qWarning() << "Can't start more than one instance of the application.";
        exit(0);
    }

    qDebug() << "Application started successfully.";
    initMenu d;
    d.show();

    return a.exec();
}
