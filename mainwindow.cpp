#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "dashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mdiArea(new QMdiArea)
{
    ui->setupUi(this);
    setCentralWidget(ui->stackedWidget);
    loginWindow = new LoginWindow();
    dashBoardWindow = new DashBoard();

    ui->stackedWidget->addWidget(loginWindow);
    ui->stackedWidget->addWidget(dashBoardWindow);

    loginWindow->show();
    dashBoardWindow->show();

    ui->stackedWidget->setCurrentWidget(loginWindow);
    loginWindow->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
