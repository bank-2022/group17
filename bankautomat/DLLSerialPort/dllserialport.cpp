#include "dllserialport.h"


void DLLSerialPort::interfaceFunctionOpenSerialPort()
{
    objectSerialEngine = new SerialEngine;


    connect(objectSerialEngine,SIGNAL(readySignal()), this, SLOT(dllSerialPortSlot()));
    objectSerialEngine->openSerialPort();
}

void DLLSerialPort::interfaceFunctionCloseSerialPort()
{
    disconnect(objectSerialEngine,SIGNAL(readySignal()), this, SIGNAL(dataReadDone()));
    objectSerialEngine->closeSerialPort();
    delete objectSerialEngine;
}

QString DLLSerialPort::interfaceFunctionReturnCardSerialNumber()
{
    dllCardSerialNumber = objectSerialEngine->returnCardSerialNumber();
    return dllCardSerialNumber;
}

void DLLSerialPort::dllSerialPortSlot()
{
    //qDebug() << "dataReadDone";
    emit dataReadDone();
}
