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
    emit emitRemoveFromRange(boton);
}

void BotoneraSlave::removeCodeFromLabelSelection(QString boton)
{
    emit emitRemoveFromLabelSelection(boton);
}

void BotoneraSlave::removeCodeFromQek(QString boton)
{
    emit emitRemoveFromQek(boton);
}

void BotoneraSlave::removeCodeFromThreat(QString boton)
{
    emit emitRemoveFromThreat(boton);
}

void BotoneraSlave::removeCodeFromCenter(QString boton)
{
    emit emitRemoveFromCenter(boton);
}

void BotoneraSlave::removeCodeFromDisplayMode(QString boton)
{
    emit emitRemoveFromDisplayMode(boton);
}

void BotoneraSlave::removeCodeFromDisplaySelection(QString boton)
{
    emit emitRemoveFromDisplaySelection(boton);
}

void BotoneraSlave::removeCodeFromIcm(QString boton)
{
    emit emitRemoveFromIcm(boton);
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
    //Conectar los sendCodeTo.
    QObject::connect(this,&BotoneraSlave::emitCodeToRange,reptr.data(),&botoneraMasterReplica::sendCodeToRange);
    QObject::connect(this,&BotoneraSlave::emitCodeToLabelSelection,reptr.data(),&botoneraMasterReplica::sendCodeToLabelSelection);
    QObject::connect(this,&BotoneraSlave::emitCodeToQek,reptr.data(),&botoneraMasterReplica::sendCodeToQekSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToThreat,reptr.data(),&botoneraMasterReplica::sendCodeToThreat);
    QObject::connect(this,&BotoneraSlave::emitCodeToCenter,reptr.data(),&botoneraMasterReplica::sendCodeToCenterSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToDisplayMode,reptr.data(),&botoneraMasterReplica::sendCodeToDisplayMode);
    QObject::connect(this,&BotoneraSlave::emitCodeToDisplaySelection,reptr.data(),&botoneraMasterReplica::sendCodeToDisplaySelection);
    QObject::connect(this,&BotoneraSlave::emitCodeToIcm,reptr.data(),&botoneraMasterReplica::sendCodeToIcmSlave);

    //Conecta los removeFrom
    QObject::connect(this,&BotoneraSlave::emitRemoveFromRange,reptr.data(),&botoneraMasterReplica::removeCodeFromRange);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromLabelSelection,reptr.data(),&botoneraMasterReplica::removeCodeFromLabelSelection);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromQek,reptr.data(),&botoneraMasterReplica::removeCodeFromQekSlave);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromThreat,reptr.data(),&botoneraMasterReplica::removeCodeFromThreat);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromCenter,reptr.data(),&botoneraMasterReplica::removeCodeFromCenterSlave);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromDisplayMode,reptr.data(),&botoneraMasterReplica::removeCodeFromDisplayMode);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromDisplaySelection,reptr.data(),&botoneraMasterReplica::removeCodeFromDisplaySelection);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromIcm,reptr.data(),&botoneraMasterReplica::removeCodeFromIcmSlave);



}
