#include "studentregistrationform.h"
#include "ui_studentregistrationform.h"

StudentRegistrationForm::StudentRegistrationForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentRegistrationForm)
{
    ui->setupUi(this);


}

StudentRegistrationForm::~StudentRegistrationForm()
{
    delete ui;
}
