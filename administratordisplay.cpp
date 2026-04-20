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

    connect(ui->pushButton_search, &QPushButton::clicked, [=]() {
        u->searchCoursesEX(
            ui->lineEdit_CRN->text(),
            ui->lineEdit_Room->text(),
            ui->lineEdit_Professor->text(),
            ui->comboBox_days->currentText(),
            ui->comboBox_term->currentText(),
            ui->lineEdit_Course->text(),
            ui->lineEdit_sectionNum->text().toInt(),
            ui->comboBox_Level->currentText(),
            ui->lineEdit_subject->text(),
            ui->lineEdit_courseNum->text()
            );
    });

    connect(u, &User::searchResultsReady,
            this, &AdministratorDisplay::handleSearchResults);

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
    ui->tableView_results->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_results->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
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
    QAbstractItemModel *oldModel = ui->tableView_results1->model();
    if (oldModel && oldModel != model) {
        oldModel->deleteLater();
    }

    // -----------------------------
    // Transfer ownership to the view
    // -----------------------------
    model->setParent(ui->tableView_results1);
    ui->tableView_results1->setModel(model);

    // -----------------------------
    // UI polish
    // -----------------------------
    ui->tableView_results1->resizeColumnsToContents();
    ui->tableView_results1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_results1->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}
