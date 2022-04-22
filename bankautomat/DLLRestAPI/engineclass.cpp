#include "engineclass.h"

EngineClass::EngineClass(QObject *parent) : QObject(parent)
{
    objectMyUrl = new MyURL;
    base_url = objectMyUrl->getBase_url();
}

void EngineClass::loginRequest(QString Korttinumero, QString Pin) //Login request to get webtoken
{
    qDebug()<<"base_url"+base_url; //Url debug

    QJsonObject jsonObj; //Json object with login credentials
    jsonObj.insert("Korttinumero", Korttinumero);
    jsonObj.insert("pin", Pin); //Insert login credentials


    QNetworkRequest request((base_url+"/login")); //Url for login request
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); //Data form in body

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    loginReply = loginManager->post(request, QJsonDocument(jsonObj).toJson()); //Login post
}

void EngineClass::getKorttiInfo(QString Korttinumero)
{
    QNetworkRequest request((base_url+"/kortti/info/"+Korttinumero)); //Url for kortti info request
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); //Data form in body
    request.setRawHeader(QByteArray("Authorization"),(token)); //WEBTOKEN

    korttiInfoManager = new QNetworkAccessManager(this);
    connect(korttiInfoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(korttiInfoSlot(QNetworkReply*)));

    korttiInfoReply = korttiInfoManager->get(request);
}

void EngineClass::nosta(QString idtili, float summa, QString Korttinumero, QString idkortti)
{
    QJsonObject jsonObj; //Json object with nosta parameters
    jsonObj.insert("Summa", summa);
    jsonObj.insert("Korttinumero", Korttinumero);
    jsonObj.insert("idkortti", idkortti); //Insert nosta parameters

    QNetworkRequest request((base_url+"/tili/nosta/"+idtili));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); //Data form in body
    request.setRawHeader(QByteArray("Authorization"),(token)); //WEBTOKEN

    nostaManager = new QNetworkAccessManager(this);
    connect(nostaManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(nostaSlot(QNetworkReply*)));

    nostaReply = nostaManager->put(request, QJsonDocument(jsonObj).toJson()); //Nosta put
}

void EngineClass::talleta(QString idtili, float summa, QString Korttinumero, QString idkortti)
{
    QJsonObject jsonObj; //Json object with nosta parameters
    jsonObj.insert("Summa", summa);
    jsonObj.insert("Korttinumero", Korttinumero);
    jsonObj.insert("idkortti", idkortti); //Insert nosta parameters

    QNetworkRequest request((base_url+"/tili/talleta/"+idtili));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); //Data form in body
    request.setRawHeader(QByteArray("Authorization"),(token)); //WEBTOKEN

    talletaManager = new QNetworkAccessManager(this);
    connect(talletaManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(talletaSlot(QNetworkReply*)));

    talletaReply = talletaManager->put(request, QJsonDocument(jsonObj).toJson()); //Nosta put
}

void EngineClass::getTilitapahtumat(QString idtili)
{
    QNetworkRequest request((base_url+"/tilitapahtumat/"+idtili)); //Url for kortti info request
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); //Data form in body
    request.setRawHeader(QByteArray("Authorization"),(token)); //WEBTOKEN

    tilitapahtumatManager = new QNetworkAccessManager(this);
    connect(tilitapahtumatManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(tilitapahtumatSlot(QNetworkReply*)));

    tilitapahtumatReply = tilitapahtumatManager->get(request);
}

void EngineClass::loginSlot(QNetworkReply *loginReply) //Login slot is triggered when finish signal gets raised from login request
{
    response_data=loginReply->readAll(); //Insert reply data to variable
    qDebug()<<response_data; //Debug response data
    if(response_data!="false")
    {
        token="Bearer "+response_data; //Set token to be Bearer token with response data
        emit sendLoginResultToDLL(true);
    }
    else
    {
        qDebug()<<"Login failed";
        emit sendLoginResultToDLL(false);
    }
}

void EngineClass::korttiInfoSlot(QNetworkReply *korttiInfoReply) //Read json data when request finished
{
    response_data=korttiInfoReply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString info;

    foreach (const QJsonValue &value, json_array) { //Read json array
        QJsonObject json_obj = value.toObject();
        info=json_obj["nimi"].toString()+","+json_obj["Korttinumero"].toString()+","+
            QString::number(json_obj["idAsiakas"].toInt())+","+QString::number(json_obj["idKortti"].toInt())+","+
            QString::number(json_obj["idtili"].toInt())+","+QString::number(json_obj["saldo"].toDouble())+"\r";
    }
    qDebug()<<info;

    korttiInfoReply->deleteLater();
    korttiInfoManager->deleteLater();

    emit sendKorttiInfoToDLL(info);
    qDebug()<<"At engine SIGNAL function = sendKorttiInfoToDLL";
}

void EngineClass::nostaSlot(QNetworkReply *nostaReply) //Slot for debug purposes
{
    response_data=nostaReply->readAll(); //Insert reply data to variable
    qDebug()<<response_data; //Debug response data
    qDebug()<<"Nosto slot executed";
    emit sendTransactionFinishedToDLL(); //Emit signal to show transaction is finished
}

void EngineClass::talletaSlot(QNetworkReply *talletaReply)
{
    response_data=talletaReply->readAll();
    qDebug()<<response_data; //Debug response data
    qDebug()<<"Talleta slot executed";
    emit sendTransactionFinishedToDLL(); //Emit signal to show transaction is finished
}

void EngineClass::tilitapahtumatSlot(QNetworkReply *tilitapahtumatReply)
{
    response_data=tilitapahtumatReply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString tilitapahtumat;

    foreach (const QJsonValue &value, json_array) { //Read json array to QString
        QJsonObject json_obj = value.toObject();
        tilitapahtumat+=QString::number(json_obj["idtilitapahtumat"].toInt())+","+json_obj["Kortinnumero"].toString()+","+
             json_obj["Paivays"].toString()+","+json_obj["Tapahtuma"].toString()+","+
             QString::number(json_obj["Summa"].toDouble())+","+QString::number(json_obj["idkortti"].toInt())+","+
             QString::number(json_obj["idtili"].toInt())+"\r";
    }
    qDebug()<<tilitapahtumat; //Debug tilitapahtumat to console

    tilitapahtumatReply->deleteLater();
    tilitapahtumatManager->deleteLater();

    emit sendTilitapahtumatToDLL(tilitapahtumat);
    qDebug()<<"At engine SIGNAL function = sendTilitapahtumatToDLL";
}
