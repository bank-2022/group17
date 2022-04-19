#include "dllpincode.h"


DLLPinCode::DLLPinCode(QObject *parent) : QObject(parent)
{
    qDebug()<<"DLL luotu";
    //pPinCodeEngine = new PinCodeEngine;
    pPinWindow = new PinWindow();
    connect(pPinWindow,SIGNAL(sendPinCode(QString)),
             this,SLOT(returnPinCode(QString)));

}

DLLPinCode::~DLLPinCode()
{
    qDebug()<<"DLL tuhottu";
    //delete pPinCodeEngine;
    //pPinCodeEngine = nullptr;
    disconnect(pPinWindow,SIGNAL(sendPinCode(QString)),
             this,SLOT(returnPinCode(QString)));
    delete pPinWindow;
    pPinWindow = nullptr;
}

void DLLPinCode::openPinWindow()
{

    pPinWindow->exec();

}

void DLLPinCode::closePinWindow()
{
    pPinWindow->close();

}

void DLLPinCode::returnPinCode(QString pin)
{
    qDebug()<<"SignalPinToExe";
    emit sendPinToExe(pin);
}



