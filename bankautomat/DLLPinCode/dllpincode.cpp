#include "dllpincode.h"


DLLPinCode::DLLPinCode(QObject *parent) : QObject(parent)
{
    qDebug()<<"DLL luotu";
    //pPinCodeEngine = new PinCodeEngine;
    pPinWindow = new PinWindow();
    connect(pPinWindow,SIGNAL(sendPinCode(QString)),
             this,SLOT(returnPinCode(QString)));
    pinYritysKerta = 0;

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


void DLLPinCode::vaaraPinTarkistus()
{
    pinYritysKerta++;

    if(pinYritysKerta >= 3){
        emit void vaaraPin();
    }
    qDebug()<<"Pin yrityskerrat: "<<pinYritysKerta;

}



