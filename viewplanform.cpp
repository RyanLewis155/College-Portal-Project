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

    if (!newPlanId.isEmpty())
    {
        QMessageBox::information(this, "Success", "Plan: " + newPlanName + " created successfully!");
        QListWidgetItem *newItem = new QListWidgetItem(newPlanName);
        newItem->setData(Qt::UserRole, newPlanId);
        ui->listWidget_PlanList->addItem(newItem);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to create plan. Please try again.");
    }
}

QString ViewPlanForm::enterNewPlan(const QString &studentID, const QString &planName)
{
    QJsonObject planInfo;
    planInfo["planName"] = planName;
    planInfo["studentID"] = studentID.toLongLong();
    QJsonObject result = Database::insert("Plan", planInfo);
    return QString::number(result["id"].toInteger());
}

//returns the inserted row
QJsonObject ViewPlanForm::enterPlanItem(const QString &planID, const QString &crn)
{
    QJsonObject planItemInfo;
    planItemInfo["planID"] = planID.toLongLong();
    planItemInfo["CRN"] = crn.toLongLong();
    return Database::insert("PlanItem", planItemInfo);
}
void ViewPlanForm::on_pushButton_AddPlanItem_clicked()
{
    //if no plan selected
    if (ui->listWidget_PlanList->currentRow() == -1)
    {
        QMessageBox::warning(this, "No Plan Selected", "Please select a plan first.");
        return;
    }

    QString crn = ui->lineEdit_CourseToAdd->text();

    if(crn.isEmpty())
    {
        QMessageBox::warning(this, "No CRN Entered", "Please enter a CRN first.");
        return;
    }

    QListWidgetItem *item = ui->listWidget_PlanList->currentItem();
    QString planID = item->data(Qt::UserRole).toString();

    //getting relevant course info
    QStringList crns = {crn};
    QVector<CourseSection> crnResults = Database::getCourseData(crns);

    //check if crn is valid
    if (!crnResults.isEmpty())
    {
        QJsonObject planItemResult = enterPlanItem(planID, crn);
        if (!planItemResult.isEmpty())
        {
            QMessageBox::information(this, "Success", "Course added successfully!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to add course. Please try again.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Invalid CRN", "The CRN you entered does not exist.");
        return;
    }
    return;
}