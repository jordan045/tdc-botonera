#include "mik.h"

MIK::MIK(Botonera *b){
    miBotonera = b;
    tab = 1;
}

void MIK::selLinea(int t){
    int i= t;

    while (i != tab) {
        if(tab > 13){
            tab = 0;
        }
        else{
            //llamo a estado
            //qDebug()<< "Linea";
            miBotonera->sendCharToMIK('S');//deberia ir el salto de linea
            tab++;
        }
    }
    tab = t;
}

void MIK::press(QChar c){

}

void MIK::release(QChar c){

}
