#ifndef OVERLAY_360_0010_H
#define OVERLAY_360_0010_H

#include <QWidget>

namespace Ui {
class overlay_360_0010;
}

class overlay_360_0010 : public QWidget
{
    Q_OBJECT

public:
    explicit overlay_360_0010(QWidget *parent = nullptr);
    ~overlay_360_0010();

private:
    Ui::overlay_360_0010 *ui;
};

#endif // OVERLAY_360_0010_H
