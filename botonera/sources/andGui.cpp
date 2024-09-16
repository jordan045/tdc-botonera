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

    // Creamos un array de labels para guardarlos
    labels.append(ui->TitleLabel);
    labels.append(ui->ALabel);
    labels.append(ui->BLabel);
    labels.append(ui->CLabel);
    labels.append(ui->DLabel);
    labels.append(ui->ELabel);
    labels.append(ui->FLabel);
    labels.append(ui->GLabel);
    labels.append(ui->HLabel);
    labels.append(ui->ILabel);
    labels.append(ui->JLabel);
    labels.append(ui->KLabel);
    labels.append(ui->LLabel);
    labels.append(ui->MLabel);
    labels.append(ui->NLabel);
    labels.append(ui->OLabel);

    QObject::connect(ui->pushButton_W1, &QPushButton::pressed, [this]() { tocarBoton("w01"); });
    QObject::connect(ui->pushButton_W2, &QPushButton::pressed, [this]() { tocarBoton("w02"); });
    QObject::connect(ui->pushButton_W3, &QPushButton::pressed, [this]() { tocarBoton("w03"); });

    // Conecta la señal de conversión de AndTranslator a una función lambda que actualiza el QLabel
    QObject::connect(&converter, &AndTranslator::conversionResult, [this](const QPair<int,QString> line) {
        setLine(line);
    });

    converter.processBinaryString();

}

void andGui::setLine(QPair<int,QString> line){
    labels[line.first]->setText(line.second);
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

