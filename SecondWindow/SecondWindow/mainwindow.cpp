#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete additionalDialog;
}

void MainWindow::on_pushButton_clicked()
{
      // mem on stack - only access open dialog. Nothing else
//    AdditionalDialog dialog;    // reference to second window
//    dialog.setModal(true);      // true - show dialog, false - hide dialog
//    dialog.exec();

    // Hides the main window
    this->hide();

    // mem on heap - allows parent and child dialog to be interactable in parallel
    additionalDialog = new AdditionalDialog(this);
    additionalDialog->show();
}
