#include "inscription.h"
#include "ui_inscription.h"

#include "membredao.h"
#include <QApplication>
#include <QtCore>
#include <QtGui>

inscription::inscription(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inscription)
{
    ui->setupUi(this);
}

inscription::~inscription()
{
    delete ui;
}
void inscription::transmitData(dataconnect data)
{
    dao.setData(data);
}

void inscription::on_pb_saisir_clicked()
{
    if(ui->le_nom->text().compare("")!=0 and ui->le_tph->text().compare("")!=0 and ui->le_mdp->text().compare("")!=0  and ui->le_mdpconfirm->text().compare("")!=0)
     {
       membre newmembre;
       newmembre.setNom(ui->le_nom->text());
       newmembre.setPrenom(ui->le_prenom->text());
       newmembre.setTelephone(ui->le_tph->text());
       newmembre.setMail(ui->le_email->text());
       newmembre.setEmploi(ui->le_emploi->text());
       newmembre.setAdresse(ui->le_adresse->text());
       newmembre.setOrganisme(ui->le_organisme->text());
       newmembre.setRs1(ui->le_rs1->text());
       newmembre.setRs2(ui->le_rs2->text());
       newmembre.setRs3(ui->le_rs3->text());
       newmembre.setMdp(ui->le_mdp->text());
       if(dao.ajouterMembre(newmembre))
     {
            try
           {
               this->testor.sendDataMembre(newmembre,this);
           }
           catch(QException e)
           {
               qWarning() << e.what();
           }
           QMessageBox::warning(this,"Inscription membre", "Inscription reussie, vous pouvez vous authentifier");
           this->on_pushButton_clicked();
         }
         else
         {
           QMessageBox::warning(this,"Inscription membre", "Inscription echouee, vous etes dejà inscrit");
           this->on_pushButton_clicked();
         }
           ui->le_nom->setText("");
           ui->le_prenom->setText("");
           ui->le_tph->setText("");
           ui->le_email->setText("");
           ui->le_emploi->setText("");
           ui->le_adresse->setText("");
           ui->le_organisme->setText("");
           ui->le_rs1->setText("");
           ui->le_rs2->setText("");
           ui->le_rs3->setText("");
           ui->le_mdp->setText("");
           ui->le_mdpconfirm->setText("");
       }
     else
     {
         QMessageBox::warning(this,"Inscription membre", "Champs obligatoires: Nom, téléphone et mot de passe");
     }
}

void inscription::on_le_mdpconfirm_editingFinished()
{
    if(ui->le_mdp->text().compare((ui->le_mdpconfirm->text())))
    {
        QMessageBox::warning(this,"Inscription membre", "Mot de passe non confirmer, veuillez retaper mot de passe et confirmer");
        ui->le_mdpconfirm->setText("");
    }
}

void inscription::on_le_email_editingFinished()
{
    if(ui->le_email->text().compare("")!=0)
    {
        if(ui->le_email->text().contains(' '))
        {
            ui->le_email->setText(ui->le_email->text().remove(' '));
        }

        if(!ui->le_email->text().contains('@') || !ui->le_email->text().contains('.'))
            {
                QMessageBox::warning(this,"Inscription membre", "Mail non valide, veuillez entrez une adresse e-mail valide");
                ui->le_email->setFocus();
                ui->le_email->setStyleSheet("background: red");
            }
        else
            {
                ui->le_email->setStyleSheet("background: none");
            }
    }
}

void inscription::on_pushButton_clicked()
{
    QMainWindow *main = (QMainWindow*)this->parent();
    main->show();
    this->close();
}
