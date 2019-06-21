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

    // Setup image - with relative resource path
    QPixmap image(":/resources/images/login.jpg");
    // Scale to be w/h of the label
    auto imgWidth {ui->label_image->width()};
    auto imgHeight {ui->label_image->height()};
    ui->label_image->setPixmap(image.scaled(imgWidth,imgHeight, Qt::KeepAspectRatio));

    // Add widgets (created originally in the UI) to the status bar
    ui->statusBar->addPermanentWidget(ui->label_3);
    ui->statusBar->addPermanentWidget(ui->progressBar);
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
        // Display small message in the status bar instead
        ui->statusBar->showMessage("Login Successful",  // Message
                                   5000);               // Timeout till clear

        // Display modal to the user
        QMessageBox::information(this, "Login Successful", "Hello " + user + ", Welcome back");
        this->hide();
        uProf = new UserProfile(this);
        uProf->show();
    }else{
        // Display small message in the status bar instead
        ui->statusBar->showMessage("Credentials Invalid");

        // Display modal to the user
        QMessageBox::warning(this, "Credentials Invalid", "No matching username and password");
    }
}
