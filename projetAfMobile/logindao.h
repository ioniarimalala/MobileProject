#ifndef LOGINDAO_H
#define LOGINDAO_H

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include <QDir>
#include <QVariant>
#include <QMessageBox>

#include "login.h"
#include "dataconnect.h"

class loginDAO
{
 public:

    loginDAO();
    bool validerLoggin(login);

private:
    //QString pathDB;
    //dataconnect data;

};

#endif // LOGINDAO_H
