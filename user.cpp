#include "user.h"
#include "database.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QJsonObject>
#include "coursesection.h"

User::User(UserInfo u, QObject *parent)
    : QObject(parent)
{
    id = u.id;
    role = u.role;
    name = u.FullName;
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
    QJsonArray results = Database::getCourseData(crns, Building, Professor, Days, Term, Course, SectionNum, Level, Subject, CourseNum);

    qDebug() << "Received results:" << results.size();

    QStandardItemModel *model = new QStandardItemModel(this);

    // ----------------------------------
    // Define column order explicitly
    // ----------------------------------
    QStringList headers = {
        "CRN",
        "startTime",
        "endTime",
        "days",
        "section",
        "subject",
        "courseNum",
        "building",
        "room",
        "course",
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

void User::getConflictReport(const QString &term)
{
    // -------------------------
    // STEP 1: Validate courses
    // -------------------------
    QHash<QString, QStringList> conflicts = validateCourses(term);

    // -------------------------
    // STEP 2: Build model
    // -------------------------
    QStandardItemModel *model = new QStandardItemModel();

    model->setHorizontalHeaderLabels({"CRN", "Conflict Reason"});

    // -------------------------
    // STEP 3: Populate rows
    // -------------------------
    for (auto it = conflicts.begin(); it != conflicts.end(); ++it) {
        const QString &crn = it.key();
        const QStringList &reasons = it.value();

        for (const QString &reason : reasons) {
            QList<QStandardItem*> row;

            if (reason == "scheduleConflict")
                continue;

            row.append(new QStandardItem(crn));
            row.append(new QStandardItem(reason));

            model->appendRow(row);
        }
    }

    // -------------------------
    // STEP 4: Emit result
    // -------------------------
    emit conflictReportReady(model);
}

QHash<QString, QStringList> User::validateCourses(const QString &term, const QStringList &crns)
{
    QHash<QString, QStringList> conflictReasons;

    QJsonArray data;
    // if crns specified, get that data; otherwise get all courses for the term
    if (!crns.isEmpty()) {
        data = Database::getCourseData(crns);
    } else {
        data = Database::getCourseData({}, "", "", "", term);
    }

    struct Course {
        QString crn;
        QSet<QChar> days;
        int start;
        int end;
        QString building;
        QString room;
        QString instructor;
        QString courseName;
        QString sectionNum;
        QString level;
    };

    QVector<Course> courses;

    // -------------------------
    // Helpers
    // -------------------------
    auto parseDays = [](const QString &days) {
        QSet<QChar> result;
        for (QChar c : days)
            result.insert(c);
        return result;
    };

    auto parseTime = [](const QString &timeStr) {
        QTime t = QTime::fromString(timeStr, "HH:mm:ss");
        if (!t.isValid())
            t = QTime::fromString(timeStr, "HH:mm");
        return t.hour() * 60 + t.minute();
    };

    auto overlaps = [](const Course *a, const Course *b) {
        return a->start < b->end && b->start < a->end;
    };

    auto addReason = [&](const QString &crn, const QString &reason) {
        if (!conflictReasons[crn].contains(reason))
            conflictReasons[crn].append(reason);
    };

    // -------------------------
    // STEP 1: Normalize JSON → Course
    // -------------------------
    for (const QJsonValue &val : data) {
        QJsonObject obj = val.toObject();

        Course c;
        c.crn = Database::jsonValueToString(obj["CRN"]); /*obj["CRN"].toString();*/
        c.days = parseDays(Database::jsonValueToString(obj["days"]));
        c.start = parseTime(Database::jsonValueToString(obj["startTime"]));
        c.end = parseTime(Database::jsonValueToString(obj["endTime"]));
        c.building = Database::jsonValueToString(obj["building"]);
        c.room = Database::jsonValueToString(obj["room"]);
        c.instructor = Database::jsonValueToString(obj["instructor"]);
        c.courseName = Database::jsonValueToString(obj["course"]);
        c.sectionNum = Database::jsonValueToString(obj["section"]);
        c.level = Database::jsonValueToString(obj["level"]);

        courses.append(c);
    }

    // -------------------------
    // STEP 1.5: Missing/null field validation
    // -------------------------
    struct FieldCheck {
        QString value;
        QString label;
    };
    QSet<QString> invalidCRNs;
    for (int i = 0; i < courses.size(); ++i) {
        const Course &c = courses[i];
        const QJsonObject obj = data[i].toObject();

        // Raw string fields
        struct FieldCheck { QString value; QString label; };
        const QList<FieldCheck> fields = {
                                           { Database::jsonValueToString(obj["startTime"]), "assigned time"   },
                                           { c.room,                                        "assigned room"        },
                                           { c.instructor,                                  "assigned instructor"  }
                                           };
        for (const FieldCheck &f : fields) {
            if (f.value.trimmed().isEmpty()) {
                addReason(c.crn, QString("Missing %1").arg(f.label));
                invalidCRNs.insert(c.crn);
            }
        }
    }

    // -------------------------
    // STEP 2: Expand by day
    // -------------------------
    struct CourseDay {
        const Course *course;
        QChar day;
    };

    QHash<QString, QVector<const CourseDay*>> roomGroups;
    QHash<QString, QVector<const CourseDay*>> instructorGroups;

    QVector<CourseDay*> storage;

    for (const Course &c : courses) {
        if (invalidCRNs.contains(c.crn)) continue;
        for (QChar d : c.days) {
            QString roomKey = c.building + "|" + c.room + "|" + d;
            QString profKey = c.instructor + "|" + d;

            CourseDay *cd = new CourseDay{&c, d};

            roomGroups[roomKey].append(cd);
            instructorGroups[profKey].append(cd);

            storage.append(cd);
        }
    }

    // -------------------------
    // STEP 3: Room & Duplicate conflicts
    // -------------------------
    for (auto it = roomGroups.begin(); it != roomGroups.end(); ++it) {
        const QVector<const CourseDay*> &group = it.value();
        for (int i = 0; i < group.size(); ++i) {
            for (int j = i + 1; j < group.size(); ++j) {
                const CourseDay *a = group[i];
                const CourseDay *b = group[j];
                if (invalidCRNs.contains(a->course->crn) || invalidCRNs.contains(b->course->crn))
                    continue;
                if (!overlaps(a->course, b->course))
                    continue;
                if ((a->course->courseName == b->course->courseName) && (a->course->level == b->course->level)) {
                    QString msg = QString("Duplicate Listing with %1").arg(b->course->crn);
                    QString msg2 = QString("Duplicate Listing with %1").arg(a->course->crn);
                    addReason(a->course->crn, msg);
                    addReason(b->course->crn, msg2);
                } else {
                    QString loc = QString("%1 %2").arg(a->course->building, a->course->room);
                    QString day = QString(a->day);
                    QString msg = QString("Room conflict with %1 - %2 on %3").arg(b->course->crn, loc, day);
                    QString msg2 = QString("Room conflict with %1 - %2 on %3").arg(a->course->crn, loc, day);
                    addReason(a->course->crn, msg);
                    addReason(b->course->crn, msg2);
                }
            }
        }
    }
    // -------------------------
    // STEP 4: Instructor conflicts
    // -------------------------
    for (auto it = instructorGroups.begin(); it != instructorGroups.end(); ++it) {
        const QVector<const CourseDay*> &group = it.value();
        for (int i = 0; i < group.size(); ++i) {
            for (int j = i + 1; j < group.size(); ++j) {
                const CourseDay *a = group[i];
                const CourseDay *b = group[j];
                if (invalidCRNs.contains(a->course->crn) || invalidCRNs.contains(b->course->crn))
                    continue;
                if (!overlaps(a->course, b->course))
                    continue;
                if (a->course->courseName == b->course->courseName)
                    continue; // already caught as duplicate above
                QString day = QString(a->day);
                QString msg = QString("Instructor conflict with %1 - %2 on %3").arg(b->course->crn, a->course->instructor, day);
                QString msg2 = QString("Instructor conflict with %1 - %2 on %3").arg(a->course->crn, a->course->instructor, day);
                addReason(a->course->crn, msg);
                addReason(b->course->crn, msg2);
            }
        }
    }
    // -------------------------
    // STEP 5: Unreasonable times
    // -------------------------
    const int earliest = 8 * 60;       // 08:00
    const int latest   = 19 * 60 + 45; // 19:45
    for (const Course &c : courses) {
        if (invalidCRNs.contains(c.crn)) continue;
        if (c.start < earliest || c.end > latest) {
            // Reconstruct human-readable times from minute offsets
            auto minToStr = [](int m) {
                return QTime(m / 60, m % 60).toString("h:mm AP");
            };
            QString msg = QString("Unreasonable time - %1 to %2")
                              .arg(minToStr(c.start), minToStr(c.end));
            addReason(c.crn, msg);
        }
    }
    // -------------------------
    // STEP 6: Schedule conflicts (generic, for external use)
    // -------------------------
    // Build a flat day-keyed list of all course-days for O(n^2) per-day scan
    QHash<QChar, QVector<const CourseDay*>> dayGroups;
    for (const CourseDay *cd : storage)
        dayGroups[cd->day].append(cd);

    for (auto it = dayGroups.begin(); it != dayGroups.end(); ++it) {
        const QVector<const CourseDay*> &group = it.value();
        for (int i = 0; i < group.size(); ++i) {
            for (int j = i + 1; j < group.size(); ++j) {
                const CourseDay *a = group[i];
                const CourseDay *b = group[j];
                if (invalidCRNs.contains(a->course->crn) || invalidCRNs.contains(b->course->crn))
                    continue;
                // Skip pairs that are literally the same course object
                if (a->course == b->course)
                    continue;
                if (!overlaps(a->course, b->course))
                    continue;
                addReason(a->course->crn, "scheduleConflict");
                addReason(b->course->crn, "scheduleConflict");
            }
        }
    }
    // -------------------------
    // Cleanup & return
    // -------------------------
    qDeleteAll(storage);
    return conflictReasons;
}

//     // -------------------------
//     // STEP 3: ROOM CONFLICTS
//     // -------------------------
//     for (auto &group : roomGroups) {
//         auto list = group;

//         std::sort(list.begin(), list.end(), [](auto a, auto b) {
//             return a->course->start < b->course->start;
//         });

//         for (int i = 0; i < list.size(); ++i) {
//             for (int j = i + 1; j < list.size(); ++j) {

//                 if (list[j]->course->start >= list[i]->course->end)
//                     break;

//                 if (overlaps(list[i]->course, list[j]->course)) {

//                     const Course *a = list[i]->course;
//                     const Course *b = list[j]->course;

//                     // skip if same course name
//                     if (a->courseName == b->courseName)
//                         continue;

//                     QString reasonA = QString("Room conflict with course %4 (%1 %2 on %3)")
//                                           .arg(a->building)
//                                           .arg(a->room)
//                                           .arg(list[i]->day)
//                                           .arg(b->crn);

//                     QString reasonB = QString("Room conflict with course %4 (%1 %2 on %3)")
//                                           .arg(b->building)
//                                           .arg(b->room)
//                                           .arg(list[j]->day)
//                                           .arg(a->crn);

//                     addReason(a->crn, reasonA);
//                     addReason(b->crn, reasonB);
//                 }
//             }
//         }
//     }

//     // -------------------------
//     // STEP 4: INSTRUCTOR CONFLICTS
//     // -------------------------
//     for (auto &group : instructorGroups) {
//         auto list = group;

//         std::sort(list.begin(), list.end(), [](auto a, auto b) {
//             return a->course->start < b->course->start;
//         });

//         for (int i = 0; i < list.size(); ++i) {
//             for (int j = i + 1; j < list.size(); ++j) {

//                 if (list[j]->course->start >= list[i]->course->end)
//                     break;

//                 if (overlaps(list[i]->course, list[j]->course)) {

//                     const Course *a = list[i]->course;
//                     const Course *b = list[j]->course;

//                     bool sameRoomSameTime =
//                         a->building == b->building &&
//                         a->room == b->room &&
//                         a->start == b->start &&
//                         a->end == b->end;

//                     if (!sameRoomSameTime) {
//                         QString reasonA = QString("Instructor conflict with course %3 (%1 on %2)")
//                                               .arg(a->instructor)
//                                               .arg(list[i]->day)
//                                               .arg(b->crn);

//                         QString reasonB = QString("Instructor conflict with course %3 (%1 on %2)")
//                                               .arg(b->instructor)
//                                               .arg(list[i]->day)
//                                               .arg(a->crn);

//                         addReason(a->crn, reasonA);
//                         addReason(b->crn, reasonB);
//                     }
//                     }
//                 }
//             }
//         }

//     qDeleteAll(storage);
//     return conflictReasons;
// }
