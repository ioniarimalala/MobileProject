#include "login.h"

login::login()
{
    this->log="log";
    this->mdp="mdp";
}

login::login(QString log,QString mdp)
{
    this->log=log;
    this->mdp=mdp;
}


QString login::getLog()
{
    return this->log;
}

QString login::getMdp()
{
    return this->mdp;
}
void login::setLog(QString log)
{
    this->log=log;
}

void login::setMdp(QString mdp)
{
    this->mdp=mdp;
}
