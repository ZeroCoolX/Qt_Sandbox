#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Check by default on startup
    //ui->checkBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString msg {"You hate cats"};
    if(ui->checkBox->isChecked()){
        msg = "You like cats";
    }

    QMessageBox::information(this, "Title", msg);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    QString msg {"You hate cats"};
    if(arg1){
        msg = "You like cats";
    }

    QMessageBox::information(this, "Title", msg);
}
