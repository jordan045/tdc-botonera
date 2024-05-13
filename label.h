#ifndef LABEL_H
#define LABEL_H

#include <QWidget>

class label :public QWidget
{
    Q_OBJECT
public:
    explicit label(QWidget *parent = nullptr);
};

#endif // LABEL_H
