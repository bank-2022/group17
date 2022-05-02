#include "dllpincode.h"


DLLPinCode::DLLPinCode(QObject *parent) : QObject(parent)
{
    qDebug()<<"DLL luotu";
    //pPinCodeEngine = new PinCodeEngine;
    pPinWindow = new PinWindow();
    connect(pPinWindow,SIGNAL(sendPinCode(QString)),
             this,SLOT(returnPinCode(QString)));
    connect(pPinWindow,SIGNAL(timerReset()),
             this,SLOT(resetTimer()));
    pinYritysKerta = 0;



}

DLLPinCode::~DLLPinCode()
{
    qDebug()<<"DLL tuhottu";
    //delete pPinCodeEngine;
    //pPinCodeEngine = nullptr;
    disconnect(pPinWindow,SIGNAL(sendPinCode(QString)),
             this,SLOT(returnPinCode(QString)));
    disconnect(pPinWindow,SIGNAL(timerReset()),
             this,SLOT(resetTimer()));
    disconnect(this->timer,SIGNAL(timeout()),
             this,SLOT(timeOutCheck()));
    delete pPinWindow;
    pPinWindow = nullptr;
    delete timer;
    timer=nullptr;
}

void DLLPinCode::openPinWindow()
{
    pPinWindow->show();
    pPinWindow->setModal(true);
    elapse_timer.start();
    elapse_timer.restart();
    timer=new QTimer(this);
    timer->start(1000);
    connect(this->timer,SIGNAL(timeout()),
             this,SLOT(timeOutCheck()));

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

    if(pinYritysKerta >= 3)
    {
        emit vaaraPin();
        pinYritysKerta = 0;
    }
    else
    {
        qDebug()<<"Pin yrityskerrat: "<<pinYritysKerta;
        openPinWindow();
        pPinWindow->wrongPin();
    }


}

void DLLPinCode::resetTimer()
{
    elapse_timer.restart();
}

void DLLPinCode::timeOutCheck()
{
    if(elapse_timer.elapsed()>10000){
        emit vaaraPin();
    }
}



