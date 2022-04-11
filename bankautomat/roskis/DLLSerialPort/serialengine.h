#ifndef SERIALENGINE_H
#define SERIALENGINE_H

#include <QObject>
#include <QString>
#include <QIODevice>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class SerialEngine
{
    Q_OBJECT
public:
    SerialEngine();
    void openSerialPort();
    void closeSerialPort();
    QString returnCardSerialNumber();

private:
    QSerialPort *objectQSerialPort;
    QString cardSerialNumber;

private slots:
    void readPort();

signals:
    void readySignal();


};

#endif // SERIALENGINE_H
