
#include <QApplication>
#include <initmenu.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Botonera AR-TDC");
    a.setWindowIcon(QIcon(":/ico/armagedon.ico"));
    InitMenu d;
    d.show();

    return a.exec();
}
