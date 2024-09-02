#ifndef ANDTRANSLATOR_H
#define ANDTRANSLATOR_H

#include <QObject>
#include <QString>

class AndTranslator:public QObject
{
    Q_OBJECT
public:
    explicit AndTranslator(QObject *parent = nullptr);

    // Método para convertir una cadena binaria a un carácter
    QString binaryToChar(const QString &binaryString) const;

signals:
    void conversionResult(const QString &result);

public slots:
    void processBinaryString(const QString &binaryString);
};
#endif // ANDTRANSLATOR_H


