#ifndef QEK_H
#define QEK_H

#include "Zone.h"
#include "qbuttongroup.h"
#include <QWidget>
#include <QtUiTools/QUiLoader>

class Botonera;
class Qek : public Zone
{

public:
    explicit Qek(Botonera *b);
    void sendCode(QString code) override;
    void removeCode(QString code) override;
    void sendMessage();
    QString getName() override;
    void setOverlay(QString o);
private:
    Botonera *miBotonera;
    QString overlay;
    QButtonGroup *qek_group;
};

#endif // QEK_H
