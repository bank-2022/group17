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
    void getKorttiInfo();
    void putTili();
    void postTilitapahtuma();
    void getTilitapahtuma();
    void getAsiakas();
    void getTili();
private:
    EngineClass *pEngineClass;

};

#endif // DLLRESTAPI_H
