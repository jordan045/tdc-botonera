#ifndef ANDGUI_H
#define ANDGUI_H

#include <QWidget>
#include "ui_andGui.h"
#include "andTranslator.h"
#include "QLabel"
// namespace Ui {
// class andGui;
// }

namespace Ui {
    class andGui;
}


class andGui : public QWidget
{
    Q_OBJECT
public:
    explicit andGui(QWidget *parent = nullptr);
    void recibirMensaje(QString entrada);

private:
    Ui::andGui *ui;
    AndTranslator converter;
    QLabel *andLabel;
    QVector<QLabel*> labels;
    void setLine(QPair<int,QString>);
    void verticalTab(int i);
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
    void on_MButton_clicked();
};

#endif // ANDGUI_H
