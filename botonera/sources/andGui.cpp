#include "andGui.h"
#include "ui_andGui.h"
#include "andTranslator.h"
#include <QLabel>
#include <QDebug>

andGui::andGui(QWidget *parent, Botonera *b)
    : QWidget(parent),ui(new Ui::andGui)
{
    // Inicializa la interfaz de usuario si es necesario
    ui->setupUi(this);
    miBotonera = b;
    mik = new MIK(b);

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

    //QObject::connect(ui->pushButton_W1, &QPushButton::pressed, [this]() { tocarBoton("W01"); });
    //QObject::connect(ui->pushButton_W2, &QPushButton::pressed, [this]() { tocarBoton("W02"); });
    //QObject::connect(ui->pushButton_W3, &QPushButton::pressed, [this]() { tocarBoton("W03"); });

    // Conecta la señal de conversión de AndTranslator a una función lambda que actualiza el QLabel
    QObject::connect(&converter, &AndTranslator::conversionResult, [this](const QPair<int,QString> line) {
        setLine(line);
    });

    converter.processBinaryString();
}

void andGui::setLine(QPair<int,QString> line){
    labels[line.first]->setText(line.second);
}

void andGui::keyReleaseEvent(QKeyEvent *event){

    QString keyText = event->text();
    switch (event->key()) {
    case Qt::Key_Enter:{
        mik->releaseKey('#');
        break;
    }
    case Qt::Key_Space:{
        mik->releaseKey('!');
        break;
    }
    case Qt::Key_Backspace:{
        mik->releaseKey('"');
    }

    default:
        break;
    }

    if(!keyText.isEmpty()){
        QChar caracter = keyText.front().toUpper();
        mik->releaseKey(caracter);
    }

}

void andGui::keyPressEvent(QKeyEvent *event){

    QString keyText = event->text();

    switch (event->key()) {
        case Qt::Key_Enter:
            mik->pressKey('#');
            break;

        case Qt::Key_Space:
            mik->pressKey('!');
            break;

        case Qt::Key_Backspace:
            mik->pressKey('"');

        default:
            break;
    }

    if(!keyText.isEmpty()){
        QChar caracter = event->text().front().toUpper();
        mik->pressKey(caracter);
    }
}

void andGui::tocarBoton(const QString &mensaje){
    for(int i = 0; i < mensaje.length(); i++){
        mik->pressKey(mensaje[i]);
    }
}

void andGui::on_AButton_clicked(){mik->selectLine(1);}
void andGui::on_BButton_clicked(){mik->selectLine(2);}
void andGui::on_CButton_clicked(){mik->selectLine(3);}
void andGui::on_DButton_clicked(){mik->selectLine(4);}
void andGui::on_EButton_clicked(){mik->selectLine(5);}
void andGui::on_FButton_clicked(){mik->selectLine(6);}
void andGui::on_GButton_clicked(){mik->selectLine(7);}
void andGui::on_HButton_clicked(){mik->selectLine(8);}
void andGui::on_IButton_clicked(){mik->selectLine(9);}
void andGui::on_JButton_clicked(){mik->selectLine(10);}
void andGui::on_KButton_clicked(){mik->selectLine(11);}
void andGui::on_LButton_clicked(){mik->selectLine(12);}
void andGui::on_MButton_clicked(){mik->selectLine(13);}

void andGui::on_pushButton_W1_pressed(){tocarBoton("W01");}
void andGui::on_pushButton_W2_pressed(){tocarBoton("W02");}
void andGui::on_pushButton_W3_pressed(){tocarBoton("W03");}
