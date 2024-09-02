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

private slots:
    void tocarBoton(const QString &mensaje);

};

#endif // ANDGUI_H
