#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "DLLPinCode_global.h"
#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
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
    void timeout();

public slots:
    void returnPinCode(QString);
    void vaaraPinTarkistus();
    void resetTimer();
    void timeOutCheck();

private:
    //PinCodeEngine * pPinCodeEngine;
    PinWindow * pPinWindow;
    QString cardPin;
    int pinYritysKerta;
    QTimer * timer;
    QElapsedTimer elapse_timer;

};

#endif // DLLPINCODE_H
