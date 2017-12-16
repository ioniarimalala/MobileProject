#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QDir>

#include "login.h"
#include "logindao.h"

#include "inscription.h"
#include "dataconnect.h"
#include "index.h"
#include "membredao.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_inscription_clicked();

    void on_lineEdit_username_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    indexa *ind;
    inscription *inscriptionDialogue;
    dataconnect data;
    membredao mdao;
    loginDAO dao;

};

#endif // MAINWINDOW_H
