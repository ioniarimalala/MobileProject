#include "netdataaccess.h"

netdataaccess::netdataaccess()
{

}

QNetworkReply* netdataaccess::getDataMembre(QObject* parent)
{
    QNetworkAccessManager *m_qnam = new QNetworkAccessManager(parent);
    m_qnam->setNetworkAccessible(QNetworkAccessManager::Accessible);

    // Time for building your request
    QUrl serviceURL("http://alldreamscool.000webhostapp.com/webservice/testmysqld.php");
    QNetworkRequest request(serviceURL);

    // Use QNetworkReply * QNetworkAccessManager::post(const QNetworkRequest & request, const QByteArray & data); to send your request. Qt will rearrange everything correctly.
    reply = m_qnam->get(request);
    return reply;
}

void netdataaccess::sendDataMembre(membre newmembre, QObject *parent)
{
    QString data = QObject::tr("{\"nom\":\"%1\",\"prenom\":\"%2\",\"tel\":\"%3\",\"mail\":\"%4\",\"emploi\":\"%5\",\"adresse\":\"%6\",\"organisme\":\"%7\",\"rs1\":\"%8\",\"rs2\":\"%9\",\"rs3\":\"%10\",\"mdp\":\"%11\"}").arg(newmembre.getNom()).arg(newmembre.getPrenom()).arg(newmembre.getTelephone()).arg(newmembre.getMail()).arg(newmembre.getEmploi()).arg(newmembre.getAdresse()).arg(newmembre.getOrganisme()).arg(newmembre.getRs1()).arg(newmembre.getRs2()).arg(newmembre.getRs3()).arg(newmembre.getMdp());
    QNetworkAccessManager *m_qnam = new QNetworkAccessManager(parent);
    m_qnam->setNetworkAccessible(QNetworkAccessManager::Accessible);
    QByteArray jsonString=data.toUtf8();
    QByteArray postDataSize = QByteArray::number(jsonString.size());
    QUrl serviceURL("http://alldreamscool.000webhostapp.com/webservice/testmysql.php");
    QNetworkRequest request(serviceURL);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);
    reply = m_qnam->post(request, jsonString);
    qWarning() <<jsonString;
}

void netdataaccess::sendDataInformation(information newinformation,QObject *parent)
{

    QString data = QObject::tr("{\"info_id\":\"%1\",\"titre\":\"%2\",\"photo\":\"%3\",\"description\":\"%4\",\"details\":\"%5\",\"date_expire\":\"%6\"}").arg(newinformation.getId()).arg(newinformation.getTitre()).arg(newinformation.getPhoto()).arg(newinformation.getDescription()).arg(newinformation.getDetails()).arg(newinformation.getDate());
    QNetworkAccessManager *m_qnam = new QNetworkAccessManager(parent);
    m_qnam->setNetworkAccessible(QNetworkAccessManager::Accessible);


    /* Build your JSON string as usual
    //strcpy(data,"{\
    // For your "Con"data\":\"b\"}");*/
    QByteArray jsonString=data.toUtf8();
    //QMessageBox test;
    //test.setText();
    //test.exec();tent-Length" header
    QByteArray postDataSize = QByteArray::number(jsonString.size());

    // Time for building your request
    QUrl serviceURL("http://alldreamscool.000webhostapp.com/webservice/testmysql.php");
    QNetworkRequest request(serviceURL);

    // Add the headers specifying their names and their values with the following method : void QNetworkRequest::setRawHeader(const QByteArray & headerName, const QByteArray & headerValue);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    // Use QNetworkReply * QNetworkAccessManager::post(const QNetworkRequest & request, const QByteArray & data); to send your request. Qt will rearrange everything correctly.

    reply = m_qnam->post(request, jsonString);
    qWarning() <<jsonString;
}

QNetworkReply* netdataaccess::getDataInformation(QObject* parent, int info_id)
{
    QString data = QObject::tr("http://alldreamscool.000webhostapp.com/webservice/lastinfomysqld.php?info_id=%1").arg(info_id);
    QNetworkAccessManager *m_qnam = new QNetworkAccessManager(parent);
    m_qnam->setNetworkAccessible(QNetworkAccessManager::Accessible);

    // Time for building your request
    QUrl serviceURL(data);
    QNetworkRequest request(serviceURL);

    // Use QNetworkReply * QNetworkAccessManager::post(const QNetworkRequest & request, const QByteArray & data); to send your request. Qt will rearrange everything correctly.
    reply = m_qnam->get(request);
    return reply;

}
