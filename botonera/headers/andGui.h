#ifndef ANDGUI_H
#define ANDGUI_H

#include <QWidget>
#include <QKeyEvent>

#include "qstackedwidget.h"
#include "sources/mik.h"
#include "ui_andGui.h"
#include "andTranslator.h"
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
    explicit andGui(QWidget *parent = nullptr,Botonera *b = nullptr);

private:
    Botonera *miBotonera;
    Ui::andGui *ui;
    Ui::andGrilla *grilla;
    AndTranslator converter;
    QVector<QLabel*> labels;
    void setLine(QPair<int,QString>);
    MIK *mik;
    QStackedWidget *stackedWidget;

protected:
    void keyReleaseEvent(QKeyEvent *event);
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
};

#endif // ANDGUI_H
