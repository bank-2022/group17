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
    void loginhttp();
protected:

private:
    QString _testID = "1";
    QString _testPin = "1234";
    MyURL *objectMyUrl;
    QString base_url;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
private slots:
    void loginSlot(QNetworkReply *reply);
};

#endif // ENGINECLASS_H
