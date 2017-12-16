#include "logindao.h"

loginDAO::loginDAO()
{
    /*this->pathDB=QObject::tr("%1/debug/db/dbAft").arg(QDir::currentPath());
    this->data.connectToSQLITE(pathDB);
    this->data.getConnexion().open();
*/

}

bool loginDAO::validerLoggin(login logins)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM membre WHERE  tel = ? and mdp = ? ");
    query.addBindValue(logins.getLog());
    query.addBindValue(logins.getMdp());
    query.exec();
    return query.next();
}

