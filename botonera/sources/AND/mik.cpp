#include "mik.h"

MIK::MIK(Botonera *b){
    miBotonera = b;
    actualLine = 0; //Linea actual
}

void MIK::goToLine(int newLine) {
    while (actualLine != newLine) {
        pressKey("SEL");
        pressKey("/");
        actualLine = (actualLine + 1) % SELECTABLE_LINES; // Mantener siempre en el rango [0, 12]
        qDebug() << "actualLine queda asi: " << actualLine;
    }
}


void MIK::pressKey(QString c){
    miBotonera->sendCharToMIK(c);
}

int MIK::getActualLine(){
    return actualLine;
}
