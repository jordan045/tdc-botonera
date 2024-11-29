#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>

class ConnectionScreen : public QDialog {
    Q_OBJECT
public:
    explicit ConnectionScreen(QWidget *parent = nullptr);
     // Destructor explícito
};

#endif // CONNECTIONSCREEN_H
