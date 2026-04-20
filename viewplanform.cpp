#include "viewplanform.h"
#include "ui_viewplanform.h"

ViewPlanForm::ViewPlanForm(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewPlanForm)
{
    ui->setupUi(this);
    u = loggedIn;

    QJsonArray results = Database::getPlans(u->id);

    for (QJsonValueRef result : results)
    {
        QJsonObject resultObj = result.toObject();
        QString tempId = QString::number(resultObj["id"].toInteger());
        QString tempPlanName = resultObj["planName"].toString();
        Plan *newPlan = new Plan(tempId, tempPlanName);
        plans.append(newPlan);

        QListWidgetItem *newItem = new QListWidgetItem(tempPlanName);
        newItem->setData(Qt::UserRole, tempId);
        ui->listWidget_PlanList->addItem(newItem);
    }
}

ViewPlanForm::~ViewPlanForm()
{
    delete ui;
}

void ViewPlanForm::on_pushButton_AddPlan_clicked()
{
    QString newPlanName = ui->lineEdit_NewPlanName->text();
    if (newPlanName.isEmpty())
    {
        newPlanName = "newPlan";
    }
    QString studentId = u->id;

    QString newPlanId = enterNewPlan(studentId, newPlanName);

    Plan *newPlan = new Plan(newPlanId, newPlanName);
    plans.append(newPlan);

    QListWidgetItem *newItem = new QListWidgetItem(newPlanName);
    newItem->setData(Qt::UserRole, newPlanId);
    ui->listWidget_PlanList->addItem(newItem);
}

QString ViewPlanForm::enterNewPlan(const QString &studentID, const QString &planName)
{
    QJsonObject planInfo;
    planInfo["planName"] = planName;
    planInfo["studentID"] = studentID.toLongLong();
    QJsonObject result = Database::insert("Plan", planInfo);
    return QString::number(result["id"].toInteger());
}