#ifndef DETAILINFO_H
#define DETAILINFO_H
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QMainWindow>
#include "information.h"

namespace Ui {
class detailInfo;
}

class detailInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit detailInfo(QWidget *parent = 0);
    void transmitDetail(information info);
    ~detailInfo();

private slots:
    void on_pushButton_clicked();
    void slot_netwManagerFinished(QNetworkReply*);

private:
    Ui::detailInfo *ui;
};

#endif // DETAILINFO_H
