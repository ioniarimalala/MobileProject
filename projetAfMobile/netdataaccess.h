#ifndef NETDATAACCESS_H
#define NETDATAACCESS_H

#include <QNetworkRequest>
#include <QMainWindow>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileInfo>
#include<QVariant>
#include <QMessageBox>

#include"membre.h"
#include"information.h"


class netdataaccess
{
    public:
        netdataaccess();
        void sendDataMembre(membre,QObject*);
        QNetworkReply* getDataMembre(QObject*);
        void sendDataInformation(information newinformation,QObject *parent);
        QNetworkReply* getDataInformation(QObject* parent, int info_id);
    private slots:
    private:
            QNetworkReply *reply;
};

#endif // NETDATAACCESS_H
