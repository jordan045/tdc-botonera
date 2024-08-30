
#include <QApplication>
#include <initmenu.h>

#include <AndTranslator.h>
#include<QLabel>
#include <QWidget>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Botonera AR-TDC");
    a.setWindowIcon(QIcon(":/ico/armagedon.ico"));

    // InitMenu d;
    // d.show();

    QWidget window;
    window.setWindowTitle("Binary to Char Converter");
    window.resize(200, 100);

    QLabel *label = new QLabel(&window);
    label->setAlignment(Qt::AlignCenter);

    AndTranslator converter;
    QObject::connect(&converter, &AndTranslator::conversionResult, [label](const QString &result) {
        label->setText(result);
    });

    // Ejemplo de cadena binaria
    QString binaryString = "1000001"; // Correspondiente a 'A'
    converter.processBinaryString(binaryString);

    window.show();

    return a.exec();
}
