#ifndef SECTION_H
#define SECTION_H

#include <QObject>
#include <QTime>

#include "room.h"

class Section : public QObject
{
    Q_OBJECT

public:
    explicit Section(QObject *parent = nullptr) : QObject(parent) {};

explicit Section(const QString& CRN,
                 const QString& sectionNum,
                 Room *room,
                 const QString& professorName,
                 const QString& level,
                 const QString& courseNum,
                 const QList<QString>& TAs_name,
                 const QTime& startTime,
                 const QTime& endTime,
                 const QString& days,
                 const QString& term,
                 const int& enrolledCount,
                 QObject *parent = nullptr)
                :
                CRN(CRN),
                sectionNum(sectionNum),
                room(room),
                professorName(professorName),
                level(level),
                courseNum(courseNum),
                TAs_name(TAs_name),
                startTime(startTime),
                endTime(endTime),
                days(days),
                term(term),
                enrolledCount(enrolledCount)
                {};

private:
    QString CRN;
    QString sectionNum;
    Room *room;
    QString professorName;
    QString level;
    QString courseNum;
    QList<QString> TAs_name;
    QTime startTime;
    QTime endTime;
    QString days;
    QString term;
    int enrolledCount;
};

#endif // SECTION_H
