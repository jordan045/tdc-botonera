#ifndef BITARRAYUTILS_H
#define BITARRAYUTILS_H

#include <QBitArray>
#include <QString>

class BitArrayUtils {
public:
    static QBitArray qBitArrayfromString(const QString &bitString);
    static QString compareBitArrays(const QBitArray& actual, const QBitArray& expected);
};

#endif // BITARRAYUTILS_H
