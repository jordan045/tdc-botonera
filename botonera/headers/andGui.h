#ifndef ANDGUI_H
#define ANDGUI_H

#include <QWidget>

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
    explicit andGui(QWidget *parent = nullptr);
    void recibirMensaje(QString entrada);
    void setBotonera(Botonera *b);

private:
    Botonera *miBotonera;
    Ui::andGui *ui;
    Ui::andGrilla *grilla;
    AndTranslator converter;
    QLabel *andLabel;
    QVector<QLabel*> labels;
    void setLine(QPair<int,QString>);
    void selLinea(int i);
    int tab;



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
};

#endif // ANDGUI_H
