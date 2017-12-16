#ifndef LOGIN_H
#define LOGIN_H

#include "QString"
#include "dataconnect.h"

class login
{
public:
    login();
    login(QString,QString);

    QString getLog();
    QString getMdp();

    void setLog(QString);
    void setMdp(QString);

private:
    QString log;
    QString mdp;

};

#endif // LOGIN_H
