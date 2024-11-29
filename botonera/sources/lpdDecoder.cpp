#include "decoderLPD.h"
#include "markerMessage.h"
#include "cursorMessage.h"
#include "qdebug.h"
#include "decenteredimage.h"
#include <QByteArray>
#include <QFile>

decoderLPD::decoderLPD(QObject *parent) : QObject(parent)
{
}

void decoderLPD::processLPDMessage(QByteArray data, int wordLength)
{
    QList<MarkerMessage> markerList;
    QList<CursorMessage> cursorList;

    QFile file(":/binary/LPD2_inverted.bin");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "No se pudo abrir el archivo";
        return;
    }

    // Leer todo el archivo y enviarlo a processMessage
    QByteArray messageArray = file.readAll().mid(3);
    processMessage(messageArray, 255, markerList, cursorList);

    // for(MarkerMessage &marker: markerList){
    //     marker.toString();
    // }
    // for(CursorMessage &cursor: cursorList){
    //     cursor.toString();
    // }

    emit processResult(markerList, cursorList);

    file.close();
}

void decoderLPD::processMessage(QByteArray &message, int wordLength, QList<MarkerMessage> &markerList, QList<CursorMessage> &cursorList)
{
    markerList.clear();
    cursorList.clear();

    int offset = 0; // Marca siempre el inicio del próximo mensaje

    while (offset < wordLength) {
        char id = message[offset + 2] & 0x0F; //Ultimos 4 bits

        if(id == MARKER_ID){ //Marker Message
            bool is_valid = message[offset + 2] & 0x10;

            if (!is_valid) { // Saltar hasta un EOMM, que está en el tercer campo
                while (message[offset + 2] != END_OF_MARKER_MESSAGE){
                    offset = offset + WORD_LENGTH;
                }
                offset = offset + WORD_LENGTH;
                continue;
            }

            bool PV = message[offset + 2] & 0x20; //5 posición
            bool AP = message[offset + 5] & 0x20; //5 posición
            bool LS = message[offset + 2] & 0x30; //6 posición

            QByteArray mainSymbol;
            QByteArray courseIndicator;
            QByteArray amplInfo;
            QByteArray linkStatus;
            QByteArray trackNumber;

            // Extraer otros campos como QByteArray
            mainSymbol = QByteArray(1, message[offset + 6]);

            if(!PV){ //Si PV es 0, mostrar punto, es mensaje largo!
                courseIndicator = QByteArray(1, message[offset + 7]);

                amplInfo = QByteArray(2, 0x0);
                amplInfo[0] = message[offset + 8];
                amplInfo[1] = message[offset + 9];

                linkStatus = QByteArray(1, message[offset + 10]);

                trackNumber = QByteArray(4,0x0);
                for (int i = 0; i < 4; ++i) {
                    trackNumber[i] = message[offset + 11 + i];
                }
            }

            QPair<qfloat16,qfloat16> coordinates = getCoords(message,offset);

            MarkerMessage newMarker(
                coordinates,
                mainSymbol,
                courseIndicator,
                amplInfo,
                linkStatus,
                trackNumber,
                PV, AP, LS
                );
            markerList.append(newMarker);

            if(!PV) offset += LONG_MESSAGE_LENGTH;
            else offset += SHORT_MESSAGE_LENGTH;
        }
        else if(id == CURSOR_ID){ //Cursor Message
            bool is_valid = message[offset + 2] & 0x10;

            if (!is_valid) { // Saltar 12 bytes
                offset += CURSOR_MESSAGE_LENGTH;
                continue;
            }

            //Extraer ángulo y longitud del cursor
            qfloat16 cursorAngle;
            qfloat16 cursorLength;

            // Extraer los 12 bits del mensaje para el ángulo
            unsigned int angleRaw = 0;
            angleRaw |= (message[offset] & 0xFF) << 4;  // Bits 24-17
            angleRaw |= (message[offset + 1] & 0xF0) >> 4; // Bits 16-13

            // Determinar el signo
            bool isNegative = angleRaw & 0x800; // Bit 24 (MSB de 12 bits)
            if (isNegative) {
                // Si es negativo, tomar el complemento a dos para obtener la magnitud
                angleRaw = (~angleRaw + 1) & 0xFFF; // Limitar a 12 bits
                cursorAngle = -static_cast<qfloat16>(angleRaw) * static_cast<qfloat16>(180.0f) / static_cast<qfloat16>(2048.0f); // Escalar a grados
            } else {
                // Si es positivo, calcular directamente
                cursorAngle = static_cast<qfloat16>(angleRaw) * static_cast<qfloat16>(180.0f) / static_cast<qfloat16>(2048.0f); // Escalar a grados
            }

            // Extraer los 17 bits del mensaje para la longitud del cursor
            unsigned int lengthRaw = 0;
            lengthRaw |= (message[offset + 3] & 0xFF) << 9;  // Bits 22-15
            lengthRaw |= (message[offset + 4] & 0xFF) << 1;  // Bits 14-8
            lengthRaw |= (message[offset + 5] & 0x80) >> 7;  // Bit 7

            // Convertir a valor decimal (escala en la unidad específica)
            cursorLength = static_cast<qfloat16>(lengthRaw) / static_cast<qfloat16>(256.0f);

            //Extraer el tipo de linea en 3 bits
            int lineType = message[offset + 5] & 0x70;

            QPair<qfloat16,qfloat16> coordinates = getCoords(message,offset);

            CursorMessage newCursor(
                coordinates,
                cursorAngle,
                cursorLength,
                lineType
            );
            cursorList.append(newCursor);
            offset += CURSOR_MESSAGE_LENGTH;
        }
        else if(id == DECENTERED_ID){ //Decentered Image
            bool is_valid = message[offset + 2] & 0x10;
            if (!is_valid) { // Saltar 12 bytes
                offset += DECENTERED_MESSAGE_LENGTH;
                continue;
            }

            QPair<qfloat16,qfloat16> coordinates = getCoords(message,offset);
            DecenteredImage newDecentered(
                coordinates
            );
            offset += DECENTERED_MESSAGE_LENGTH;
        }
        else{
            qDebug() << offset;
            break;
        }
    }
}

QPair<qfloat16,qfloat16> decoderLPD::getCoords(QByteArray message, int offset){
    qfloat16 coordX = 0.0f;
    qfloat16 coordY = 0.0f;

    // Extraer coordenada X (17 bits desde los primeros 3 bytes a partir de offset)
    unsigned int coordXRaw = 0;
    coordXRaw |= (message[offset] & 0xFF) << 9;  // Bits 24-16
    coordXRaw |= (message[offset + 1] & 0xFF) << 1; // Bits 15-8
    coordXRaw |= (message[offset + 2] & 0x80) >> 7; // Bit 7 (último bit relevante para 17 bits)

    // Determinar signo y convertir a valor real
    if (coordXRaw & 0x10000) { // Si el bit más significativo (24 en términos de 17 bits) es 1
        coordXRaw = (~coordXRaw + 1) & 0x1FFFF; // Complemento a dos para 17 bits
        coordX = -static_cast<qfloat16>(coordXRaw) / static_cast<qfloat16>(256.0f); // Escalar por DM
    } else {
        coordX = static_cast<qfloat16>(coordXRaw) / static_cast<qfloat16>(256.0f); // Escalar por DM
    }

    // Extraer coordenada Y (17 bits desde los siguientes 3 bytes a partir de offset + 3)
    unsigned int coordYRaw = 0;
    coordYRaw |= (message[offset + 3] & 0xFF) << 9;  // Bits 24-16
    coordYRaw |= (message[offset + 4] & 0xFF) << 1;  // Bits 15-8
    coordYRaw |= (message[offset + 5] & 0x80) >> 7;  // Bit 7 (último bit relevante para 17 bits)

    // Determinar signo y convertir a valor real
    if (coordYRaw & 0x10000) { // Si el bit más significativo (24 en términos de 17 bits) es 1
        coordYRaw = (~coordYRaw + 1) & 0x1FFFF; // Complemento a dos para 17 bits
        coordY = -static_cast<qfloat16>(coordYRaw) / static_cast<qfloat16>(256.0f); // Escalar por DM
    } else {
        coordY = static_cast<qfloat16>(coordYRaw) / static_cast<qfloat16>(256.0f); // Escalar por DM
    }

    QPair<qfloat16, qfloat16> coordinates(coordX, coordY);
    return coordinates;
}
