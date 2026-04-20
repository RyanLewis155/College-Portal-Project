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
void ViewPlanForm::on_listWidget_PlanList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (current == nullptr) return;
    QString planID = current->data(Qt::UserRole).toString();
    loadPlanItems(planID);
}

void ViewPlanForm::loadPlanItems(const QString &planID)
{
    ui->tableWidget_PlanClasses->clearContents();
    ui->tableWidget_PlanClasses->setRowCount(0);

    QJsonArray results = Database::getPlanItems(planID);
    QStringList crns;

    //put crns in a list
    for (QJsonValueRef result : results)
    {
        QJsonObject resultObj = result.toObject();
        QString tempCRN = QString::number(resultObj["CRN"].toInteger());
        crns.append(tempCRN);
    }

    if (crns.isEmpty())
    {
        return;
    }

    //get course data for all crns
    QVector<CourseSection> courses = Database::getCourseData(crns);
    ui->tableWidget_PlanClasses->setColumnCount(11);
    ui->tableWidget_PlanClasses->setHorizontalHeaderLabels({
        "CRN", "Start Time", "End Time", "Days", "Section",
        "Subject", "Course #", "Building", "Room", "Course", "Instructor"
    });

    for (const CourseSection &cs : courses) {
        int row = ui->tableWidget_PlanClasses->rowCount();
        ui->tableWidget_PlanClasses->insertRow(row);
        ui->tableWidget_PlanClasses->setItem(row, 0,  new QTableWidgetItem(cs.crn));
        ui->tableWidget_PlanClasses->setItem(row, 1,  new QTableWidgetItem(cs.startTime));
        ui->tableWidget_PlanClasses->setItem(row, 2,  new QTableWidgetItem(cs.endTime));
        ui->tableWidget_PlanClasses->setItem(row, 3,  new QTableWidgetItem(cs.days));
        ui->tableWidget_PlanClasses->setItem(row, 4,  new QTableWidgetItem(QString::number(cs.sectionNum)));
        ui->tableWidget_PlanClasses->setItem(row, 5,  new QTableWidgetItem(cs.subject));
        ui->tableWidget_PlanClasses->setItem(row, 6,  new QTableWidgetItem(cs.courseNum));
        ui->tableWidget_PlanClasses->setItem(row, 7,  new QTableWidgetItem(cs.building));
        ui->tableWidget_PlanClasses->setItem(row, 8,  new QTableWidgetItem(cs.room));
        ui->tableWidget_PlanClasses->setItem(row, 9,  new QTableWidgetItem(cs.coursename));
        ui->tableWidget_PlanClasses->setItem(row, 10, new QTableWidgetItem(cs.instructorname));
    }
}

