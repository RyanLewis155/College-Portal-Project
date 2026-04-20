#include "viewplanform.h"
#include "ui_viewplanform.h"

ViewPlanForm::ViewPlanForm(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewPlanForm)
{
    ui->setupUi(this);
    u = loggedIn;
}

ViewPlanForm::~ViewPlanForm()
{
    delete ui;
}

void ViewPlanForm::on_pushButton_AddPlan_clicked()
{
    QJsonObject planInfo;
    QString newPlanName = ui->lineEdit_NewPlanName->text();
    if (newPlanName.isEmpty())
    {
        newPlanName = "newPlan";
    }
    QString studentId = u->id;

    planInfo["planName"] = newPlanName;
    planInfo["studentID"] = studentId.toLongLong();

    QJsonObject result = Database::insert("Plan", planInfo);
}

