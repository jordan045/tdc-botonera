#include "andGui.h"
#include "ui_andGui.h"
#include "andTranslator.h"
#include <QLabel>
#include <QDebug>

andGui::andGui(QWidget *parent)
    : QWidget(parent)
{
    // Inicializa la interfaz de usuario si es necesario
    // ui->setupUi(this);

    // Crea el QLabel
    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);

    label->setWordWrap(true);// Permite que el texto se ajuste en varias líneas

    label->setMinimumSize(600, 600);

    // Conecta la señal de conversión de AndTranslator a una función lambda que actualiza el QLabel
    QObject::connect(&converter, &AndTranslator::conversionResult, [this](const QString &result) {
        label->setText(result);
    });
}

void andGui::recibirMensaje(QString entrada)
{
    QString textResult;
    for (int i = 0; i < entrada.size(); i += 8) {
        // Obtener un segmento de 8 caracteres
        QString binarySegment = entrada.mid(i, 8);

        // Convertir el segmento binario a carácter usando binaryToChar
        QString character = converter.binaryToChar(binarySegment);

        // Verificar si la conversión fue exitosa
        if (!character.isEmpty()) {
            textResult.append(character);
        } else {
            qDebug() << "Error en la conversión del segmento:" << binarySegment;
        }
    }
    label->setText(textResult);
}

andGui::~andGui()
{
    // Eliminar el QLabel si es necesario
    // No es necesario eliminar el QLabel aquí ya que está siendo manejado automáticamente por el parent (this)
    // delete label; // Puedes comentar esta línea si el QLabel es manejado automáticamente por su parent
}
