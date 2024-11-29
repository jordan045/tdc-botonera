#ifndef ANDGUI_H
#define ANDGUI_H

#include <QWidget>
#include <QKeyEvent>

#include "qstackedwidget.h"
#include "mik.h"
#include "ui_andGui.h"
#include "decoderAND.h"
#include "QLabel"
#include "botonera.h"

namespace Ui {
class andGrilla;

}

class Botonera;
class andGui : public QWidget
{
    Q_OBJECT
public:
    explicit andGui(QWidget *parent = nullptr,Botonera *b = nullptr, decoderAND *translator = nullptr);

private:
    Botonera *miBotonera;
    Ui::andGui *ui;
    Ui::andGrilla *grilla;
    decoderAND *converter;
    QVector<QLabel*> labels;
    void setLine(QPair<int,QString>);
    MIK *mik;
    QStackedWidget *stackedWidget;
    void saltoDeLineaTecla();


protected:
    void keyPressEvent(QKeyEvent *event);


private slots:
    void tocarBoton(const QString &mensaje);

    void on_A_Button_clicked();
    void on_B_Button_clicked();
    void on_C_Button_clicked();
    void on_D_Button_clicked();
    void on_E_Button_clicked();
    void on_F_Button_clicked();
    void on_G_Button_clicked();
    void on_H_Button_clicked();
    void on_I_Button_clicked();
    void on_J_Button_clicked();
    void on_K_Button_clicked();
    void on_L_Button_clicked();
    void on_pushButton_W1_pressed();
    void on_pushButton_W2_pressed();
    void on_pushButton_W3_pressed();
    void on_pushButton_grilla_clicked();
    void on_pushButton_back_clicked();

    void on_P01_button_clicked();
    void on_P02_button_clicked();
    void on_P03_button_clicked();
    void on_P04_button_clicked();
    void on_P05_button_clicked();
    void on_P06_button_clicked();
    void on_P07_button_clicked();
    void on_P08_button_clicked();
    void on_P09_button_clicked();
    void on_P10_button_clicked();
    void on_P11_button_clicked();
    void on_P12_button_clicked();
    void on_P13_button_clicked();
    void on_P14_button_clicked();
    void on_P15_button_clicked();
    void on_P16_button_clicked();
    void on_P17_button_clicked();
    void on_S01_button_clicked();
    void on_S02_button_clicked();
    void on_S03_button_clicked();
    void on_S04_button_clicked();
    void on_pushButton_Del_clicked();
};

#endif // ANDGUI_H
