#include <botoneraSlave.h>

BotoneraSlave::BotoneraSlave(QWidget *parent):Botonera(parent){
    range_widget->start();
}

void BotoneraSlave::removeCodeFromRange(QString boton)
{
    //Acá seria mandarle a la BotoneraMaster que elimine codeFromRange con el boton que le mando
    //Investigar
}

void BotoneraSlave::removeCodeFromLabelSelection(QString boton)
{

}

void BotoneraSlave::removeCodeFromQek(QString boton)
{

}

void BotoneraSlave::removeCodeFromThreat(QString boton)
{

}

void BotoneraSlave::removeCodeFromCenter(QString boton)
{

}

void BotoneraSlave::removeCodeFromDisplayMode(QString boton)
{

}

void BotoneraSlave::removeCodeFromDisplaySelection(QString boton)
{

}

void BotoneraSlave::removeCodeFromIcm(QString boton)
{

}

void BotoneraSlave::setOverlay(QString codigo)
{
    overlay =codigo.toInt();
}

void BotoneraSlave::sendCodeToRange(QString boton)
{

}

void BotoneraSlave::sendCodeToLabelSelection(QString boton)
{

}

void BotoneraSlave::sendCodeToQek(QString boton)
{

}

void BotoneraSlave::sendCodeToThreat(QString boton)
{

}

void BotoneraSlave::sendCodeToCenter(QString boton)
{

}

void BotoneraSlave::sendCodeToDisplayMode(QString boton)
{

}

void BotoneraSlave::sendCodeToDisplaySelection(QString boton)
{

}

void BotoneraSlave::sendCodeToIcm(QString boton)
{

}

void BotoneraSlave::sendMessage()
{

}

QString BotoneraSlave::getOverlay()
{

}
