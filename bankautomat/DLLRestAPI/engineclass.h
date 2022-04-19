#ifndef ENGINECLASS_H
#define ENGINECLASS_H

#include <myurl.h>

#include <QString>
#include <QDebug>
#include <QObject>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class EngineClass : public QObject
{
    Q_OBJECT
public:
    EngineClass(QObject *parent = nullptr);
    void loginRequest(QString, QString);
    void GetKorttiInfo(QString);
    void nosta(QString,float,QString,QString);
protected:

private:
    MyURL *objectMyUrl;
    QString base_url;
    QByteArray response_data;

    //Login variables
    QNetworkAccessManager *loginManager;
    QNetworkReply *loginReply;
    QByteArray token; //Token used for http requests
    //QString _testKorttiNum = "52255BC";
    //QString _testPin = "0000";

    //Info req variables
    QNetworkAccessManager *korttiInfoManager;
    QNetworkReply *korttiInfoReply;

    //Nosta variables
    QNetworkAccessManager *nostaManager;
    QNetworkReply *nostaReply;

private slots:
    void loginSlot(QNetworkReply *loginReply);
    void korttiInfoSlot(QNetworkReply *korttiInfoReply);
    void nostaSlot(QNetworkReply *nostaReply);
signals:
    void sendKorttiInfoToDLL(QString);
};

#endif // ENGINECLASS_H
