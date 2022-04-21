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
private:
    EngineClass *pEngineClass;
signals:
    void sendKorttiInfoToExe(QString);
    void sendTilitapahtumatToExe(QString);
    void sendLoginResultToExe(bool);


public slots:
    void recvGenerateKorttiInfoCommand(QString);
    void recvKorttiInfoFromEngine(QString);
    void recvLoginCommand(QString, QString);
    void recvNostaCommand(QString,float,QString,QString);
    void recvTalletaCommand(QString,float,QString,QString);
    void recvGetTilitapahtumatCommand(QString);
    void recvTilitapahtumatFromEngine(QString);
    void recvLoginResultFromEngine(bool);
};

#endif // DLLRESTAPI_H
