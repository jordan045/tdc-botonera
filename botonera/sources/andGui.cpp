#include "andGui.h"
#include "ui_andGui.h"
#include "andTranslator.h"
#include <QLabel>
#include <QDebug>

andGui::andGui(QWidget *parent)
    : QWidget(parent),ui(new Ui::andGui)
{
    // Inicializa la interfaz de usuario si es necesario
    // ui->setupUi(this);

    ui->setupUi(this);

    // Crea el QLabel
    andLabel = ui->ALabel;

    QObject::connect(ui->pushButton_W1, &QPushButton::pressed, [this]() { tocarBoton("w01"); });
    QObject::connect(ui->pushButton_W2, &QPushButton::pressed, [this]() { tocarBoton("w02"); });
    QObject::connect(ui->pushButton_W3, &QPushButton::pressed, [this]() { tocarBoton("w03"); });
    // Conecta la señal de conversión de AndTranslator a una función lambda que actualiza el QLabel
    QObject::connect(&converter, &AndTranslator::conversionResult, [this](const QString &result) {
        andLabel->setText(result);
    });

    converter.processBinaryString();

}



void andGui::recibirMensaje(QString entrada)
{
    // QString textResult;
    // for (int i = 0; i < entrada.size(); i += 8) {
    //     // Obtener un segmento de 8 caracteres
    //     QString binarySegment = entrada.mid(i, 8);

    //     // Convertir el segmento binario a carácter usando binaryToChar
    //     //QString character = converter.binaryToChar(binarySegment);

    //     // Verificar si la conversión fue exitosa
    //     if (!character.isEmpty()) {
    //         textResult.append(character);
    //     } else {
    //         qDebug() << "Error en la conversión del segmento:" << binarySegment;
    //     }
    // }
    // andLabel->setText(textResult);
}

void andGui::tocarBoton(const QString &mensaje)
{
    qDebug() << mensaje;
}

