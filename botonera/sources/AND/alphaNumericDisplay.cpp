#include "andGui.h"
#include "ui_andGui.h"
#include "decoderAND.h"
#include "ui_andGrilla.h"
#include <QLabel>
#include <QDebug>
#include <QStackedWidget>
#include <QFontDatabase>
#include <QFont>

AlphaNumericDisplay::AlphaNumericDisplay(QWidget *parent, Botonera *b, decoderAND *translator)
    : QWidget(parent),ui(new Ui::andGui)
{
    converter = translator;

    // Crear QStackedWidget
    stackedWidget = new QStackedWidget(this);

    QWidget *mainInterface = new QWidget();  // Interfaz principal
    grilla = new Ui::andGrilla;              // Inicializar andGrilla

    ui->setupUi(mainInterface);
    QWidget *grillaWidget = new QWidget();   // Crear un nuevo QWidget para la grilla
    grilla->setupUi(grillaWidget);           // Cargar la interfaz de la grilla en el nuevo widget

    stackedWidget->addWidget(mainInterface); // Página 0: Interfaz principal
    stackedWidget->addWidget(grillaWidget);  // Página 1: Interfaz andGrilla

    stackedWidget->setCurrentIndex(0);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);  // Solo agregamos el stackedWidget
    setLayout(layout);

    this->setFixedSize(627, 603);  // Establecer tamaño fijo opcional

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

    // Cargar la fuente desde los recursos
    int fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/pixelmix.ttf");
    if (fontId != -1) {
        QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont font(fontFamily);
        font.setPointSize(FONTSIZE);
        // Aplicar la fuente a todos los QLabel
        for (QLabel *label : labels) {
            label->setFont(font);
        }
    } else {
        qWarning() << "No se pudo cargar la fuente desde recursos.";
    }

    ui->selGroup->setId(ui->noLine,0);
    ui->selGroup->setId(ui->AButton,1);
    ui->selGroup->setId(ui->BButton,2);
    ui->selGroup->setId(ui->CButton,3);
    ui->selGroup->setId(ui->DButton,4);
    ui->selGroup->setId(ui->EButton,5);
    ui->selGroup->setId(ui->FButton,6);
    ui->selGroup->setId(ui->GButton,7);
    ui->selGroup->setId(ui->HButton,8);
    ui->selGroup->setId(ui->IButton,9);
    ui->selGroup->setId(ui->JButton,10);
    ui->selGroup->setId(ui->KButton,11);
    ui->selGroup->setId(ui->LButton,12);

    connect(ui->pushButton_grilla, &QPushButton::clicked, this, &AlphaNumericDisplay::on_pushButton_grilla_clicked);
    connect(grilla->pushButton_back, &QPushButton::clicked, this, &AlphaNumericDisplay::on_pushButton_back_clicked);
    connect(ui->pushButton_Del, &QPushButton::clicked, this, &AlphaNumericDisplay::on_pushButton_Del_clicked);

    connect(ui->pushButton_W1,&QPushButton::clicked,this,&AlphaNumericDisplay::on_pushButton_W1_pressed);
    connect(ui->pushButton_W2,&QPushButton::clicked,this,&AlphaNumericDisplay::on_pushButton_W2_pressed);
    connect(ui->pushButton_W3,&QPushButton::clicked,this,&AlphaNumericDisplay::on_pushButton_W3_pressed);

    //Conecta botones de lineas con su funcionalidad correspondiente
    connect(ui->AButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_A_Button_clicked);
    connect(ui->BButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_B_Button_clicked);
    connect(ui->CButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_C_Button_clicked);
    connect(ui->DButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_D_Button_clicked);
    connect(ui->EButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_E_Button_clicked);
    connect(ui->FButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_F_Button_clicked);
    connect(ui->GButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_G_Button_clicked);
    connect(ui->HButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_H_Button_clicked);
    connect(ui->IButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_I_Button_clicked);
    connect(ui->JButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_J_Button_clicked);
    connect(ui->KButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_K_Button_clicked);
    connect(ui->LButton,&QPushButton::clicked,this,&AlphaNumericDisplay::on_L_Button_clicked);
    connect(ui->noLine,&QPushButton::clicked,this,&AlphaNumericDisplay::on_noLine_clicked);

    connect(grilla->P01_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P01_button_clicked);
    connect(grilla->P02_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P02_button_clicked);
    connect(grilla->P03_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P03_button_clicked);
    connect(grilla->P04_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P04_button_clicked);
    connect(grilla->P05_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P05_button_clicked);
    connect(grilla->P06_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P06_button_clicked);
    connect(grilla->P07_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P07_button_clicked);
    connect(grilla->P08_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P08_button_clicked);
    connect(grilla->P09_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P09_button_clicked);
    connect(grilla->P10_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P10_button_clicked);
    connect(grilla->P11_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P11_button_clicked);
    connect(grilla->P12_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P12_button_clicked);
    connect(grilla->P13_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P13_button_clicked);
    connect(grilla->P14_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P14_button_clicked);
    connect(grilla->P15_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P15_button_clicked);
    connect(grilla->P16_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P16_button_clicked);
    connect(grilla->P17_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_P17_button_clicked);
    connect(grilla->S01_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_S01_button_clicked);
    connect(grilla->S02_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_S02_button_clicked);
    connect(grilla->S03_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_S03_button_clicked);
    connect(grilla->S04_button, &QPushButton::clicked,this,&AlphaNumericDisplay::on_S04_button_clicked);

    // Conecta la señal de conversión de AndTranslator a una función lambda que actualiza el QLabel
    QObject::connect(converter, &decoderAND::conversionResult, [this](const QPair<int,QString> line) {
        writeToLine(line);
        if (line.first == 0){
            QString dataLine = line.second;
            updateWButton(dataLine);
        }
        if (line.first == 14)
            updateLineButton(line);
    });

    // Esto hace que se abra en una ventana aparte
    this->setWindowFlag(Qt::Window);
    this->setWindowTitle("AND");
    this->show();
}

void AlphaNumericDisplay::writeToLine(QPair<int,QString> line){
    labels[line.first]->setText(line.second);
}

void AlphaNumericDisplay::updateWButton(QString line){
    //el Workspace es el 3er caracter de la linea recibida con fila 0 -> [W02]
    QChar workspace = line[2];
    if(workspace == '1'){
        ui->pushButton_W1->toggle();
    }
    else if(workspace == '2'){
        ui->pushButton_W2->toggle();
    }
    else if(workspace == '3'){
        ui->pushButton_W3->toggle();
    }
}

void AlphaNumericDisplay::updateLineButton(QPair<int, QString> line) {
    QChar andLine = line.second[0];
    int lineIndex;

    if(andLine == ' ')
        lineIndex = 0;
    else
        lineIndex = static_cast<int>(andLine.unicode() - 'A');

    QAbstractButton *buttonToPress = ui->selGroup->button(lineIndex);
    buttonToPress->toggle();
}

void AlphaNumericDisplay::selectNextLine(){
    int i = (mik->getActualLine() == 12) ? 0 : mik->getActualLine() + 1;
    QAbstractButton *buttonToPress = ui->selGroup->button(i);
    buttonToPress->click();
}

void AlphaNumericDisplay::selectPreviousLine(){
    int i = (mik->getActualLine() == 0) ? 12 : mik->getActualLine() - 1;
    QAbstractButton *buttonToPress = ui->selGroup->button(i);
    buttonToPress->click();
}

void AlphaNumericDisplay::keyPressEvent(QKeyEvent *event){
    QString keyText = event->text();

    switch (event->key()) {
        case Qt::Key_Return:
            mik->pressKey("EXECUTE");
            break;
        case Qt::Key_Enter://Enter de teclado numerico
            mik->pressKey("EXECUTE");
            break;

        case Qt::Key_Space:
            mik->pressKey("SPACE");
            break;

        case Qt::Key_Backspace:
            mik->pressKey("ERASE_LINE");
            break;

        case Qt::Key_Left:
            mik->pressKey("MARK_BWD");
            break;

        case Qt::Key_Right:
            mik->pressKey("MARK_FWD");
            break;

        case Qt::Key_F2:
            mik->pressKey("RB");
            break;

        case Qt::Key_F3:
            mik->pressKey("DR_OBM");
            break;

        case Qt::Key_F4:
            mik->pressKey("WIPE_WARN");
            break;

        case Qt::Key_Down:
            selectNextLine();
            break;

        case Qt::Key_Up:
            selectPreviousLine();
            break;

        default:
            //Para devolver caracteres alfanuméricos
            if(!keyText.isEmpty()){
                QChar caracter = event->text().front().toUpper();
                mik->pressKey(caracter);
            }
            break;
    }
}

void AlphaNumericDisplay::executeMacro(const QString &message){
    QStringList commands = message.split(' ', Qt::SkipEmptyParts);
    for (const QString &command : commands) {
        mik->pressKey(command);
    }
}

void AlphaNumericDisplay::handleSelectLine(Letras letra) {
    mik->goToLine(static_cast<int>(letra));
}

// Declaración de las funciones
void AlphaNumericDisplay::on_A_Button_clicked(){
    handleSelectLine(A);
}
void AlphaNumericDisplay::on_B_Button_clicked(){
    handleSelectLine(B);
}
void AlphaNumericDisplay::on_C_Button_clicked(){
    handleSelectLine(C);
}
void AlphaNumericDisplay::on_D_Button_clicked(){
    handleSelectLine(D);
}
void AlphaNumericDisplay::on_E_Button_clicked(){
    handleSelectLine(E);
}
void AlphaNumericDisplay::on_F_Button_clicked(){
    handleSelectLine(F);
}
void AlphaNumericDisplay::on_G_Button_clicked(){
    handleSelectLine(G);
}
void AlphaNumericDisplay::on_H_Button_clicked(){
    handleSelectLine(H);
}
void AlphaNumericDisplay::on_I_Button_clicked(){
    handleSelectLine(I);
}
void AlphaNumericDisplay::on_J_Button_clicked(){
    handleSelectLine(J);
}
void AlphaNumericDisplay::on_K_Button_clicked(){
    handleSelectLine(K);
}
void AlphaNumericDisplay::on_L_Button_clicked(){
    handleSelectLine(L);
}
void AlphaNumericDisplay::on_noLine_clicked(){
    handleSelectLine(noLine);
}

//Declaracion de las funciones de los works spaces
void AlphaNumericDisplay::on_pushButton_W1_pressed(){executeMacro("W 0 1 EXECUTE");}
void AlphaNumericDisplay::on_pushButton_W2_pressed(){executeMacro("W 0 2 EXECUTE");}
void AlphaNumericDisplay::on_pushButton_W3_pressed(){executeMacro("W 0 3 EXECUTE");}

void AlphaNumericDisplay::on_pushButton_grilla_clicked(){
    qDebug() << "Cambiando a la grilla";
    stackedWidget->setCurrentIndex(1);  // Cambiar a la página con la grilla
}

void AlphaNumericDisplay::on_pushButton_back_clicked(){
    qDebug() << "Cambiando a la principal";
    stackedWidget->setCurrentIndex(0);  // Cambiar a PRINCIPAL
}

void AlphaNumericDisplay::on_P01_button_clicked(){
    executeMacro("P 0 1 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P02_button_clicked(){
    executeMacro("P 0 2 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P03_button_clicked(){
    executeMacro("P 0 3 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P04_button_clicked(){
    executeMacro("P 0 4 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P05_button_clicked(){
    executeMacro("P 0 5 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P06_button_clicked(){
    executeMacro("P 0 6 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P07_button_clicked(){
    executeMacro("P 0 7 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P08_button_clicked(){
    executeMacro("P 0 8 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P09_button_clicked(){
    executeMacro("P 0 9 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P10_button_clicked(){
    executeMacro("P 1 0 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P11_button_clicked(){
    executeMacro("P 1 1 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P12_button_clicked(){
    executeMacro("P 1 2 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P13_button_clicked(){
    executeMacro("P 1 3 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P14_button_clicked(){
    executeMacro("P 1 4 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P15_button_clicked(){
    executeMacro("P 1 5 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P16_button_clicked(){
    executeMacro("P 1 6 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_P17_button_clicked(){
    executeMacro("P 1 7 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_S01_button_clicked(){
    executeMacro("S 0 1 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_S02_button_clicked(){
    executeMacro("S 0 2 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_S03_button_clicked(){
    executeMacro("S 0 3 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_S04_button_clicked(){
    executeMacro("S 0 4 EXECUTE + EXECUTE");
    stackedWidget->setCurrentIndex(0);
}

void AlphaNumericDisplay::on_pushButton_Del_clicked(){
    executeMacro("- EXECUTE");
}




