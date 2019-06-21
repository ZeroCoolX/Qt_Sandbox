#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete uProf;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString user {ui->lineEdit_userName->text()};
    QString pass {ui->lineEdit_password->text()};

    if(user == "atlas" && pass == "fontaine"){
        QMessageBox::information(this, "Login Successful", "Hello " + user + ", Welcome back");
        this->hide();
        uProf = new UserProfile(this);
        uProf->show();
    }else{
        QMessageBox::warning(this, "Credentials Invalid", "No matching username and password");
    }
}
