#ifndef DATACONNECT_H
#define DATACONNECT_H

#include <QtSql/QSqlDatabase>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QDir>

class dataconnect
{
public:
    dataconnect();
    void setConnexion(QSqlDatabase);
    QSqlDatabase getConnexion();
    void connectToSQLITE(QString);
    void openDB();

private:
    QSqlDatabase db;

};

#endif // DATACONNECT_H
