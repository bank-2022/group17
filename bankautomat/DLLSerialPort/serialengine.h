#ifndef SERIALENGINE_H
#define SERIALENGINE_H

#include <QObject>
#include <QString>
//#include <QIODevice>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo> //Debug only
#include <QDebug>
//#include "stdlib.h"

class SerialEngine : public QObject
{
    Q_OBJECT

public:
    void openSerialPort();
    void closeSerialPort();
    QString returnCardSerialNumber();

private:
    QSerialPortInfo *objectInfo; //Debug only
    QSerialPort *objectQSerialPort;
    QString *list;
    QString cardSerialNumber;

private slots:
    void readPort();

signals:
    void readySignal();


};

#endif // SERIALENGINE_H

