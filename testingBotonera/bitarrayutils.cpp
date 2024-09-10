#include "bitarrayutils.h"
#include <QDebug>
#include <QString>

#define WORD_SIZE 24
#define WORD_COUNT 8

QBitArray BitArrayUtils::qBitArrayfromString(const QString &bitString) {
    int size = bitString.size();
    QBitArray bitArray(size);

    for (int i = 0; i < size; ++i) {
        bitArray.setBit(i, bitString[i] == '1');
    }

    return bitArray;
}

QString BitArrayUtils::compareBitArrays(const QBitArray& actual, const QBitArray& expected) {
    QString result = "\nOBS; bit más a la izquierda es posicion 1, segun TMIO V0.3.\n";

    if (actual.size() != 192 || expected.size() != 192) {
        result.append("Error: Bit arrays must be 192 bits long.\n");
        return result;
    }

    for (int wordIndex = 0; wordIndex < WORD_COUNT; ++wordIndex) {
        bool hasDifference = false;
        QString actualWordStr, expectedWordStr;

        for (int bitIndex = 0; bitIndex < WORD_SIZE; ++bitIndex) {
            int actualBit = actual.testBit(wordIndex * WORD_SIZE + bitIndex);
            int expectedBit = expected.testBit(wordIndex * WORD_SIZE + bitIndex);

            actualWordStr.append(actualBit ? '1' : '0');
            expectedWordStr.append(expectedBit ? '1' : '0');

            if (actualBit != expectedBit) {
                hasDifference = true;
            }
        }

        if (hasDifference) {
            result.append(QString("\nDifference in word %1:\n").arg(wordIndex + 1));
            result.append(QString("\tActual  : %1\n").arg(actualWordStr));
            result.append(QString("\tExpected: %1\n").arg(expectedWordStr));
        }
    }

    return result;
}
