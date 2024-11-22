#ifndef CURSORMESSAGE_H
#define CURSORMESSAGE_H

#include <qpair.h>
#include <qfloat16.h>
#include <qstring.h>

class CursorMessage
{
private:
    QPair<qfloat16, qfloat16> coordinates;
    qfloat16 cursorAngle;
    qfloat16 cursorLength;
    int lineType;
public:
    // Constructor
    CursorMessage(
        QPair<qfloat16, qfloat16> coordinates,
        qfloat16 cursorAngle,
        qfloat16 cursorLength,
        int lineType);

    // Getters
    QPair<qfloat16, qfloat16> getCoordinates() const;
    qfloat16 getCursorAngle() const;
    qfloat16 getCursorLength() const;
    int getLineType() const;

    // Setters
    void setCoordinates(QPair<qfloat16, qfloat16> coordinates);
    void setCursorAngle(qfloat16 cursorAngle);
    void setCursorLength(qfloat16 cursorLength);
    void setLineType(int lineType);

    void toString();

};

#endif // CURSORMESSAGE_H
