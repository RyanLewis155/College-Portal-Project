#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QObject>
#include <QDate>

#include "section.h"

class Schedule : public QObject
{
    Q_OBJECT
public:
    explicit Schedule(QObject *parent = nullptr);

    explicit Schedule(const QString& scheduleID,
                      const QString& semester,
                      const QDate& year,
                      const int& totalCredits,
                      const QList<Section*>& sections)
                      :
                      scheduleID(scheduleID),
                      semester(semester),
                      year(year),
                      totalCredits(totalCredits),
                      sections(sections) {};

private:
    QString scheduleID;
    QString semester;
    QDate year;
    int totalCredits;
    QList<Section*> sections;

signals:
};

#endif // SCHEDULE_H
