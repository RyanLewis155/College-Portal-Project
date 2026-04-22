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
    int buildingID = 0;
    QString room;
    QString capacity;

    QString coursename;
    int courseID = 0;
    QString instructorname;
    int professorID = 0;

    QString level;
};

CourseSection fromJson(const QJsonObject &obj);

QJsonObject toJson(const CourseSection &cs);



#endif // COURSESECTION_H
