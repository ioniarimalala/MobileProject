#ifndef MEMBRE_H
#define MEMBRE_H

#include<QString>

class membre
{
public:
    membre();
    membre(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString); //ted. constructeur

    QString getNom();
    QString getPrenom();
    QString getTelephone();
    QString getMail();
    QString getEmploi();
    QString getAdresse();
    QString getOrganisme();
    QString getRs1();
    QString getRs2();
    QString getRs3();
    QString getMdp();

    void setNom(QString);
    void setPrenom(QString);
    void setTelephone(QString);
    void setMail(QString);
    void setEmploi(QString);
    void setAdresse(QString);
    void setOrganisme(QString);
    void setRs1(QString);
    void setRs2(QString);
    void setRs3(QString);
    void setMdp(QString);

private:
    QString nom;
    QString prenom;
    QString telephone;
    QString mail;
    QString emploi;
    QString organisme;
    QString adresse;
    QString rs1;
    QString rs2;
    QString rs3;
    QString mdp;
};

#endif // MEMBRE_H
