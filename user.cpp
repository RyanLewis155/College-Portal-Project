#include "user.h"
#include "database.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QJsonObject>
#include "coursesection.h"

User::User(QObject *parent)
    : QObject(parent)
{
}

User::~User()
{
}

// ===== Public Methods Implementation =====

// void User::searchCourses(const QString &crn)
// {
//     qDebug() << "Searching courses for CRN:" << crn;

//     // TODO: Replace with real DB/API call
//     QVector<QMap<QString, QString>> results;

//     QMap<QString, QString> row;
//     row["CRN"] = crn;
//     row["CourseName"] = "Example Course";
//     row["Instructor"] = "Dr. Smith";

//     results.append(row);

//     emit searchResultsReady(results);
// }

void User::searchCourses(const QString &term,
                         const QString &crn,
                         const QString &subject,
                         const QString &courseNum,
                         const QString &days)
{
    QStringList crns = {crn}; // Convert single CRN to list for API
    QVector<CourseSection> results = Database::getCourseData(crns, term, subject, courseNum, days);

    qDebug() << "Received results:" << results.size();

    QStandardItemModel *model = new QStandardItemModel(this);

    if (results.isEmpty()) {
        emit searchResultsReady(model);
        return;
    }

    model->setRowCount(results.size());
    model->setColumnCount(11);

    model->setHorizontalHeaderLabels({
        "CRN",
        "Start Time",
        "End Time",
        "Days",
        "Section",
        "Subject",
        "Course #",
        "Building",
        "Room",
        "Course",
        "Instructor"
    });


    for (int i = 0; i < results.size(); ++i)
    {
        const CourseSection &cs = results[i];

        model->setItem(i, 0, new QStandardItem(cs.crn));
        model->setItem(i, 1, new QStandardItem(cs.startTime));
        model->setItem(i, 2, new QStandardItem(cs.endTime));
        model->setItem(i, 3, new QStandardItem(cs.days));
        model->setItem(i, 4, new QStandardItem(QString::number(cs.sectionNum)));
        model->setItem(i, 5, new QStandardItem(cs.subject));
        model->setItem(i, 6, new QStandardItem(cs.courseNum));
        model->setItem(i, 7, new QStandardItem(cs.building));
        model->setItem(i, 8, new QStandardItem(cs.room));
        model->setItem(i, 9, new QStandardItem(cs.coursename));
        model->setItem(i,10, new QStandardItem(cs.instructorname));
    }

    emit searchResultsReady(model);
}

void User::searchCoursesEX(const QString &CRN,
                           const QString &Building,
                           const QString &Professor,
                           const QString &Days,
                           const QString &Term,
                           const QString &Course,
                           const int &SectionNum,
                           const QString &Level,
                           const QString &Subject,
                           const QString &CourseNum
                           )
{
    QStringList crns = {CRN}; // Convert single CRN to list for API
    QVector<CourseSection> results = Database::getCourseData(crns, Building, Professor, Days, Term, Course, SectionNum, Level, Subject, CourseNum);

    qDebug() << "Received results:" << results.size();

    QStandardItemModel *model = new QStandardItemModel(this);


    if (results.isEmpty()) {
        emit searchResultsReady(model);
        qDebug() << "Results were empty";
        return;
    }


    model->setRowCount(results.size());
    model->setColumnCount(11);

    model->setHorizontalHeaderLabels({
        "CRN",
        "Start Time",
        "End Time",
        "Days",
        "Section",
        "Subject",
        "Course #",
        "Building",
        "Room",
        "Course",
        "Instructor"
    });

    for (int i = 0; i < results.size(); ++i)
    {
        const CourseSection &cs = results[i];

        model->setItem(i, 0, new QStandardItem(cs.crn));
        model->setItem(i, 1, new QStandardItem(cs.startTime));
        model->setItem(i, 2, new QStandardItem(cs.endTime));
        model->setItem(i, 3, new QStandardItem(cs.days));
        model->setItem(i, 4, new QStandardItem(QString::number(cs.sectionNum)));
        model->setItem(i, 5, new QStandardItem(cs.subject));
        model->setItem(i, 6, new QStandardItem(cs.courseNum));
        model->setItem(i, 7, new QStandardItem(cs.building));
        model->setItem(i, 8, new QStandardItem(cs.room));
        model->setItem(i, 9, new QStandardItem(cs.coursename));
        model->setItem(i,10, new QStandardItem(cs.instructorname));
    }

    emit searchResultsReady(model);

}