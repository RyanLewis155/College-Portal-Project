#include "dashboard.h"
#include "ui_dashboard.h"

DashBoard::DashBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashBoard)
{
    ui->setupUi(this);
}

DashBoard::~DashBoard()
{
    delete ui;
}

void DashBoard::setDisplay(QWidget *displayWidget) {
    if (!displayWidget) return;

    ui->stackedWidget->addWidget(displayWidget);
    ui->stackedWidget->setCurrentWidget(displayWidget);

    qDebug() << "Dashboard central widget layout:" << centralWidget()->layout();
}
