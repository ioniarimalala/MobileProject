#include "dataconnect.h"

dataconnect::dataconnect()
{

}

void dataconnect::setConnexion(QSqlDatabase db)
{
    this->db=db;
}

QSqlDatabase dataconnect::getConnexion()
{
    return this->db;
}

void dataconnect::openDB()
{
    this->connectToSQLITE("assets:/dbAft"); //VERSION Android old
    //this->connectToSQLITE(QObject::tr("%1/debug/db/dbAft").arg(QDir::currentPath())); //VERSION Desktop 1/2
    this->getConnexion().open(); //VERSION Desktop 2/2
}

void dataconnect::connectToSQLITE(QString filename)
{
    QFile dfile(filename);
    //QFile old("./dbAft");
    if(dfile.exists())
    {
        //old.remove();
        dfile.copy("./dbAft");
        QFile::setPermissions("./dbAft",QFile::WriteOwner |     QFile::ReadOwner);
        filename="./dbAft";
     }
    this->db=QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(filename);
}
