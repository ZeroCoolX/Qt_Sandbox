#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup image
    QPixmap image("C:/Users/Mitinz/Desktop/download.jpg");
    // Scale to be w/h of the label
    auto imgWidth = ui->label_image->width();
    auto imgHeight = ui->label_image->height();
    ui->label_image->setPixmap(image.scaled(imgWidth,imgHeight, Qt::KeepAspectRatio));
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
