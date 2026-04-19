#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "studentdisplay.h"
#include "professordisplay.h"
#include "administratordisplay.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->stackedWidget);
    loginWindow = new LoginWindow();

    connect(loginWindow, &LoginWindow::loginSuccessful,
            this, &MainWindow::handleLoginSuccess);

    ui->stackedWidget->addWidget(loginWindow);

    loginWindow->show();

    ui->stackedWidget->setCurrentWidget(loginWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleLoginSuccess(UserInfo userInfo)
{
    QString role = userInfo.role;

    if (role == "Student")
        dashBoardWindow = new StudentDisplay();
    else if (role == "Professor")
        dashBoardWindow = new ProfessorDisplay();
    else if (role == "Administrator")
        dashBoardWindow = new AdministratorDisplay();

    if(dashBoardWindow)
    {
        ui->stackedWidget->addWidget(dashBoardWindow);
        // dashBoardWindow->show();
        ui->stackedWidget->setCurrentWidget(dashBoardWindow);
    }
}

