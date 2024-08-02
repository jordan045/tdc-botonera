#ifndef OVERLAY_360_0001_H
#define OVERLAY_360_0001_H

#include <QWidget>

namespace Ui {
class overlay_360_0001;
}

class overlay_360_0001 : public QWidget
{
    Q_OBJECT

public:
    explicit overlay_360_0001(QWidget *parent = nullptr);
    ~overlay_360_0001();

private:
    Ui::overlay_360_0001 *ui;
};

#endif // OVERLAY_360_0001_H
