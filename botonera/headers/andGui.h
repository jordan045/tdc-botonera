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

    void on_AButton_clicked();
    void on_BButton_clicked();
    void on_CButton_clicked();
    void on_DButton_clicked();
    void on_EButton_clicked();
    void on_FButton_clicked();
    void on_GButton_clicked();
    void on_HButton_clicked();
    void on_IButton_clicked();
    void on_JButton_clicked();
    void on_KButton_clicked();
    void on_LButton_clicked();
    void on_pushButton_W1_pressed();
    void on_pushButton_W2_pressed();
    void on_pushButton_W3_pressed();
    void on_pushButton_grilla_clicked();
    void on_pushButton_back_clicked();
};

#endif // ANDGUI_H
