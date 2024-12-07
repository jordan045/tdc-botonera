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
    emit emitCodeToRange(boton);
}

void BotoneraSlave::removeCodeFromLabelSelection(QString boton)
{
    emit emitCodeToLabelSelection(boton);
}

void BotoneraSlave::removeCodeFromQek(QString boton)
{
    emit emitRemoveFromQek(boton);
}

void BotoneraSlave::removeCodeFromThreat(QString boton)
{
    emit emitCodeToThreat(boton);
}

void BotoneraSlave::removeCodeFromCenter(QString boton)
{
    emit emitRemoveFromCenter(boton);
}

void BotoneraSlave::removeCodeFromDisplayMode(QString boton)
{
    emit emitCodeToDisplayMode(boton);
}

void BotoneraSlave::removeCodeFromDisplaySelection(QString boton)
{
    emit emitCodeToDisplaySelection(boton);
}

void BotoneraSlave::removeCodeFromIcm(QString boton)
{
    emit emitRemoveFromIcm(boton);
}

void BotoneraSlave::setOverlay(QString codigo)
{
    if(overlay == 0)
        overlay = codigo.toInt();
    emit emitCodeToOverlay(codigo);
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

void BotoneraSlave::sendCharToMIK(QString caracter)
{
    emit emitCharToMik(caracter);
}

void BotoneraSlave::sendMessage()
{
}

QString BotoneraSlave::getOverlay()
{
    return "q";
}

void BotoneraSlave::synchronize()
{
    reptr.data()->synchronize();
}



void BotoneraSlave::initConnections()
{
    //Conectar los sendCodeTo.
    QObject::connect(this,&BotoneraSlave::emitCodeToRange,reptr.data(),&botoneraMasterReplica::sendCodeToRangeFromSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToLabelSelection,reptr.data(),&botoneraMasterReplica::sendCodeToLabelSelectionFromSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToQek,reptr.data(),&botoneraMasterReplica::sendCodeToQekSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToThreat,reptr.data(),&botoneraMasterReplica::sendCodeToThreatFromSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToCenter,reptr.data(),&botoneraMasterReplica::sendCodeToCenterSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToDisplayMode,reptr.data(),&botoneraMasterReplica::sendCodeToDisplayModeFromSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToDisplaySelection,reptr.data(),&botoneraMasterReplica::sendCodeToDisplaySelectionFromSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToIcm,reptr.data(),&botoneraMasterReplica::sendCodeToIcmSlave);
    QObject::connect(this,&BotoneraSlave::emitCodeToOverlay,reptr.data(),&botoneraMasterReplica::sendCodeToOverlaySlave);
    QObject::connect(this,&BotoneraSlave::emitCharToMik,reptr.data(),&botoneraMasterReplica::sendCharToMIKSlave);

    //Conecta los removeFrom


    QObject::connect(this,&BotoneraSlave::emitRemoveFromQek,reptr.data(),&botoneraMasterReplica::removeCodeFromQekSlave);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromCenter,reptr.data(),&botoneraMasterReplica::removeCodeFromCenterSlave);
    QObject::connect(this,&BotoneraSlave::emitRemoveFromIcm,reptr.data(),&botoneraMasterReplica::removeCodeFromIcmSlave);

    QObject::connect(reptr.data(),&botoneraMasterReplica::changeRangeSlave,this, &BotoneraSlave::changeRange);
    QObject::connect(reptr.data(),&botoneraMasterReplica::changeThreatAssesmentSlave,this, &BotoneraSlave::changeThreat);
    QObject::connect(reptr.data(),&botoneraMasterReplica::changeDisplaySelectionSlave,this, &BotoneraSlave::changeDisplaySelection);
    QObject::connect(reptr.data(),&botoneraMasterReplica::changeLabelSelectionSlave,this, &BotoneraSlave::changeLabelSelection);
    QObject::connect(reptr.data(),&botoneraMasterReplica::changeDisplayModeSlave,this, &BotoneraSlave::changeDisplayMode);


}

void BotoneraSlave::changeRange(QString boton)
{
    range_widget->interactVisual(boton);
}

void BotoneraSlave::changeThreat(QString boton)
{
    threat_assesment_widget->interactVisual(boton);
}

void BotoneraSlave::changeDisplaySelection(QString boton)
{
    display_selection_widget->interactVisual(boton);
}

void BotoneraSlave::changeLabelSelection(QString boton)
{
    label_selection_widget->interactVisual(boton);
}

void BotoneraSlave::changeDisplayMode(QString boton)
{
    display_mode_widget->interactVisual(boton);
}

