#ifndef INFOMESSAGE_H
#define INFOMESSAGE_H

#include <QDialog>

namespace Ui {
class infoMessage;
}

class infoMessage : public QDialog
{
    Q_OBJECT

public:
    explicit infoMessage(QWidget *parent = nullptr);
    ~infoMessage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::infoMessage *ui;
};

#endif // INFOMESSAGE_H
