
#include <QApplication>
#include <initmenu.h>
#include <andGui.h>

#include "lpdDecoder.h"
#include<QLabel>
#include <QWidget>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Botonera AR-TDC");
    a.setWindowIcon(QIcon(":/ico/armagedon.ico"));

    InitMenu d;
    d.show();

    LPDDecoder lpd;
    lpd.processLPDMessage(0x0,0);


    return a.exec();
}
