#include "dllserialport.h"


void DLLSerialPort::interfaceFunctionOpenSerialPort()
{
    if(isObjectSerialEngineCreated!='y'){
        objectSerialEngine = new SerialEngine;
        isObjectSerialEngineCreated='y';
    }
    connect(objectSerialEngine,SIGNAL(readySignal()), this, SLOT(dllSerialPortSlot()));
    objectSerialEngine->openSerialPort();
}

void DLLSerialPort::interfaceFunctionCloseSerialPort()
{
    isObjectSerialEngineCreated=0;
    disconnect(objectSerialEngine,SIGNAL(readySignal()), this, SIGNAL(dataReadDone()));
    objectSerialEngine->closeSerialPort();
    delete objectSerialEngine;
}

QString DLLSerialPort::interfaceFunctionReturnCardSerialNumber()
{
    dllCardSerialNumber = objectSerialEngine->returnCardSerialNumber();
    return dllCardSerialNumber;
}

void DLLSerialPort::interfaceSetSerialPortManually(QString port)
{
    if(isObjectSerialEngineCreated!='y'){
        objectSerialEngine = new SerialEngine;
        isObjectSerialEngineCreated='y';
        }
    objectSerialEngine->setSerialPortManually(port);



}

void DLLSerialPort::dllSerialPortSlot()
{
    //qDebug() << "dataReadDone";
    emit dataReadDone();
}
