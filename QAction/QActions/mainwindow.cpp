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
}

void MainWindow::on_actionHealth_triggered()
{
    QMessageBox::information(this,
                             "Health Acquired",
                             "Health has been upgraded!");
}

void MainWindow::on_actionMissile_triggered()
{
    QMessageBox::warning(this,
                             "Missiles Active",
                             "Missiles have been activated!");
}

void MainWindow::on_actionHMissile_triggered()
{
    QApplication::quit();
}
