#ifndef QEK_H
#define QEK_H

#include "Zone.h"
#include <QWidget>

class Botonera;
class Qek : public Zone
{

public:
    explicit Qek(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    void sendMessage();
    QString getName() override;
private:
    Botonera *miBotonera;
};

#endif // QEK_H
