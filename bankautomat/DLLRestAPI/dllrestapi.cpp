#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent) : QObject(parent)
{
    qDebug()<<"DLL luotu";
    pEngineClass = new EngineClass(this);

    connect(pEngineClass, SIGNAL(sendKorttiInfoToDLL(QString)),
            this,SLOT(recvKorttiInfoFromEngine(QString)));
}

DLLRestAPI::~DLLRestAPI()
{
    qDebug()<<"DLL tuhottu";
    disconnect(pEngineClass, SIGNAL(sendKorttiInfoToDLL(QString)),
        this,SLOT(recvKorttiInfoFromEngine));
    delete pEngineClass;
    pEngineClass = nullptr;
}

void DLLRestAPI::login()
{
    pEngineClass->loginRequest();
}

void DLLRestAPI::getKorttiInfo()
{
    pEngineClass->GetKorttiInfo();
}

void DLLRestAPI::recvKorttiInfoFromEngine(QString info)
{
    qDebug()<<"At  DLL restapi SLOT function = recvKorttiInfoFromEngine";
    emit sendKorttiInfoToExe(info);
}
