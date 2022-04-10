#include "engineclass.h"

EngineClass::EngineClass(QObject *parent) : QObject(parent)
{
    objectMyUrl = new MyURL;
    base_url = objectMyUrl->getBase_url();
}

void EngineClass::loginhttp()
{
    //qDebug()<<"base_url"+base_url;
    QJsonObject jsonObj;
    jsonObj.insert("idKortti", _testID);
    jsonObj.insert("pin", _testPin);


    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void EngineClass::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    token="Bearer "+response_data;
}
