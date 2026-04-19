#include "administratordisplay.h"
#include "ui_administratordisplay.h"
#include <qtabbar.h>

AdministratorDisplay::AdministratorDisplay(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdministratorDisplay)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->setCursor(Qt::PointingHandCursor);

    u = loggedIn;

    // conflict report handlers
    connect(ui->pushButton_generate, &QPushButton::clicked, [=]() {
        u->getConflictReport(ui->comboBox_term->currentText());
    });
    connect(u, &User::conflictReportReady,
            this, &AdministratorDisplay::handleConflictReports);
}

AdministratorDisplay::~AdministratorDisplay()
{
    delete ui;
}

void AdministratorDisplay::handleConflictReports(QStandardItemModel* model)
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