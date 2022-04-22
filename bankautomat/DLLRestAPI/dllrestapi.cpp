#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent) : QObject(parent)
{
    qDebug()<<"DLLRestApi luotu";
    pEngineClass = new EngineClass(this);


    connect(pEngineClass, SIGNAL(sendKorttiInfoToDLL(QString)),
            this,SLOT(recvKorttiInfoFromEngine(QString)));
    connect(pEngineClass, SIGNAL(sendTilitapahtumatToDLL(QString)),
            this,SLOT(recvTilitapahtumatFromEngine(QString)));
    connect(pEngineClass,SIGNAL(sendLoginResult(bool)),this,SLOT(recvLoginResultFromEngine(bool)));
}

DLLRestAPI::~DLLRestAPI()
{
    qDebug()<<"DLL tuhottu";
    disconnect(pEngineClass, SIGNAL(sendKorttiInfoToDLL(QString)),
        this,SLOT(recvKorttiInfoFromEngine(QString)));
    disconnect(pEngineClass, SIGNAL(sendTilitapahtumatToDLL(QString)),
            this,SLOT(recvTilitapahtumatFromEngine(QString)));
    delete pEngineClass;
    pEngineClass = nullptr;
}

void DLLRestAPI::recvGenerateKorttiInfoCommand(QString Korttinumero)
{
    qDebug()<<"Received generatekorttiInfoCommand from exe";
    pEngineClass->getKorttiInfo(Korttinumero);

}

void DLLRestAPI::recvKorttiInfoFromEngine(QString info)
{
    qDebug()<<"At  DLL restapi SLOT function = recvKorttiInfoFromEngine";
    emit sendKorttiInfoToExe(info);
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

void DLLRestAPI::recvTalletaCommand(QString idtili, float amount, QString Korttinumero, QString idKortti)
{
    pEngineClass->talleta(idtili,amount,Korttinumero,idKortti);
    qDebug()<<"Received talletaCommand from exe";
}

void DLLRestAPI::recvGetTilitapahtumatCommand(QString idtili)
{
    pEngineClass->getTilitapahtumat(idtili);
    qDebug()<<"Received getTilitapahtumatCommand from exe";
}

void DLLRestAPI::recvTilitapahtumatFromEngine(QString tilitapahtumat)
{
    qDebug()<<"At DLL restapi SLOT function = recvTilitapahtumatFromEngine";
    emit sendTilitapahtumatToExe(tilitapahtumat);
}

void DLLRestAPI::recvLoginResultFromEngine(bool result)
{
    qDebug()<<"At DLL restapi SLOT function = recvLoginResultFromEngine";
    emit sendLoginResultToExe(result);
}
