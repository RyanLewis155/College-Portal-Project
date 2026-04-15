#include "studentdisplay.h"
#include "ui_studentdisplay.h"

StudentDisplay::StudentDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentDisplay)
{
    ui->setupUi(this);

    QList<ClassScheduleItem*> classList;
    ClassScheduleItem* class1 = new ClassScheduleItem();
    ClassScheduleItem* class2 = new ClassScheduleItem();
    ClassScheduleItem* class3 = new ClassScheduleItem();
    ClassScheduleItem* class4 = new ClassScheduleItem();
    ClassScheduleItem* class5 = new ClassScheduleItem();

    class1->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class2->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class3->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class4->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class5->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));

    classList.append(class1);
    classList.append(class2);
    classList.append(class3);
    classList.append(class4);
    classList.append(class5);

    PopulateClasses(classList);

    QGridLayout *registrationLayout = qobject_cast<QGridLayout*>(ui->widget_Register->layout());



}

StudentDisplay::~StudentDisplay()
{
    delete ui;
}

void StudentDisplay::PopulateClasses(QList<ClassScheduleItem*> classSchedule)
{
    QGridLayout* gridLayout = qobject_cast<QGridLayout*>(ui->widget_ClassSchedule->layout());

    for(int i = 0; i < classSchedule.count(); ++i)
    {
        gridLayout->addWidget(classSchedule[i], i/3, i % 3);
    }
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

