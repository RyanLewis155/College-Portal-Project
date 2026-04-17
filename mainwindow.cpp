#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "studentdisplay.h"

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

void MainWindow::handleLoginSuccess()
{
    int role = 0;

    switch (role) {
        case 0:
            dashBoardWindow = new StudentDisplay();
            break;
        case 1:
            //display = new ProfessorDisplay();
            break;

        case 2:
            //display = new AdminstratorDisplay();
            break;

        case 3:
            //display = new BoardMemberDisplay();
            break;

        default:
            break;
    }

    if(dashBoardWindow)
    {
        ui->stackedWidget->addWidget(dashBoardWindow);
        // dashBoardWindow->show();
        ui->stackedWidget->setCurrentWidget(dashBoardWindow);
    }
}

