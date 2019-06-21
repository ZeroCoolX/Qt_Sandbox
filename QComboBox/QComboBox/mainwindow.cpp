#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/res/img/hpSupply.png"), "Atlas");
    ui->comboBox->addItem(QIcon(":/res/img/missileHSupply.png"),"Frank");
    ui->comboBox->addItem(QIcon(":/res/img/missileSupply.png"),"Fontaine");

    for(auto i{0}; i < 10; ++i){
        ui->comboBox->addItem(QIcon(":/res/img/hpSupply.png"), "LittleSister_"+QString::number(i));
    }

    ui->comboBox->insertItem(3, QIcon(":/res/img/missileSupply.png"),"LittleSister_3");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,
                             "Title",
                             ui->comboBox->currentText());
}
