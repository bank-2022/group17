#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent) : QObject(parent)
{
    qDebug()<<"DLL luotu";
    pEngineClass = new EngineClass(this);

    connect(pEngineClass, SIGNAL(sendKorttiInfoToDLL(QString)),
            this,SLOT(recvKorttiInfoFromEngine(QString)));
    //connect(parent, SIGNAL(generateKorttiInfo(QString)),
    //        this, SLOT(recvGenerateKorttiInfoCommand(QString)));
}

DLLRestAPI::~DLLRestAPI()
{
    qDebug()<<"DLL tuhottu";
    disconnect(pEngineClass, SIGNAL(sendKorttiInfoToDLL(QString)),
        this,SLOT(recvKorttiInfoFromEngine(QString)));
    delete pEngineClass;
    pEngineClass = nullptr;
}

void DLLRestAPI::recvKorttiInfoFromEngine(QString info)
{
    qDebug()<<"At  DLL restapi SLOT function = recvKorttiInfoFromEngine";
    emit sendKorttiInfoToExe(info);
}

void DLLRestAPI::recvGenerateKorttiInfoCommand(QString Korttinumero)
{
    qDebug()<<"Received generatekorttiInfoCommand from exe";
    pEngineClass->GetKorttiInfo(Korttinumero);

}

void DLLRestAPI::recvLoginCommand(QString Korttinumero, QString Pin)
{
    pEngineClass->loginRequest(Korttinumero,Pin);
    qDebug()<<"Received loginCommand from exe";
}

void DLLRestAPI::recvNostaCommand(QString idtili, float amount, QString Korttinumero, QString idKortti)
{
    pEngineClass->nosta(idtili,amount,Korttinumero,idKortti);
    qDebug()<<"Received nostaCommand from exe";
}
