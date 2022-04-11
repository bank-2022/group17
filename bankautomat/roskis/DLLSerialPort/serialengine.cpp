#include "serialengine.h"

SerialEngine::SerialEngine()
{
    openSerialPort();
    QSerialPortInfo *info;
    info->availablePorts();

}

void SerialEngine::openSerialPort()
{

}

void SerialEngine::closeSerialPort()
{

}

QString SerialEngine::returnCardSerialNumber()
{
    return "";
}

void SerialEngine::readPort()
{

}
