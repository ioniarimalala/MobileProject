#ifndef MEMBREDAO_H
#define MEMBREDAO_H

#include <QNetworkRequest>
#include <QMainWindow>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileInfo>


#include <QSqlQuery>
#include <QVariant>
#include <QDir>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QtSql/QSqlError>
#include <QString>
#include <QMessageBox>

#include "dataconnect.h"
#include "membre.h"


class membredao
{
public:
    membredao();
    bool ajouterMembre(membre);
    bool modifierMembre(membre);
    void setData(dataconnect);
    QList<membre> touslesMembre();

private:
    dataconnect data;
};

#endif // MEMBREDAO_H
