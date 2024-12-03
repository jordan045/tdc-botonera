#include "mik.h"

MIK::MIK(Botonera *b){
    miBotonera = b;
    actualLine = 1; //Linea actual
}

void MIK::goToLine(int newLine) {
    // Validar entrada
    if (newLine < 0 || newLine > 11) {
        qWarning() << "Línea inválida solicitada:" << newLine;
        return;
    }

    // Validar estado inicial
    if (actualLine < 0 || actualLine > 11) {
        qWarning() << "Estado de actualLine inválido. Reiniciando a 0.";
        actualLine = 0;
    }

    // Si ya estamos en la línea deseada, no hacer nada
    if (actualLine == newLine) {
        qDebug() << "Ya estás en la línea:" << actualLine;
        return;
    }

    // Avanzar hasta la línea deseada
    while (actualLine != newLine) {
        qDebug() << "Actual:" << actualLine << ", avanzando a:" << (actualLine + 1) % 12;

        pressKey("SEL");
        pressKey("/");
        actualLine = (actualLine + 1) % 12; // Mantener siempre en el rango [0, 12]
    }

    qDebug() << "Línea alcanzada:" << actualLine;
}


void MIK::pressKey(QString c){
    miBotonera->sendCharToMIK(c);
}

int MIK::getActualLine(){
    return actualLine;
}
