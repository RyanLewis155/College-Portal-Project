#include "user.h"
#include "queryparams.h"
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

    QJsonArray results = getCourseData(term, crn, subject, courseNum, days);

    qDebug() << "Received results:" << results.size();

    QStandardItemModel *model = new QStandardItemModel(this);

    if (results.isEmpty()) {
        emit searchResultsReady(model);
        return;
    }

    // ----------------------------
    // Build headers dynamically
    // ----------------------------
    QJsonObject firstRow = results[0].toObject();
    QStringList headers = firstRow.keys();

    model->setColumnCount(headers.size());
    model->setHorizontalHeaderLabels(headers);

    // ----------------------------
    // Fill rows
    // ----------------------------
    for (int i = 0; i < results.size(); ++i)
    {
        QJsonObject row = results[i].toObject();

        for (int j = 0; j < headers.size(); ++j)
        {
            QString key = headers[j];
            QString value;

            // handle nested objects (Supabase joins)
            if (row.value(key).isObject())
            {
                QJsonObject nested = row.value(key).toObject();

                // flatten nested object into string
                QStringList parts;
                for (auto it = nested.begin(); it != nested.end(); ++it)
                {
                    parts << it.value().toString();
                }

                value = parts.join(" ");
            }
            else
            {
                value = row.value(key).toString();
            }

            model->setItem(i, j, new QStandardItem(value));
        }
    }

    emit searchResultsReady(model);
}

QJsonArray User::getCourseData(const QString &term,
                               const QString &crn,
                               const QString &subject,
                               const QString &courseNum,
                               const QString &days)
{

    QueryParams params;

    // TODO: figure out joins
    // SELECT clause (Supabase embedded joins)
    params.select({
        "CRN",
        "startTime",
        "endTime",
        "days",
        "sectionNum",
        "subject",
        "courseNum",
        // "Room(building)",
        // "Room(room)",
        // "Course(name)",
        // "User(name)"
    });

    // WHERE clauses (only if provided)

    if (!term.isEmpty())
        params.where("term", EQ, term);

    if (!crn.isEmpty())
        params.where("CRN", EQ, crn);

    if (!subject.isEmpty())
        params.where("subject", EQ, subject);

    if (!courseNum.isEmpty())
        params.where("courseNum", EQ, courseNum);

    if (!days.isEmpty() && days != "")
        params.where("days", EQ, days);

    return Database::fetch("CourseSection", params);
}