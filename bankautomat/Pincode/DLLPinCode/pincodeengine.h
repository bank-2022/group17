#ifndef PINCODEENGINE_H
#define PINCODEENGINE_H
#include <QString>


class PinCodeEngine
{
public:
    PinCodeEngine();
    QString cardPinCode();
private:
    QString cardPin;


};

#endif // PINCODEENGINE_H
