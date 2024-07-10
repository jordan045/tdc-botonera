#include "initmenu.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

InitMenu::InitMenu(QWidget *parent) :
    QWidget(parent)
{
    // Inicializa la botonera (suponiendo que tienes esta clase)
    miBotonera = new Botonera();

    // Lee el archivo JSON
    QFile file("C:/Users/jruma/Desktop/qt-juego/overlay.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("No se pudo abrir el archivo.");
        return;
    } else {
        qDebug() << "Se abrió bien";
    }

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

