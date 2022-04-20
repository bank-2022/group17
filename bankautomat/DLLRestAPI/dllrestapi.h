#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include <QDebug>
#include <QObject>
#include "engineclass.h"


class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI(QObject *parent = nullptr);
    ~DLLRestAPI();
    void login();
    void putTili();
    void postTilitapahtuma();
    void getTilitapahtuma();
private:
    EngineClass *pEngineClass;
signals:
    void sendKorttiInfoToExe(QString);
public slots:
    void recvKorttiInfoFromEngine(QString);
    void recvGenerateKorttiInfoCommand(QString);
    void recvLoginCommand(QString, QString);
    void recvNostaCommand(QString,float,QString,QString);
    void recvTalletaCommand(QString,float,QString,QString);
};

#endif // DLLRESTAPI_H
