#ifndef DISPLAY_MODE_H
#define DISPLAY_MODE_H

#include <QWidget>

class display_mode:public QWidget
{
    Q_OBJECT
public:
   explicit display_mode(QWidget *parent = nullptr);
};

#endif // DISPLAY_MODE_H
