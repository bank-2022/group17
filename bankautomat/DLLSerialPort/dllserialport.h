#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "DLLSerialPort_global.h"
#include "serialengine.h"
#include <QDebug>
#include <QObject>

class DLLSERIALPORT_EXPORT DLLSerialPort : public QObject
{
Q_OBJECT
public:
    DLLSerialPort();
    ~DLLSerialPort();
    void interfaceFunctionOpenSerialPort();
    void interfaceFunctionCloseSerialPort();
    QString interfaceFunctionReturnCardSerialNumber();
    void interfaceSetSerialPortManually(QString port);

private:
    QString dllCardSerialNumber;
    SerialEngine *objectSerialEngine;

private slots:
    void dllSerialPortSlot();

signals:
    void dataReadDone();

};

#endif // DLLSERIALPORT_H
