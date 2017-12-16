#include "membredao.h"

membredao::membredao()
{
    //this->data.connectToSQLITE(QObject::tr("%1/debug/bd/dbAft").arg(QDir::currentPath())); //VERSION Desktop 1/2
    //this->data.getConnexion().open(); //VERSION Desktop 2/2

    //this->data.connecttosqlite("assets:/dbAft"); //VERSION Android old
    //this->data.connecttosqlite("/mnt/sdcard/dbAft"); //VERSION Android  (atao ao anaty CARTE SD)
}

void membredao::setData(dataconnect data)
{
    this->data=data;
}

bool membredao::ajouterMembre(membre newmembre)
{
    QSqlQuery query;
    query.prepare("INSERT INTO membre VALUES (?,?,?,?,?,?,?,?,?,?,?)");
    query.addBindValue(newmembre.getNom());
    query.addBindValue(newmembre.getPrenom());
    query.addBindValue(newmembre.getTelephone());
    query.addBindValue(newmembre.getMail());
    query.addBindValue(newmembre.getEmploi());
    query.addBindValue(newmembre.getAdresse());
    query.addBindValue(newmembre.getOrganisme());
    query.addBindValue(newmembre.getRs1());
    query.addBindValue(newmembre.getRs2());
    query.addBindValue(newmembre.getRs3());
    query.addBindValue(newmembre.getMdp());
    qDebug() << "ity ny query" << newmembre.getNom() << newmembre.getMdp();

    return query.exec();
}

bool membredao::modifierMembre(membre newmembre)
{
    QSqlQuery query;
    //Pb: Syntaxe requête Update, ny solon'ny 'addBinValue'
    query.prepare("UPDATE membre SET nom=?,prenom=?,mail=?,emploi=?,note=? WHERE tel=?");
    query.addBindValue(newmembre.getNom());
    query.addBindValue(newmembre.getPrenom());
    query.addBindValue(newmembre.getMail());
    query.addBindValue(newmembre.getEmploi());
    query.addBindValue(newmembre.getAdresse());
    query.addBindValue(newmembre.getOrganisme());
    query.addBindValue(newmembre.getRs1());
    query.addBindValue(newmembre.getRs2());
    query.addBindValue(newmembre.getRs3());
    query.addBindValue(newmembre.getMdp());
    return query.exec();
}

QList<membre> membredao::touslesMembre()
{
    QSqlQueryModel model;
    QList<membre> list;
    model.setQuery("SELECT * FROM membre");
    for(int i=0; i<model.rowCount(); i++)
    {
      membre newmembre;
      newmembre.setNom(model.record(i).value("nom").toString());
      newmembre.setPrenom(model.record(i).value("prenom").toString());
      newmembre.setTelephone(model.record(i).value("tel").toString());
      newmembre.setMail(model.record(i).value("mail").toString());
      newmembre.setEmploi(model.record(i).value("emploi").toString());
      newmembre.setEmploi(model.record(i).value("adresse").toString());
      newmembre.setEmploi(model.record(i).value("organisme").toString());
      newmembre.setEmploi(model.record(i).value("rs1").toString());
      newmembre.setEmploi(model.record(i).value("rs2").toString());
      newmembre.setEmploi(model.record(i).value("rs3").toString());
      newmembre.setEmploi(model.record(i).value("mdp").toString());

      list.insert(i,newmembre);
    }
    return list;
}
