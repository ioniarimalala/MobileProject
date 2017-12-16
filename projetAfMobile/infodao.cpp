#include "infodao.h"
#include<QMessageBox>

infodao::infodao()
{
}

void infodao::setData(dataconnect data)
{
    this->data=data;
}

QSqlQueryModel* infodao::ListeInformation()
{
     QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("SELECT info_id, titre, photo ,description, details, date_expire FROM information");
     return model;
}

bool infodao::synchroInfo(information info)
{
    QSqlQuery query;
    query.prepare("INSERT INTO information VALUES (?,?,?,?,?,?)");
    query.addBindValue(info.getId());
    query.addBindValue(info.getTitre());
    query.addBindValue(info.getPhoto());
    query.addBindValue(info.getDescription());
    query.addBindValue(info.getDetails());
    query.addBindValue(info.getDate());
    return query.exec();
}

bool infodao::purgerInfo()
{
    QSqlQuery query;
    query.prepare("DELETE FROM information");
    return query.exec();
}

void infodao::finishdao()
{
    this->data.getConnexion().close();
}

QList<information> infodao::toutLesMembres()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QList<information> list;
    model->setQuery("SELECT info_id, titre, photo ,description, details, date_expire FROM information");
    for (int i=0;i<model->rowCount();i++){
        information info;
        qWarning() <<"nombre : "<< model->record(i).value("titre").toString();
        info.setTitre(model->record(i).value("titre").toString());
        info.setPhoto(model->record(i).value("photo").toString());
        info.setDescription(model->record(i).value("description").toString());
        info.setDetails(model->record(i).value("details").toString());
        list.insert(i,info);
    }
    return list;
}
