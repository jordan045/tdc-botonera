#ifndef INFOPANEL_H
#define INFOPANEL_H

#include <QDialog>

namespace Ui {
class infoPanel;
}

class infoPanel : public QDialog
{
    Q_OBJECT

public:
    explicit infoPanel(QWidget *parent = nullptr);
    ~infoPanel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::infoPanel *ui;
};

#endif // INFOPANEL_H
