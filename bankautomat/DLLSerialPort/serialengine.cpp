#include "serialengine.h"

void SerialEngine::openSerialPort() //Read the serial port data and make signal
{
    //Debug only with: "#include <QtSerialPort/QSerialPortInfo>" and "private: *objectInfo"
    //----------------Debug-----------------------------------
    int portSize=objectInfo->availablePorts().length();
    QString currentPortToUse;
    //int portOrderNumber=0;
    qDebug() << portSize << "serial ports found:";

    for(const QSerialPortInfo &info : objectInfo->availablePorts())
    {
        qDebug() << info.portName();
        currentPortToUse = info.portName();
    }

    //----------------Debug-----------------------------------
    qDebug() << "Using port: " << currentPortToUse;
    objectQSerialPort = new QSerialPort(this);
    //objectQSerialPort->setPortName("COM4"); //COM-port that reader is connected to
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

void SerialEngine::readPort()
{
    QByteArray byteArray;
    byteArray=objectQSerialPort->readAll();

    if(byteArray=="")
        qDebug() << "Can't read card from serial port...";
    else
    {
        //qDebug() << "-Signal read:- " << byteArray; //Full card number data

        QByteArray slicedByteArray = byteArray.mid(3,10);
        cardSerialNumber=slicedByteArray;

        qDebug() << "Card serial number = " << slicedByteArray; //Shows only card number
        emit readySignal();
    }

}
