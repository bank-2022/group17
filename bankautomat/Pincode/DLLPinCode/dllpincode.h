#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "DLLPinCode_global.h"
#include <QDebug>
#include <QObject>
#include "pincodeengine.h"
#include "pinwindow.h"

class DLLPINCODE_EXPORT DLLPinCode : public QObject
{
    Q_OBJECT


public:
    DLLPinCode(QObject * parent = nullptr);
    ~DLLPinCode();
    void openPinWindow();
    void closePinWindow();
signals:
    void sendPinToExe(QString pin);

public slots:
    void returnPinCode(QString);

private:
    PinCodeEngine * pPinCodeEngine;
    PinWindow * pPinWindow;
    QString cardPin;

};

#endif // DLLPINCODE_H
