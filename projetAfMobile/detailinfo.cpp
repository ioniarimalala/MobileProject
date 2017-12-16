#include "detailinfo.h"
#include "ui_detailinfo.h"

detailInfo::detailInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::detailInfo)
{
    ui->setupUi(this);
}

void detailInfo::transmitDetail(information info)
{
    QNetworkAccessManager *m_netwManager = new QNetworkAccessManager(this);
    connect(m_netwManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_netwManagerFinished(QNetworkReply*)));

    QUrl url(info.getPhoto());
    QNetworkRequest request(url);
    m_netwManager->get(request);
    ui->titre->setText(info.getTitre());
    ui->description->setText(info.getDescription());
    ui->details->setText(info.getDetails());
}

void detailInfo::slot_netwManagerFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {

    }
    else
    {
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    ui->photo->setPixmap(pixmap.scaled(200,200));
    }
}

detailInfo::~detailInfo()
{
    delete ui;
}

void detailInfo::on_pushButton_clicked()
{
    QMainWindow *main = (QMainWindow*)this->parent();
    main->show();
    this->close();
}
