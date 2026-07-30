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
    QString term;
    QString level;

    QString sectionNum;

    QString subject;
    QString courseNum;
    QString courseTitle;

    QString room;

    QString professorName;
    QString professorEmail;

};

CourseSection fromJson(const QJsonObject &obj);

QJsonObject toJson(const CourseSection &cs);



#endif // COURSESECTION_H
