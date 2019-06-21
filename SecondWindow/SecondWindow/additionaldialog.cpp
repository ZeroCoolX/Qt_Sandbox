#include "additionaldialog.h"
#include "ui_additionaldialog.h"

AdditionalDialog::AdditionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdditionalDialog)
{
    ui->setupUi(this);
}

AdditionalDialog::~AdditionalDialog()
{
    delete ui;
}
