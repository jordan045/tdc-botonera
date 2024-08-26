#ifndef BITARRAYUTILS_H
#define BITARRAYUTILS_H

#include <QBitArray>
#include <QString>

class BitArrayUtils {
public:
    static QBitArray qBitArrayfromString(const QString &bitString);
};

#endif // BITARRAYUTILS_H
