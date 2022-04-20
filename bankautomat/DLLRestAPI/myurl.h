#ifndef MYURL_H
#define MYURL_H

#include <qstring.h>

class MyURL
{
public:
    MyURL();
    const QString &getBase_url() const;

private:
    QString base_url;
};

#endif // MYURL_H
