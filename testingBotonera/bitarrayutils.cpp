#include "bitarrayutils.h"

QBitArray BitArrayUtils::qBitArrayfromString(const QString &bitString) {
    int size = bitString.size();
    QBitArray bitArray(size);

    for (int i = 0; i < size; ++i) {
        bitArray.setBit(i, bitString[i] == '1');
    }

    return bitArray;
}
