#ifndef ANDGUI_H
#define ANDGUI_H

#include <QWidget>
#include "ui_andGui.h"
#include "andTranslator.h"
#include "QLabel"
// namespace Ui {
// class andGui;
// }

class andGui : public QWidget
{
    Q_OBJECT
public:
    explicit andGui(QWidget *parent = nullptr);
    void recibirMensaje(QString entrada);
    ~andGui();
private:
    // Ui::andGui *ui;
    AndTranslator converter;
    QLabel *label;
};

#endif // ANDGUI_H
