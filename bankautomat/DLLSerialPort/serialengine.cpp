#include "serialengine.h"

void SerialEngine::openSerialPort() //Read the serial port data and make signal
{
    int portSize=objectInfo->availablePorts().length();
    QString currentPortToUse;
    qDebug() << portSize << "Serial port - ports found:";


    for(const QSerialPortInfo &info : objectInfo->availablePorts()){
        qDebug() << info.portName();
        currentPortToUse = info.portName();
    }

    objectQSerialPort = new QSerialPort(this);
    qDebug() << "Serial port - using serial port: " << currentPortToUse;
    objectQSerialPort->setPortName(currentPortToUse);
    objectQSerialPort->setBaudRate(QSerialPort::Baud9600);
    objectQSerialPort->setDataBits(QSerialPort::Data8);
    objectQSerialPort->setParity(QSerialPort::NoParity);
    objectQSerialPort->setStopBits(QSerialPort::OneStop);
    objectQSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    objectQSerialPort->open(QIODevice::ReadOnly);
    objectQSerialPort->write("ok*");

    //Connect card
    connect(objectQSerialPort,SIGNAL(readyRead()),
            this, SLOT(readPort()));

}

void SerialEngine::closeSerialPort()
{
    disconnect(objectQSerialPort,SIGNAL(readyRead()),
               this, SLOT(readPort()));
    delete objectQSerialPort;
    qDebug() << "Serial port - card signal disconnected";
}

QString SerialEngine::returnCardSerialNumber()
{
    qDebug() << "Serial port - card serial number = " << cardSerialNumber;
    return cardSerialNumber;
}

void SerialEngine::setSerialPortManually(QString port)
{
    qDebug() << "Serial port - port changed to: " << port;
    objectQSerialPort->setPortName(port);
}

void SerialEngine::readPort()
{
    QByteArray byteArray;
    byteArray=objectQSerialPort->readAll();

    if(byteArray=="")
        qDebug() << "Serial port - can't read card value...";
    else
    {
        //qDebug() << "Serial port - signal read: " << byteArray; //Full card number data

        QByteArray slicedByteArray = byteArray.mid(3,10);
        cardSerialNumber=slicedByteArray;
        qDebug() << "Serial port - card serial number = " << slicedByteArray; //Shows only card number
        emit readySignal();
    }

}
