#include "studentdisplay.h"
#include "ui_studentdisplay.h"

StudentDisplay::StudentDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentDisplay)
{
    ui->setupUi(this);
}

StudentDisplay::~StudentDisplay()
{
    delete ui;
}

/////////////////From Course Registration///////////////////
void StudentDisplay::on_pushButton_RegSC_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_SearchCourses);
}


void StudentDisplay::on_pushButton_RegCS_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_ClassSchedule);
}


void StudentDisplay::on_pushButton_RegViewPlans_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_ViewPlans);
}
////////////////////////////////////////////////////////////



/////////////////From Search Courses///////////////////
void StudentDisplay::on_pushButton_SCCS_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_ClassSchedule);
}


void StudentDisplay::on_pushButton_SCReg_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Register);
}


void StudentDisplay::on_pushButton_SCViewPlans_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_ViewPlans);
}
////////////////////////////////////////////////////////////



/////////////////From View Plans///////////////////
void StudentDisplay::on_pushButton_VPCS_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_ClassSchedule);
}


void StudentDisplay::on_pushButton_VPReg_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Register);
}


void StudentDisplay::on_pushButton_VPSC_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_SearchCourses);
}
////////////////////////////////////////////////////////////




/////////////////From Class Schedules///////////////////
void StudentDisplay::on_pushButton_CSReg_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Register);
}


void StudentDisplay::on_pushButton_CSViewPlans_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_ViewPlans);
}


void StudentDisplay::on_pushButton_CSSC_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_SearchCourses);
}
////////////////////////////////////////////////////////////

