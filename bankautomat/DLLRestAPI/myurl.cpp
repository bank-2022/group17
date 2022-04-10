#include "myurl.h"

MyURL::MyURL()
{
    //base_url ="http://localhost:3000";
    base_url ="http://ipv4.fiddler:3000";
}

const QString &MyURL::getBase_url() const
{
    return base_url;
}
