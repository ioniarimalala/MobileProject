#ifndef INFODAO_H
#define INFODAO_H

#include"dataconnect.h"
#include"information.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include<QDir>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QAbstractButton>
#include <QDebug>
#include<QAbstractItemModel>
#include<QListView>

class infodao
{
public:
    infodao();
    QSqlQueryModel* ListeInformation();
    QList<information> toutLesMembres();
    bool purgerInfo();
    bool synchroInfo(information);
    void setData(dataconnect);
    void finishdao();
private:
    dataconnect data;
};

#endif // INFODAO_H
