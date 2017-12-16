#ifndef INFORMATION_H
#define INFORMATION_H


#include<QString> //ted. à déclarer
class information
{
public:
    information();
    information(QString titre, QString photo, QString description, QString details);
    int getId();
    QString getTitre();
    QString getPhoto();
    QString getDescription();
    QString getDetails();
    QString getDate();


    void setId(int id);
    void setTitre(QString titre);
    void setPhoto(QString photo);
    void setDescription(QString description);
    void setDetails(QString details);
    void setDate(QString date);

private:
    int info_id;
    QString titre;
    QString photo;
    QString description;
    QString details;
    QString date;

};

#endif // INFORMATION_H
