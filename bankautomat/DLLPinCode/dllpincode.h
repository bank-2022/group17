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
    void vaaraPin();

public slots:
    void returnPinCode(QString);
    void vaaraPinTarkistus();

private:
    //PinCodeEngine * pPinCodeEngine;
    PinWindow * pPinWindow;
    QString cardPin;
    int pinYritysKerta;

};

#endif // DLLPINCODE_H
