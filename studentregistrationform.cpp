#include "studentregistrationform.h"
#include "ui_studentregistrationform.h"
#include <QMessageBox>
#include "user.h"
#include "database.h"

#include <QPushButton>
#include <QMessageBox>
#include <QJsonObject>
#include <QDebug>

StudentRegistrationForm::StudentRegistrationForm(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentRegistrationForm),
     u(loggedIn)
{
    ui->setupUi(this);
    u = loggedIn;

    // registration handlers
    connect(ui->pushButton_CRNRegister, &QPushButton::clicked, [=]() {
        QStringList crns = {ui->textEdit_course1->toPlainText(), ui->textEdit_course2->toPlainText(),
                            ui->textEdit_course3->toPlainText()};
        QStringList crnsEntered;
        for (const QString &crn : crns) {
            if (!crn.trimmed().isEmpty()) {
                crnsEntered.append(crn.trimmed());
            }
        }
        u->handleRegistration(ui->comboBox_RegSemester->currentText(), crnsEntered);
    });
    connect(u, &User::registrationComplete,
            this, &StudentRegistrationForm::handleRegistrationComplete);

    connect(u, &User::searchResultsReady,
            this, &StudentRegistrationForm::handleSearchResults);

    connect(ui->pushButton_Search, &QPushButton::clicked,
            this, &StudentRegistrationForm::onSearchClicked);

    connect(ui->pushButton_CRNRegister, &QPushButton::clicked,
            this, &StudentRegistrationForm::onRegisterClicked);

    connect(ui->pushButton_Waitlisted, &QPushButton::clicked,
            this, &StudentRegistrationForm::onWaitlistClicked);

}

StudentRegistrationForm::~StudentRegistrationForm()
{
    delete ui;
}
void StudentRegistrationForm::handleRegistrationComplete(const QString &message)
{
    QMessageBox::information(this, "Registration Status", message);
}
void StudentRegistrationForm::handleSearchResults(QStandardItemModel* model)
{
    if (!model) {
        qDebug() << "Received null model";
        return;
    }

    QAbstractItemModel *oldModel = ui->tableView_results->model();
    if (oldModel) {
        oldModel->deleteLater();
    }

    model->setParent(ui->tableView_results);
    ui->tableView_results->setModel(model);
    ui->tableView_results->resizeColumnsToContents();
}

void StudentRegistrationForm::onSearchClicked()
{
    u->searchCourses(
        ui->comboBox_RegSemester->currentText(),
        ui->lineEdit_CRN->text(),
        ui->lineEdit_Subject->text(),
        ui->lineEdit_coursenumber->text(),
        ui->lineEdit_days->text()

        );
}

void StudentRegistrationForm::onRegisterClicked()
{
    QModelIndex index = ui->tableView_results->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Register", "Please select a course first.");
        return;
    }

    int row = index.row();
    QString crn = ui->tableView_results->model()->index(row, 0).data().toString();

    QJsonObject data;
    data["studentID"] = u->id;
    data["CRN"] = crn;
    data["status"] = "Registered";

    Database::insert("Registration", data);

    QMessageBox::information(this, "Register", "Course registration submitted.");
}

void StudentRegistrationForm::onWaitlistClicked()
{
    QModelIndex index = ui->tableView_results->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Waitlist", "Please select a course first.");
        return;
    }

    int row = index.row();
    QString crn = ui->tableView_results->model()->index(row, 0).data().toString();

    QJsonObject data;
    data["studentID"] = u->id;
    data["CRN"] = crn;
    data["status"] = "Waitlisted";

    Database::insert("Registration", data);

    QMessageBox::information(this, "Waitlist", "Student added to waitlist.");
}
