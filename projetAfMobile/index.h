#ifndef INDEX_H
#define INDEX_H

#include <QMainWindow>
#include <QNetworkRequest>
#include <QMainWindow>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItemModel>
#include "dataconnect.h"
#include "infodao.h"
#include "information.h"
#include "detailinfo.h"
#include "netdataaccess.h"

namespace Ui {
class indexa;
}

class indexa : public QMainWindow
{
    Q_OBJECT

public:
    explicit indexa(QWidget *parent = 0);
    void transmitData(dataconnect);
    void loadInfo();
    ~indexa();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void HttpReadyReadInfo();
    void onFinished();

private:
    Ui::indexa *ui;
    infodao dao;
    information info;
    netdataaccess data;
    detailInfo *detail;
    QNetworkReply *reply;
};

#endif // INDEX_H
