#ifndef ADDITIONALDIALOG_H
#define ADDITIONALDIALOG_H

#include <QDialog>


namespace Ui {
class AdditionalDialog;
}

class AdditionalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdditionalDialog(QWidget *parent = nullptr);
    ~AdditionalDialog();

private:
    Ui::AdditionalDialog *ui;
};

#endif // ADDITIONALDIALOG_H
