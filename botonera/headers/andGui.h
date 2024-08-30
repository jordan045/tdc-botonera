#ifndef ANDGUI_H
#define ANDGUI_H

#include <QWidget>
#include "ui_andGui.h"

namespace Ui {
    class andGui;
}

class andGui : public QWidget
{
    Q_OBJECT
public:
    explicit andGui(QWidget *parent = nullptr);
    ~andGui();
private:
    Ui::andGui *ui;
};

#endif // ANDGUI_H
