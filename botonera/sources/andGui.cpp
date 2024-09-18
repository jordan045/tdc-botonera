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
    //miBotonera = b;
    tab = 1;
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

    QObject::connect(ui->pushButton_W1, &QPushButton::pressed, [this]() { tocarBoton("W01"); });
    QObject::connect(ui->pushButton_W2, &QPushButton::pressed, [this]() { tocarBoton("W02"); });
    QObject::connect(ui->pushButton_W3, &QPushButton::pressed, [this]() { tocarBoton("W03"); });

    // Conecta la señal de conversión de AndTranslator a una función lambda que actualiza el QLabel
    QObject::connect(&converter, &AndTranslator::conversionResult, [this](const QPair<int,QString> line) {
        setLine(line);
    });

    converter.processBinaryString();

}


void andGui::setLine(QPair<int,QString> line){
    labels[line.first]->setText(line.second);
}

void andGui::selLinea(int t){
    int i= t;
    while (i != tab) {
        if(tab > 13){
            tab = 0;
        }
        else{
            //llamo a estado
            qDebug()<< "Linea";
            miBotonera->sendCharToMIK('S');//deberia ir el salto de linea
            tab++;
        }
    }
    //qDebug()<< "-------";
    tab = t;
}

void andGui::setBotonera(Botonera *b){
    miBotonera = b;
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
    for(int i = 0; i < mensaje.length(); i++){
        miBotonera->sendCharToMIK(mensaje[i]);
    }
    //qDebug() << mensaje;
}


void andGui::on_AButton_clicked(){selLinea(1);}
void andGui::on_BButton_clicked(){selLinea(2);}
void andGui::on_CButton_clicked(){selLinea(3);}
void andGui::on_DButton_clicked(){selLinea(4);}
void andGui::on_EButton_clicked(){selLinea(5);}
void andGui::on_FButton_clicked(){selLinea(6);}
void andGui::on_GButton_clicked(){selLinea(7);}
void andGui::on_HButton_clicked(){selLinea(8);}
void andGui::on_IButton_clicked(){selLinea(9);}
void andGui::on_JButton_clicked(){selLinea(10);}
void andGui::on_KButton_clicked(){selLinea(11);}
void andGui::on_LButton_clicked(){selLinea(12);}
void andGui::on_MButton_clicked(){selLinea(13);}
