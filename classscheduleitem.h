#ifndef CLASSSCHEDULEITEM_H
#define CLASSSCHEDULEITEM_H

#include <QWidget>

namespace Ui {
class ClassScheduleItem;
}

class ClassScheduleItem : public QWidget
{
    Q_OBJECT

public:
    explicit ClassScheduleItem(QWidget *parent = nullptr);
    ~ClassScheduleItem();

    void setFields(QString CourseAbvAndNum, QString CourseName, QString MeetLocTime);

private:
    Ui::ClassScheduleItem *ui;
};

#endif // CLASSSCHEDULEITEM_H
