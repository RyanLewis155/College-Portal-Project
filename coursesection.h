#ifndef COURSESECTION_H
#define COURSESECTION_H
#include <QString>
#include <QJsonObject>


struct CourseSection
{
    QString crn;

    QString startTime;
    QString endTime;
    QString days;

    int sectionNum = 0;

    QString subject;
    QString courseNum;
    QString term;

    QString building;
    QString room;
    QString capacity;

    QString coursename;
    QString instructorname;

    QString level;
};

CourseSection fromJson(const QJsonObject &obj);



#endif // COURSESECTION_H
