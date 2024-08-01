#include "initmenu.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>

InitMenu::InitMenu(QWidget *parent) :
    QWidget(parent)
{
    QMessageBox::StandardButton reply;

    // Lee el archivo JSON
    QFile file(":/json/overlay.json");
    if (!file.open(QIODevice::ReadOnly)) {
        reply = QMessageBox::warning(this,"ERROR LECTURA DE ARCHIVO","No se pudo abrir el archivo de configuración de overlay.");
       if (reply == QMessageBox::Ok)
             QCoreApplication::exit(0);
    } else {
        qDebug() << "Se abrió bien el archivo de overlay";
    }

    QMessageBox::StandardButton replys;
    QString JsonFilePath = ":/json/properties.json";
    qDebug()<<"Se llamo a leer json";
    QFile File(JsonFilePath);
    if(!File.open(QIODevice::ReadOnly))
    {
        replys = QMessageBox::warning(this,"ERROR LECTURA DE ARCHIVO","Hubo un error, no se abrio el archivo de propiedades");
        if (replys == QMessageBox::Ok) {
            QCoreApplication::exit(0);}
    }
    else qDebug()<<"se abrió bien el archivo de properties";


    // Inicializa la botonera (suponiendo que tienes esta clase)
    miBotonera = new Botonera();

    QByteArray archivo = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(archivo);

    // Verificar si el documento es un objeto
    if (!document.isObject()) {
        qWarning("El documento JSON no es un objeto.");
        return;
    }

    QJsonObject mainObj = document.object();

    // Verificar si el objeto contiene un array llamado "overlay"
    if (!mainObj.contains("overlay") || !mainObj["overlay"].isArray()) {
        qWarning("El objeto JSON no contiene un array 'overlay'.");
        return;
    }

    QJsonArray jsonArray = mainObj["overlay"].toArray();

    // Depuración: Imprimir el contenido del JSON
    qDebug() << "Contenido del JSON:" << jsonArray;

    // Crear layout principal
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Crear botones a partir del JSON
    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        qDebug() << "Objeto JSON:" << obj;

        for (const QString &key : obj.keys()) {
            QString buttonName = key;
            QString buttonCode = obj[key].toString();
            qDebug() << "Creando botón con nombre:" << buttonName;

            QPushButton *button = new QPushButton(buttonName);
            layout->addWidget(button);

            QObject::connect(button, &QPushButton::clicked, [this, buttonCode]() {
                miBotonera->start();
                this->close();
                qDebug() << "Botón presionado con código:" << buttonCode;
                // Aquí puedes llamar a un método de Botonera y pasar el código del botón
                miBotonera->setOverlay(buttonCode);
            });
        }
    }

    this->setLayout(layout);
}

