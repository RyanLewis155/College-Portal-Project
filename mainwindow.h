#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginwindow.h"
#include "dashboard.h"

#include <QMainWindow>
#include <QMdiArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;

    LoginWindow *loginWindow;
    DashBoard *dashBoardWindow;
};

#endif // MAINWINDOW_H
