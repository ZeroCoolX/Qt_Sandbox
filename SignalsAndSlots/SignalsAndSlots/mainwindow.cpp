#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Adding signal and slot to sender and reciever
    connect(ui->horizontalSlider,       // sender
            SIGNAL(valueChanged(int)),  // signal
            ui->progressBar,            // receiver
            SLOT(setValue(int)));       // slot

    // Remove a signal and slot
//    disconnect(ui->horizontalSlider,
//               SIGNAL(valueChanged(int)),
//               ui->progressBar,
//               SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
