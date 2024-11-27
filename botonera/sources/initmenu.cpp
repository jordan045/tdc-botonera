#include "initmenu.h"
#include "qbuttongroup.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>
#include <ui_initmenu.h>
#include "botoneraMaster.h"

InitMenu::InitMenu(QWidget *parent) :
    QWidget(parent)
{
    QCoreApplication::setApplicationName("Botonera AR-TDC");

    QMessageBox::StandardButton reply;

    // Lee el archivo JSON con la información de los overlays
    QFile file(":/json/json/overlay.json");
    if (!file.open(QIODevice::ReadOnly)) {
        reply = QMessageBox::warning(this, "Error", "No se pudo abrir el archivo de configuración de overlay.");
        if (reply == QMessageBox::Ok)
            QCoreApplication::exit(0);
    }

    // Lee el archivo JSON con la información de los botones
    QMessageBox::StandardButton reply2;
    QString JsonFilePath = ":/json/json/properties.json";
    QFile File(JsonFilePath);
    if (!File.open(QIODevice::ReadOnly)) {
        reply2 = QMessageBox::warning(this, "Error", "Hubo un error, no se abrió el archivo de propiedades");
        if (reply2 == QMessageBox::Ok) {
            QCoreApplication::exit(0);
        }
    }

    QByteArray archivo = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(archivo);
    file.close();

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

    Ui::InitMenu ui;
    ui.setupUi(this);

    //Crear interfaz
    int countY = 0; int countX = 0;
    group = new QButtonGroup();
    group->setExclusive(true);
    // Crear botones a partir del JSON
    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        for (const QString &key : obj.keys()) {
            QString buttonCode = obj[key].toString();
            QPushButton *button = new QPushButton("");
            button->setObjectName(buttonCode);
            QString style = QString("QPushButton {image: url(':/overlays/360/img/Overlays/360/%1.png');border: none}"
                                    "QPushButton:checked {image: url(':/overlays/360/img/Overlays/360/%1_pressed.png');border: none}"
                                    )
                                .arg(key);

            group->addButton(button, countX);

            button->setStyleSheet(style);
            button->setMinimumSize(240,120);
            button->setCheckable(true);
            button->setFlat(true);

            int posX = countX % 2;
            int posY = countY / 2;

            ui.gridLayout->addWidget(button, posY, posX);
        }
        countX++;
        countY++;
    }

    tipoBuque = mainObj["tipo"].toString().toInt();

    bool master = true;

    if(master){
         botonera = new BotoneraMaster();
    }
    /*
     * else
     *      miBotonera = new BotoneraSlave();
     * */


    QObject::connect(ui.continue_button, &QPushButton::clicked, this, &InitMenu::seleccion);
}

void InitMenu::seleccion()
{
    if(group->checkedButton() == nullptr){
        QMessageBox::warning(this, "Advertencia", "Seleccione un ambiente de trabajo");
    }else {
        auto overlay = group->checkedButton()->objectName();

        botonera->setOverlay(overlay);
        botonera->start(tipoBuque);

        decoderLPD = new class decoderLPD(this);
        decoderAND = new class decoderAND(this);
        andGui = new class andGui(this, botonera, decoderAND);

        comunicationSystem = new transcieverFPGA(
            this,
            decoderAND,
            static_cast<BotoneraMaster*>(botonera),
            decoderLPD);

        this->close();
        botonera->show();
    }
}

