#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionHealth_triggered();

    void on_actionMissile_triggered();

    void on_actionHMissile_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
