#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*
    QMessageBox::   about       : basic modal
                    aboutQt
                    critical    : (x) critical modal
                    information : (i) info modal
                    question    : (?) quesiton modal
                    warning     : (!) warning
    */

//    QMessageBox::information(this,                          // parent for widget
//                       "Message box title",                 // title
//                       "Custom message text...");           // message

    QMessageBox::StandardButton reply = QMessageBox::question(this, // parent for widget
                       "Message box title",                         // title
                       "Do you want to quit the app?",              // message
                       QMessageBox::Yes | QMessageBox::No);         // options - only available for question type

    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "No is clicked";
    }
}
