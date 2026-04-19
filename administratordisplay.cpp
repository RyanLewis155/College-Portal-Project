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

void AdministratorDisplay::handleSearchResults(QStandardItemModel *model)
{
    if (!model) {
        qDebug() << "Received null model";
        return;
    }

    qDebug() << "Received model with rows:" << model->rowCount();

    // -----------------------------
    // Clean up previous model safely
    // -----------------------------
    QAbstractItemModel *oldModel = ui->tableView_results->model();
    if (oldModel) {
        oldModel->deleteLater();
    }

    // -----------------------------
    // Transfer ownership to the view
    // -----------------------------
    model->setParent(ui->tableView_results);
    ui->tableView_results->setModel(model);

    // -----------------------------
    // UI polish
    // -----------------------------
    ui->tableView_results->resizeColumnsToContents();
}
