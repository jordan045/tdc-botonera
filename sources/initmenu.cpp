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

    // Lee el archivo JSON con la información de los overlays
    QFile file(":/json/json/overlay.json");
    if (!file.open(QIODevice::ReadOnly)) {
        reply = QMessageBox::warning(this,"Error al abrir","No se pudo abrir el archivo de configuración de overlay.");
       if (reply == QMessageBox::Ok)
             QCoreApplication::exit(0);
    }

    // Lee el archivo JSON con la información de los botones
    QMessageBox::StandardButton reply2;
    QString JsonFilePath = ":/json/json/properties.json";
    QFile File(JsonFilePath);
    if(!File.open(QIODevice::ReadOnly))
    {
        reply2 = QMessageBox::warning(this,"ERROR LECTURA DE ARCHIVO","Hubo un error, no se abrio el archivo de propiedades");
        if (reply2 == QMessageBox::Ok) {
            QCoreApplication::exit(0);}
    }


    // Inicializa la botonera
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

    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(0);
    this->setMinimumSize(QSize(500,500));

    int countY = 0;
    int countX = 0;
    // Crear botones a partir del JSON
    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        for (const QString &key : obj.keys()) {
            QString buttonCode = obj[key].toString();
            QPushButton *button = new QPushButton("");
            QString style = QString("QPushButton {image: url(':/overlays/360/img/Overlays/360/%1.png')}"
                                    "QPushButton:pressed {image: url(':/overlays/360/img/Overlays/360/%1_pressed.png')}")
                                    .arg(key);

            button->setStyleSheet(style);
            button->setMinimumHeight(100);
            button->setFlat(true);

            int posX = countX % 2;
            int posY = countY / 2;
            layout->addWidget(button,posY,posX);

            QObject::connect(button, &QPushButton::clicked, [this, buttonCode]() {
                miBotonera->setOverlay(buttonCode);
                miBotonera->start();
                this->close();
            });
        }
        countX++; countY++;
    }

    this->setLayout(layout);
}

