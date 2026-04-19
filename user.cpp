#include "user.h"
#include "database.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QJsonObject>

User::User(QObject *parent)
    : QObject(parent)
{
}

User::~User()
{
}


void User::searchCourses(const QString &term,
                         const QString &crn,
                         const QString &subject,
                         const QString &courseNum,
                         const QString &days)
{
    QStringList crns = {crn}; // Convert single CRN to list for API
    QJsonArray results = Database::getCourseData(crns, term, subject, courseNum, days);

    qDebug() << "Received results:" << results.size();

    QStandardItemModel *model = new QStandardItemModel(this);

    // ----------------------------------
    // Define column order explicitly
    // ----------------------------------
    QStringList headers = {
        "CRN",
        "subject",
        "courseNum",
        "course",
        "section",
        "days",
        "startTime",
        "endTime",
        "building",
        "room",
        "instructor"
    };

    model->setColumnCount(headers.size());
    model->setHorizontalHeaderLabels(headers);

    if (results.isEmpty()) {
        emit searchResultsReady(model);
        return;
    }

    // ----------------------------------
    // Fill rows
    // ----------------------------------
    for (int i = 0; i < results.size(); ++i)
    {
        QJsonObject row = results[i].toObject();

        for (int j = 0; j < headers.size(); ++j)
        {
            QString key = headers[j];
            QString value = Database::jsonValueToString(row.value(key));

            model->setItem(i, j, new QStandardItem(value));
        }
    }

    emit searchResultsReady(model);
}