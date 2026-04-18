#include "administratordisplay.h"
#include "ui_administratordisplay.h"
#include <qtabbar.h>

AdministratorDisplay::AdministratorDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdministratorDisplay)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->setCursor(Qt::PointingHandCursor);
}

AdministratorDisplay::~AdministratorDisplay()
{
    delete ui;
}
