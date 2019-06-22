#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

void MainWindow::on_pushButton_3_clicked()
{
    QFile file("C:\\Users\\Mitinz\\Documents\\development\\Qt_udemy\\FileIO\\FilesIO\\darth.vader");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,
                             "Warning",
                             "Coult not open file darth.vader");
        return;
    }

    QTextStream fout(&file);
    QString text {ui->plainTextEdit->toPlainText()};
    fout << text;
    file.flush();

    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString searchFilter {"All File (*.*) ;; Vader File (*.vader) ;; Cpp File (*.cpp)"};
    QString fileName = QFileDialog::getOpenFileName(this,               // Parent
                                                    "Open a file",      // Message
                                                    QDir::homePath(),   // Base dir
                                                    searchFilter);      // Filter dropdown

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,
                             "Warning",
                             "Coult not open file " + fileName);
        return;
    }

    QTextStream fin(&file);
    QString text {fin.readAll()};
    ui->plainTextEdit->setPlainText(text);

    file.close();
}
