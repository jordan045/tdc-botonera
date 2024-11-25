#include <botoneraSlave.h>

BotoneraSlave::BotoneraSlave(QWidget *parent, QSharedPointer<botoneraMasterReplica> ptr):Botonera(parent), reptr(ptr){
    range_widget->start();
    if(!reptr)
    {
        qDebug()<<"El reptr no se inicializo";
    }
    initConnections();

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
    emit emitCodeToRange(boton);
}

void BotoneraSlave::sendCodeToLabelSelection(QString boton)
{
    emit emitCodeToLabelSelection(boton);
}

void BotoneraSlave::sendCodeToQek(QString boton)
{
    emit emitCodeToQek(boton);
}

void BotoneraSlave::sendCodeToThreat(QString boton)
{
    emit emitCodeToThreat(boton);
}

void BotoneraSlave::sendCodeToCenter(QString boton)
{
    emit emitCodeToCenter(boton);
}

void BotoneraSlave::sendCodeToDisplayMode(QString boton)
{
    emit emitCodeToDisplayMode(boton);
}

void BotoneraSlave::sendCodeToDisplaySelection(QString boton)
{
    emit emitCodeToDisplaySelection(boton);
}

void BotoneraSlave::sendCodeToIcm(QString boton)
{
    emit emitCodeToIcm(boton);
}

void BotoneraSlave::sendMessage()
{
}

QString BotoneraSlave::getOverlay()
{
    return "q";
}

void BotoneraSlave::initConnections()
{
    QObject::connect(this,&BotoneraSlave::emitCodeToRange,reptr.data(),&botoneraMasterReplica::sendCodeToRange);
    QObject::connect(this,&BotoneraSlave::emitCodeToLabelSelection,reptr.data(),&botoneraMasterReplica::sendCodeToLabelSelection);
    QObject::connect(this,&BotoneraSlave::emitCodeToQek,reptr.data(),&botoneraMasterReplica::sendCodeToQekSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToThreat,reptr.data(),&botoneraMasterReplica::sendCodeToThreat);
    QObject::connect(this,&BotoneraSlave::emitCodeToCenter,reptr.data(),&botoneraMasterReplica::sendCodeToCenterSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToDisplayMode,reptr.data(),&botoneraMasterReplica::sendCodeToDisplayMode);
    QObject::connect(this,&BotoneraSlave::emitCodeToDisplaySelection,reptr.data(),&botoneraMasterReplica::sendCodeToDisplaySelection);
    QObject::connect(this,&BotoneraSlave::emitCodeToIcm,reptr.data(),&botoneraMasterReplica::sendCodeToIcmSlave);


}
