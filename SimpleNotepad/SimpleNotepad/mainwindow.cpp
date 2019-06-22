#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Removes padding space for this widget
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    // clear whatever WAS the current file
    current_filepath = "";
    // clear the editor
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    // Open the file if we can
    current_filepath = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(current_filepath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,
                             "Error openeing file",
                             "Could not open file " + current_filepath);
        current_filepath = "";
        return;
    }

    // Write the contents of the file to the editor
    QTextStream fin(&file);
    ui->textEdit->setText(fin.readAll());

    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(current_filepath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,
                             "Error openeing file",
                             "Could not save file " + current_filepath);
        return;
    }

    // Write the contents of the editor to the file
    QTextStream fout(&file);
    fout << ui->textEdit->toPlainText();
    file.flush();

    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    // Open the file if we can
     current_filepath = QFileDialog::getSaveFileName(this, "Save file");
    QFile file( current_filepath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,
                             "Error openeing file",
                             "Could not save file " +  current_filepath);
        return;
    }

    // Write the contents of the editor to the file
    QTextStream fout(&file);
    fout << ui->textEdit->toPlainText();
    file.flush();

    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_SimpleNotepad_triggered()
{
    QMessageBox::about(this,
                             "About",
                             "SimpleNotepad is a simple text editor with some bells and whistles");
}
