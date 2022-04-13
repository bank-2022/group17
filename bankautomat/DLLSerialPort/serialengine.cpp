#include "serialengine.h"

void SerialEngine::openSerialPort() //Read the serial port data and make signal
{
    int portSize=objectInfo->availablePorts().length();
    QString currentPortToUse;
    qDebug() << portSize << "serial ports found:";

    if(manualSerialPort=="")//Uses the last port available
    {
        for(const QSerialPortInfo &info : objectInfo->availablePorts()){
            qDebug() << info.portName();
            currentPortToUse = info.portName();
        }
    }
    else //Uses manually set port
        currentPortToUse = manualSerialPort;

    objectQSerialPort = new QSerialPort(this);
    qDebug() << "Using port: " << currentPortToUse;
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

    qDebug() << "Card signal connected";


}

void SerialEngine::closeSerialPort()
{
    disconnect(objectQSerialPort,SIGNAL(readyRead()),
               this, SLOT(readPort()));
    delete objectQSerialPort;
    qDebug() << "Card signal disconnected";
}

QString SerialEngine::returnCardSerialNumber()
{
    qDebug() << "Card serial number = " << cardSerialNumber;
    return cardSerialNumber;
}

void SerialEngine::setSerialPortManually(QString port)
{
    manualSerialPort = port;
}

void SerialEngine::readPort()
{
    QByteArray byteArray;
    byteArray=objectQSerialPort->readAll();

    if(byteArray=="")
        qDebug() << "Can't read card value...";
    else
    {
        //qDebug() << "-Signal read:- " << byteArray; //Full card number data

        QByteArray slicedByteArray = byteArray.mid(3,10);
        cardSerialNumber=slicedByteArray;

        qDebug() << "Card serial number = " << slicedByteArray; //Shows only card number
        emit readySignal();
    }

}
