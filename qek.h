#ifndef QEK_H
#define QEK_H

#include "Zone.h"
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

    private:
        Botonera *miBotonera;
};

#endif // QEK_H
