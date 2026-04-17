#include "studentdisplay.h"
#include "ui_studentdisplay.h"
#include "studentregistrationform.h"
#include "viewplanform.h"


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
    QGridLayout *viewPlanLayout = qobject_cast<QGridLayout*>(ui->widget_ViewPlans->layout());


    registrationLayout->addWidget(new StudentRegistrationForm());
    viewPlanLayout->addWidget(new ViewPlanForm());

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


