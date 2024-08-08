
#include <QApplication>
#include <initmenu.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    QSharedMemory shared("62d60669-bb94-4a94-88bb-b964890a7e04");
    if( !shared.create( 512, QSharedMemory::ReadWrite) )
    {
        qWarning() << "Can't start more than one instance of the application.";
        exit(0);
    }
*/
    QCoreApplication::setApplicationName("Botonera AR-TDC");
    a.setWindowIcon(QIcon(":/ico/armagedon.ico"));
    InitMenu d;
    d.show();

    return a.exec();
}
