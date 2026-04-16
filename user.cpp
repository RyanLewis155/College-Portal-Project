#include "user.h"
#include <QDebug>

User::User(QObject *parent)
    : QObject(parent)
{
}

User::~User()
{
}

// ===== Public Methods Implementation =====

void User::searchCourses(const QString &crn)
{
    qDebug() << "Searching courses for CRN:" << crn;

    // TODO: Replace with real DB/API call
    QVector<QMap<QString, QString>> results;

    QMap<QString, QString> row;
    row["CRN"] = crn;
    row["CourseName"] = "Example Course";
    row["Instructor"] = "Dr. Smith";

    results.append(row);

    emit searchResultsReady(results);
}