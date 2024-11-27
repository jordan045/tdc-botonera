#ifndef DECENTEREDIMAGE_H
#define DECENTEREDIMAGE_H

#include <qpair.h>
#include <qfloat16.h>

class DecenteredImage
{
private:
    QPair<qfloat16, qfloat16> coordinates;

public:
    DecenteredImage(QPair<qfloat16, qfloat16> coordinates);

    QPair<qfloat16, qfloat16> getCoordinates() const;

    void toString();
};

#endif // DECENTEREDIMAGE_H
