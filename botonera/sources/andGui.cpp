#include "andGui.h"
#include "ui_andGui.h"
#include "andTranslator.h"
#include "ui_andGrilla.h"
#include <QLabel>
#include <QDebug>
#include <QStackedWidget>

andGui::andGui(QWidget *parent, Botonera *b)
    : QWidget(parent),ui(new Ui::andGui)
{

    // Crear QStackedWidget
    stackedWidget = new QStackedWidget(this);

    // Inicializar las interfaces
    QWidget *mainInterface = new QWidget();  // Interfaz principal
    grilla = new Ui::andGrilla;              // Inicializar andGrilla

    // Configurar las interfaces
    ui->setupUi(mainInterface);  // Cargar la interfaz principal en el widget
    QWidget *grillaWidget = new QWidget();   // Crear un nuevo QWidget para la grilla
    grilla->setupUi(grillaWidget);           // Cargar la interfaz de la grilla en el nuevo widget

    // Agregar las interfaces al QStackedWidget
    stackedWidget->addWidget(mainInterface); // Página 0: Interfaz principal
    stackedWidget->addWidget(grillaWidget);  // Página 1: Interfaz andGrilla

    // Mostrar la primera página (Interfaz principal)
    stackedWidget->setCurrentIndex(0);

    // Ahora el stackedWidget es el único widget en el layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);  // Solo agregamos el stackedWidget
    setLayout(layout);
    tab = 1;
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

    tab = 1;

    connect(ui->pushButton_grilla, &QPushButton::clicked, this, &andGui::on_pushButton_grilla_clicked);
    connect(grilla->pushButton_back, &QPushButton::clicked, this, &andGui::on_pushButton_back_clicked);


    // Conecta la señal de conversión de AndTranslator a una función lambda que actualiza el QLabel
    QObject::connect(&converter, &AndTranslator::conversionResult, [this](const QPair<int,QString> line) {
        setLine(line);
    });

    converter.processBinaryString();

    // Esto hace que se abra en una ventana aparte
    this->setWindowFlag(Qt::Window);
    this->setWindowTitle("AND");
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

void andGui::on_pushButton_grilla_clicked()
{
    qDebug() << "Cambiando a la grilla";
    stackedWidget->setCurrentIndex(1);  // Cambiar a la página con la grilla
}


void andGui::on_pushButton_back_clicked()
{
    qDebug() << "Cambiando a la principal";
    stackedWidget->setCurrentIndex(0);  // Cambiar a la página con la grilla
}

