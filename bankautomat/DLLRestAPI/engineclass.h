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
    void loginRequest();
    void GetKorttiInfo();
protected:

private:
    MyURL *objectMyUrl;
    QString base_url;
    QByteArray response_data;

    //Login variables
    QNetworkAccessManager *loginManager;
    QNetworkReply *loginReply;
    QByteArray token; //Token used for http requests
    QString _testKorttiNum = "901234";
    QString _testPin = "1234";

    //Info req variables
    QNetworkAccessManager *korttiInfoManager;
    QNetworkReply *korttiInfoReply;
private slots:
    void loginSlot(QNetworkReply *loginReply);
    void korttiInfoSlot(QNetworkReply *korttiInfoReply);
};

#endif // ENGINECLASS_H
