#ifndef ZONE_CENTER_H
#define ZONE_CENTER_H

#include <QWidget>

namespace Ui {
class zone_center;
}

class zone_center : public QWidget
{
    Q_OBJECT

public:
    explicit zone_center(QWidget *parent = nullptr);
    ~zone_center();

private:
    Ui::zone_center *ui;
};

#endif // ZONE_CENTER_H
