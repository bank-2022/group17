#ifndef SERIALENGINE_H
#define SERIALENGINE_H

#include <QObject>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class SerialEngine : public QObject
{
    Q_OBJECT

public:
    void openSerialPort();
    void closeSerialPort();
    QString returnCardSerialNumber();
    void setSerialPortManually(QString port);   //Optional

private:
    QSerialPortInfo *objectInfo;
    QSerialPort *objectQSerialPort;
    QString *list;
    QString cardSerialNumber;
    QString manualSerialPort;

private slots:
    void readPort();

signals:
    void readySignal();


};

#endif // SERIALENGINE_H

