#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QDir dir("C:\\Users\\Mitinz\\Documents\\development\\Qt_udemy\\FileIO\\FilesIO\\randocalrisian");
//    if(dir.exists()){
//        QMessageBox::information(this,
//                                 "Directory status",
//                                 "Directory exists!");
//    }else{
//        QMessageBox::warning(this,
//                                 "Directory status",
//                                 "Directory does not exist!");
//    }

    QDir dir;
    foreach(auto d, dir.drives()){
        ui->comboBox->addItem(d.absoluteFilePath());
    }
    QDir dir2("C:\\Users\\Mitinz\\Documents\\development\\Qt_udemy\\FileIO\\FilesIO");
    foreach(auto f, dir2.entryInfoList()){
        if(f.isDir()){
            ui->listWidget->addItem("DIR: " + f.absoluteFilePath());
        }
        if(f.isFile()){
            ui->listWidget->addItem("FILE: " + f.absoluteFilePath());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir("C:\\Users\\Mitinz\\Documents\\development\\Qt_udemy\\FileIO\\FilesIO\\no-exist");
    if(!dir.exists()){
        dir.mkpath("C:\\Users\\Mitinz\\Documents\\development\\Qt_udemy\\FileIO\\FilesIO\\no-exist");
    }else{
        QMessageBox::information(this,
                                 "Exists",
                                 "Dir exists");
    }
}
