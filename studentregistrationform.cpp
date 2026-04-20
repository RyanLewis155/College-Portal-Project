#include "studentregistrationform.h"
#include "ui_studentregistrationform.h"
#include <QMessageBox>
#include "user.h"

StudentRegistrationForm::StudentRegistrationForm(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentRegistrationForm)
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
}

StudentRegistrationForm::~StudentRegistrationForm()
{
    delete ui;
}

void StudentRegistrationForm::handleRegistrationComplete(const QString &message)
{
    QMessageBox::information(this, "Registration Status", message);
}
