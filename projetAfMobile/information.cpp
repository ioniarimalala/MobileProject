#include "information.h"

information::information()
{
    this->titre="titre";
    this->photo="photo";
    this->description="description";
    this->details="details";
}
information::information(QString titre, QString photo, QString description, QString details)
{
    this->titre=titre;
    this->photo=photo;
    this->description=description;
    this->details=details;

}
//**************Getter ****************************
QString information::getDate()
{
    return this->date;
}

int information::getId()
{
    return this->info_id;
}

QString information::getTitre()
{
    return this->titre;
}

QString information::getPhoto()
{
    return this->photo;
}

QString information::getDescription()
{
    return this->description;
}

QString information::getDetails()
{
    return this->details;
}

//**********************Setter *************************
void information::setDate(QString date)
{
    this->date=date;
}
void information::setId(int id)
{
    this->info_id=id;
}
void information::setTitre(QString titre)
{
    this->titre=titre;
}

void information::setPhoto(QString photo)
{
    this->photo=photo;
}

void information::setDescription(QString description)
{
    this->description=description;
}

void information::setDetails(QString details)
{
    this->details=details;
}
