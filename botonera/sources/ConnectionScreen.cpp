#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>

class ConnectionScreen : public QDialog {
    Q_OBJECT
public:
    explicit ConnectionScreen(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Intentando conectar...");
        setModal(true);

        QLabel *label = new QLabel("Esperando conexión con la master...");
        QProgressBar *progressBar = new QProgressBar();
        progressBar->setRange(0, 0); // Barra indeterminada

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        layout->addWidget(progressBar);

        setLayout(layout);
    }


};
