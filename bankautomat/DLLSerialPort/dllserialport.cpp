#include "dllserialport.h"


DLLSerialPort::DLLSerialPort()
{
    objectSerialEngine = new SerialEngine;
    objectSerialEngine->openSerialPort();
}

DLLSerialPort::~DLLSerialPort()
{
    objectSerialEngine->closeSerialPort();
    delete objectSerialEngine;
}

void DLLSerialPort::interfaceFunctionOpenSerialPort()
{
    connect(objectSerialEngine,SIGNAL(readySignal()), this, SLOT(dllSerialPortSlot()));
    qDebug()<<"Serial Port - signal connected";
}

void DLLSerialPort::interfaceFunctionCloseSerialPort()
{
    disconnect(objectSerialEngine,SIGNAL(readySignal()), this, SIGNAL(dataReadDone()));
    qDebug()<<"Serial Port - signal disconnected";
}

QString DLLSerialPort::interfaceFunctionReturnCardSerialNumber()
{
    dllCardSerialNumber = objectSerialEngine->returnCardSerialNumber();
    return dllCardSerialNumber;
}

void DLLSerialPort::interfaceSetSerialPortManually(QString port)
{
    objectSerialEngine->setSerialPortManually(port);

}

void DLLSerialPort::dllSerialPortSlot()
{
    emit dataReadDone();
}
