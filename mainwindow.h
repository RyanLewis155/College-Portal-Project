#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginwindow.h"

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

private:

private slots:
    void handleLoginSuccess(UserInfo userInfo);

    //void handleRegistrationRequest();

private:
    Ui::MainWindow *ui;

    LoginWindow *loginWindow;
    QWidget *dashBoardWindow;
};

#endif // MAINWINDOW_H
