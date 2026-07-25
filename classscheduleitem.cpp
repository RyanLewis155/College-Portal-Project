#include "classscheduleitem.h"
#include "ui_classscheduleitem.h"

ClassScheduleItem::ClassScheduleItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClassScheduleItem)
{
    ui->setupUi(this);
}

ClassScheduleItem::~ClassScheduleItem()
{
    delete ui;
}

void ClassScheduleItem::setFields(QString CourseAbvAndNum, QString CourseName, QString MeetLocTime)
{
    ui->label->setText(CourseAbvAndNum);
    ui->label_2->setText(CourseName);
    ui->label_3->setText(MeetLocTime);
}
