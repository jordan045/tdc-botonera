#include "decenteredimage.h"
#include "qdebug.h"

DecenteredImage::DecenteredImage(
    QPair<qfloat16, qfloat16> coordinates
    ):
    coordinates(coordinates)
{}

QPair<qfloat16, qfloat16> DecenteredImage::getCoordinates() const {
    return coordinates;
}

void DecenteredImage::toString(){
    qDebug() << "COORDENADAS: " << coordinates.first << " " << coordinates.second;
};
