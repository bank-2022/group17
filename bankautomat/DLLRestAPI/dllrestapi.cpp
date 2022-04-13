#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent) : QObject(parent)
{
    qDebug()<<"DLL luotu";
    pEngineClass = new EngineClass;
}

DLLRestAPI::~DLLRestAPI()
{
        qDebug()<<"DLL tuhottu";
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
