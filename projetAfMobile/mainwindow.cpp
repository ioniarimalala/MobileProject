#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    data.openDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    login logins;
    logins.setLog(ui->lineEdit_username->text());
    logins.setMdp(ui->lineEdit_password->text());

    if(dao.validerLoggin(logins))
    {
        //bool test = dao.validerLoggin(logins);
        ind = new indexa(this);
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        ind->show();
        this->hide();
    }
    else
    {
        //bool test = dao.validerLoggin(logins);
        QMessageBox::warning(this,"Authentification", "Erreur d'authentification, veuillez verifier le login ou le mot de passe");
    }
}

void MainWindow::on_pushButton_inscription_clicked()
{
//    QString t;
//    QMessageBox::warning(this,"Numero", t.setNum(mdao.touslesMembre().count()));
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("http://www.google.com"));
    QNetworkReply *reply = nam.get(req);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->bytesAvailable())
    {
        if(mdao.touslesMembre().isEmpty())
        {
            inscriptionDialogue = new inscription(this);
            inscriptionDialogue->transmitData(this->data);
            this->hide();
            inscriptionDialogue->show();
        }
        else
        {
            QMessageBox::warning(this,"Inscription dejà valider", "Ce telephone est dejà inscrit, inscription unique par telephone, veuillez contectez l'administrateur pour une nouvelle reinscription");
        }
    }
   else
        QMessageBox::warning(this,"Connexion coupé","Pour vous inscrire veuillez vous connectez");

}

void MainWindow::on_lineEdit_username_textChanged(const QString &arg1)
{
    if(ui->lineEdit_username->text().compare("")!=0)
        {
            if(arg1.at(arg1.length()-1).isLetter())
                {
                    QMessageBox::warning(this,"Numero", "Entrez un numero valide");
                    ui->lineEdit_username->setText("");
                }
                if (arg1.length()>10)
                {
                    QMessageBox::warning(this,"Numero", "Un numero valide a 10 chiffres");
                    ui->lineEdit_username->setText(ui->lineEdit_username->text().remove(arg1.length()-1,1));
                }
        }
}
