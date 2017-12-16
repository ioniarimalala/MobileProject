#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QMainWindow>

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtSql/qsqlerror.h>
#include "QPalette"

#include <QMessageBox>
#include <QDir>


#include "membre.h"
#include "membredao.h"
#include"netdataaccess.h"

namespace Ui {
class inscription;
}

class inscription : public QMainWindow
{
    Q_OBJECT

public:
    explicit inscription(QWidget *parent = 0);
    void HttpReadyRead();
    void transmitData(dataconnect);
    ~inscription();

private slots:
    void on_pb_saisir_clicked();

    void on_le_mdpconfirm_editingFinished();

    void on_le_email_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::inscription *ui;
    membre newmembre;
    membredao dao;
    netdataaccess testor;
    QNetworkReply *reply;
};

#endif // INSCRIPTION_H
