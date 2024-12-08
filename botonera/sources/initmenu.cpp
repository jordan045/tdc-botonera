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
#include "botoneraSlave.h"
#include "ConnectionScreen.h"

InitMenu::InitMenu(QWidget *parent) :
    QWidget(parent)
{
    QCoreApplication::setApplicationName("Botonera AR-TDC");

    readFiles();
    startConnection();
    startInterface();

}

void InitMenu::seleccion()
{
    if(group->checkedButton() == nullptr){
        QMessageBox::warning(this, "Advertencia", "Seleccione un ambiente de trabajo");
    }else {
        auto overlay = group->checkedButton()->objectName();

        myBotonera->setOverlay(overlay);
        myBotonera->start(meko);

        this->close();
        myBotonera->show();

        decoderAND *decoAND = new class decoderAND(this);

        new class AlphaNumericDisplay(this, myBotonera, decoAND);

        comunicationSystem = new transcieverFPGA(
            this,
            decoAND,
            static_cast<BotoneraMaster*>(myBotonera),
            new class decoderLPD(this));
    }
}

void InitMenu::startInterface(){
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


    QObject::connect(ui.continue_button, &QPushButton::clicked, this, &InitMenu::seleccion);
}


void InitMenu::readFiles()
{
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
    QJsonObject OverlayJson = document.object();

    // Verificar si el objeto contiene un array llamado "overlay"
    if (!OverlayJson.contains("overlay") || !OverlayJson["overlay"].isArray()) {
        qWarning("El objeto JSON no contiene un array 'overlay'.");
        return;
    }
    jsonArray = OverlayJson["overlay"].toArray();

    // Modal para mensajes de error
    meko = OverlayJson["tipo"].toString().toInt(); // obtengo el tipoDeBuque

    master = OverlayJson["master"].toBool(); //obtengo el valor de master.
}

void InitMenu::startConnection(){
    if(master){ //Si es maestro creo una botonera master
        myBotonera = new BotoneraMaster();
        // BotoneraMaster* myBotoneraMaster = new BotoneraMaster();
        srcNode = new QRemoteObjectHost(QUrl (QStringLiteral("tcp://0.0.0.0:5000")));
        auto source = dynamic_cast<botoneraMasterSource *>(myBotonera); //fuente, toma el objeto myBotonera y lo muestra en el puerto

        if(source){
            if(srcNode->enableRemoting(source)) //habilita el remoto
                qDebug() << "INIT MENU: Servidor remoto para interconexión habilitado en: " << srcNode->hostUrl();
            else
                qDebug()<<"No se habilito el servidor";
        }else{
            qDebug()<<"Error: myBotonera no es del tipo BotoneraMasterSource";
        }
    }
    else{
        //sino creo una botonera slave

        //Muestro pantalla de carga por si aun no esta la conexión.

        ConnectionScreen *pantallaCarga = new ConnectionScreen(nullptr);
        pantallaCarga->show();

        connect(pantallaCarga, &QDialog::rejected, this, &QWidget::close);

        //Uso un temporizador para ir tratando de establecer conexiópn
        QTimer *timer = new QTimer(this);

        connect(timer, &QTimer::timeout, [this, pantallaCarga, timer]() {

            nodoReplica.connectToNode(QUrl(QStringLiteral("tcp://192.168.1.1:5000"))); // Intentar conectar
            ptr.reset(nodoReplica.acquire<botoneraMasterReplica>()); // Adquirir réplica

            if (ptr->isInitialized()) {
                qDebug() << "La réplica se inicializó correctamente.";

                // Detener el temporizador y cerrar el diálogo
                timer->stop();
                pantallaCarga->accept();

                // Crear la botonera slave
                myBotonera = new BotoneraSlave(nullptr, ptr);
            } else {
                qDebug() << "Intentando conectar con la master...";
            }
        });

        // Iniciar el temporizador con un intervalo de 2 segundos
        timer->start(2000);
    }

}

