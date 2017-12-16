#include "index.h"
#include "ui_index.h"

indexa::indexa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::indexa)
{
    ui->setupUi(this);
    this->loadInfo();
}

void indexa::loadInfo()
{
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("http://www.google.com"));
    QNetworkReply *repl = nam.get(req);
    QEventLoop loop;
    connect(repl, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(repl->bytesAvailable())
    {
        QMessageBox::warning(this,"Liste info", "Vous etes actuellement en mode connecté");
        reply = data.getDataInformation(this,0);
        connect(reply, SIGNAL(readyRead()), this, SLOT(HttpReadyReadInfo()));
//        QEventLoop looping;
//        connect(reply,SIGNAL(finished()),&looping,SLOT(onFinished()));
//        looping.exec();
        ui->tableView->setModel(this->dao.ListeInformation());
        ui->tableView->setColumnHidden(0,true);
        ui->tableView->setColumnHidden(2,true);
        ui->tableView->setColumnHidden(4,true);
        ui->tableView->setColumnHidden(5,true);
        ui->tableView->setColumnHidden(6,true);
    }
    else
    {
        QMessageBox::warning(this,"Liste info", "Vous etes actuellement en mode deconnecté");
        ui->tableView->setModel(this->dao.ListeInformation());
        ui->tableView->setColumnHidden(0,true);
        ui->tableView->setColumnHidden(2,true);
        ui->tableView->setColumnHidden(4,true);
        ui->tableView->setColumnHidden(5,true);
        ui->tableView->setColumnHidden(6,true);
    }
}
void indexa::HttpReadyReadInfo()
{
    QByteArray json = reply->readAll();
    QJsonDocument d = QJsonDocument::fromJson(json);
    QJsonObject ligne = d.object();
    QJsonArray test = ligne["posts"].toArray();
    dao.purgerInfo();
    //QStandardItemModel *model = new QStandardItemModel(test.count(),6,this);
    for(int i=0 ; i<test.count() ; i++)
    {
        QJsonValue subobj = test[i];
        QJsonObject cellule = subobj.toObject();
        QJsonObject info = cellule["post"].toObject();
        //qWarning() << cellule["post"];
        information newsqlite;
        //QJsonValue val_infoid=information.value("info_id");
        newsqlite.setId(info["info_id"].toInt());
//        QStandardItem *itemid = new QStandardItem(info["info_id"].toString());
//        model->setItem(i,0,itemid);
        newsqlite.setTitre(info["titre"].toString());
//        QStandardItem *itemtitre = new QStandardItem(info["titre"].toString());
//        model->setItem(i,1,itemtitre);
        //qWarning()<<"Eto le test" <<information["titre"].toString();
        newsqlite.setPhoto(QObject::tr("http://alldreamscool.000webhostapp.com/aftmobile/img/%1").arg(info["photo"].toString()));
//        QStandardItem *itemphoto = new QStandardItem(info["photo"].toString());
//        model->setItem(i,2,itemphoto);
        newsqlite.setDescription(info["description"].toString());
//        QStandardItem *itemdesc = new QStandardItem(info["description"].toString());
//        model->setItem(i,3,itemdesc);
        newsqlite.setDetails(info["details"].toString());
//        QStandardItem *itemdet = new QStandardItem(info["details"].toString());
//        model->setItem(i,4,itemdet);
        newsqlite.setDate(info["date_expire"].toString());
//        QStandardItem *itemdate = new QStandardItem(info["date_expire"].toString());
//        model->setItem(i,5,itemdate);
        dao.synchroInfo(newsqlite);
    }
}

void indexa::transmitData(dataconnect dataq)
{
    this->dao.setData(dataq);
}

indexa::~indexa()
{
    delete ui;
}

void indexa::onFinished()
{

}

void indexa::on_tableView_clicked(const QModelIndex &index)
{
   information info;

   QSqlQueryModel *model = (QSqlQueryModel*)ui->tableView->model();
   //qWarning() << ui->tableView->model();
   info.setId(model->record(index.row()).value("info_id").toInt());
   info.setTitre(model->record(index.row()).value("titre").toString());
   info.setPhoto(model->record(index.row()).value("photo").toString());
   info.setDescription(model->record(index.row()).value("description").toString());
   info.setDetails(model->record(index.row()).value("details").toString());
   info.setDate(model->record(index.row()).value("date_expire").toString());

   detail = new detailInfo(this);
   detail->transmitDetail(info);
   detail->show();
   this->hide();
}

void indexa::on_pushButton_clicked()
{
    QMainWindow *main = (QMainWindow*)this->parent();
    main->show();
    this->close();
}
