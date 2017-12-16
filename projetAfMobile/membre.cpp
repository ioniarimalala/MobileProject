#include "membre.h"

membre::membre()
{
    this->nom="nom";
    this->prenom="prenom";
    this->telephone="telephone";
    this->mail="mail";
    this->emploi="emploi";
    this->adresse="adresse";
    this->organisme="organisme";
    this->rs1="rs1";
    this->rs2="rs2";
    this->rs3="rs3";
    this->mdp="mdp";
}

membre::membre(QString nom,QString prenom,QString telephone,QString mail,QString emploi,QString adresse,QString organisme,QString rs1,QString rs2,QString rs3,QString mdp) //ted. constructeur
{
    this->nom=nom;
    this->prenom=prenom;
    this->telephone=telephone;
    this->mail=mail;
    this->emploi=emploi;
    this->adresse=adresse;
    this->organisme=organisme;
    this->rs1=rs1;
    this->rs2=rs2;
    this->rs3=rs3;
    this->mdp=mdp;
}

QString membre::getNom()
{
    return this->nom;
}

QString membre::getPrenom()
{
    return this->prenom;
}
QString membre::getTelephone()
{
    return this->telephone;
}
QString membre::getMail()
{
    return this->mail;
}
QString membre::getEmploi()
{
    return this->emploi;
}
QString membre::getAdresse()
{
    return this->adresse;
}

QString membre::getOrganisme()
{
    return this->organisme;
}

QString membre::getRs1()
{
    return this->rs1;
}

QString membre::getRs2()
{
    return this->rs2;
}
QString membre::getRs3()
{
    return this->rs3;
}

QString membre::getMdp()
{
    return this->mdp;
}

//SET
void membre::setNom(QString nom)
{
   this->nom=nom;
}

void membre::setPrenom(QString prenom)
{
   this->prenom=prenom;
}

void membre::setEmploi(QString emploi)
{
   this->emploi=emploi;
}

void membre::setMail(QString mail)
{
   this->mail=mail;
}

void membre::setTelephone(QString telephone)
{
   this->telephone=telephone;
}

void membre::setAdresse(QString adresse)
{
   this->adresse=adresse;
}

void membre::setOrganisme(QString organisme)
{
   this->organisme=organisme;
}
void membre::setRs1(QString rs1)
{
   this->rs1=rs1;
}
void membre::setRs2(QString rs2)
{
   this->rs2=rs2;
}
void membre::setRs3(QString rs3)
{
   this->rs3=rs3;
}
void membre::setMdp(QString mdp)
{
   this->mdp=mdp;
}
