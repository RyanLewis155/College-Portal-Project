#include "user.h"
#include "database.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QJsonObject>
#include "coursesection.h"
#include "course.h"
#include "room.h"

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

void User::searchForSingleCourse(const QString &CRN)
{
    QStringList crns = {CRN}; // Convert single CRN to list for API
    QVector<CourseSection> results = Database::getCourseData(crns);

    const CourseSection &cs = results[0];

    emit searchForCourseReady(cs);
}

void User::searchCourses(const QString &term,
                        const QString &crn,
                        const QString &subject,
                        const QString &courseNum,
                        const QString &days)
{
    QStringList crns = {crn}; // Convert single CRN to list for API
    QVector<CourseSection> results = Database::getCourseData(crns, "", "", days, term, "", 0, "", subject, courseNum);

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
        model->setItem(i, 4, new QStandardItem(cs.sectionNum));
        model->setItem(i, 5, new QStandardItem(cs.subject));
        model->setItem(i, 6, new QStandardItem(cs.courseNum));
        model->setItem(i, 7, new QStandardItem(cs.room));
        model->setItem(i, 8, new QStandardItem(cs.courseTitle));
        model->setItem(i, 9, new QStandardItem(cs.professorName));
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
        model->setItem(i, 4, new QStandardItem(cs.sectionNum));
        model->setItem(i, 5, new QStandardItem(cs.subject));
        model->setItem(i, 6, new QStandardItem(cs.courseNum));
        model->setItem(i, 8, new QStandardItem(cs.room));
        model->setItem(i, 9, new QStandardItem(cs.courseTitle));
        model->setItem(i,10, new QStandardItem(cs.professorName));
    }

    emit searchResultsReady(model);
}



QList<Room> User::getRooms()
{
    QJsonArray data = Database::getRoomData();
    QList<Room> results;

    for(int i = 0; i < data.size(); ++i)
    {
        QJsonObject roomObj = data.at(i).toObject();

        Room room;
        room.roomID = Database::jsonValueToString(roomObj["id"]);
        room.building = Database::jsonValueToString(roomObj["building"]);
        room.room = Database::jsonValueToString(roomObj["room"]).toInt();
        room.capacity = Database::jsonValueToString(roomObj["capacity"]).toInt();

        results.append(room);
    }

    return results;
}

QList<Course> User::getCourses()
{
    QJsonArray data = Database::getCourseNameData();

    QList<Course> results;

    for (int i = 0; i < data.size(); ++i)
    {
        QJsonObject courseObj = data.at(i).toObject();

        Course course;
        course.courseID = Database::jsonValueToString(courseObj["id"]);
        course.name = Database::jsonValueToString(courseObj["name"]);

        results.append(course);
    }

    return results;
}

QList<UserInfo> User::getProfessors()
{
    QJsonArray data = Database::getUserData("", "", "Professor", "");

    QList<UserInfo> results;

    for (int i = 0; i < data.size(); ++i)
    {
        QJsonObject userObj = data.at(i).toObject();

        UserInfo professor;
        professor.id = Database::jsonValueToString(userObj["id"]);
        professor.email = Database::jsonValueToString(userObj["email"]);
        professor.role = Database::jsonValueToString(userObj["role"]);
        professor.FullName = Database::jsonValueToString(userObj["name"]);

        results.append(professor);
    }

    return results;
}

void User::handleRegistration(const QString &term, const QStringList &crns)
{
    // check for duplicate registration first
    QJsonArray existing = Database::getRegistrations(this->id, crns, "");
    if (!existing.isEmpty())
    {
        qDebug() << existing;
        emit registrationComplete("Error - already registered for one or more courses submitted");
        return;
    }

    // Step 1: Fetch course data and validate CRNs
    QVector<CourseSection> courseData = Database::getCourseData(crns, "", "", "", term);
    if (courseData.length() != crns.length())
    {
        emit registrationComplete("Error: Invalid CRNs for selected term");
        return;
    }

    // Step 2: Check for scheduling conflicts (including existing registrations)
    QJsonArray existingRegs = Database::getRegistrations(this->id);
    QStringList allCrns = crns;
    for (const QJsonValue &reg : existingRegs)
        allCrns.append(Database::jsonValueToString(reg.toObject().value("CRN")));
    for (QString c : crns)
        if (!allCrns.contains(c))
            allCrns.append(c);


    // Step 3: Build registration records
    QHash<QString, int> enrollCounts = Database::getNumRegistered(crns);
    QJsonArray newReg;
    QStringList messageLines;

    for (const CourseSection &c : courseData)
    {
        QString status;
        //qDebug() << "Capacity: " << c.capacity;
        //qDebug() << "Enrolled: " << enrollCounts[c.crn];
        status = "Registered";
        messageLines.append("Course (" + c.crn + ") successfully registered");

        QJsonObject record;
        record["studentID"]     = this->id;
        record["CRN"]    = c.crn;
        record["status"] = status;
        newReg.append(record);
    }

    // Step 4: Insert into database
    for (const QJsonValue &entry : newReg)
    {
        qDebug() << entry;
        QJsonObject insertResult = Database::insert("Registration", entry.toObject());
        if (insertResult.isEmpty())
        {
            emit registrationComplete("Database error, try again later");
            return;
        }
    }

    // Step 5: Emit status message
    emit registrationComplete(messageLines.join("\n"));
}


void User::getFullWaitlistReport(const QString &term)
{
    QJsonArray waitlisted = Database::getRegistrations("", {}, "Waitlisted");

    QMap<QString, int> waitlistCounts;

    for (int i = 0; i < waitlisted.size(); ++i)
    {
        QJsonObject obj = waitlisted.at(i).toObject();
        QString crn = obj.value("CRN").toString();

        if (!crn.isEmpty())
            waitlistCounts[crn]++;
    }

    QStringList crns = waitlistCounts.keys();
    QVector<CourseSection> sections = Database::getCourseData(crns, "", "", "", term);

    QStandardItemModel *model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({
        "CRN", "Course", "Section", "Waitlist Count", "Waitlist Capacity"
    });

    //5 is the hard coded waitlist limit
    int listLim = 5;
    for (int i = 0; i < sections.size(); ++i)
    {
        const CourseSection &cs = sections.at(i);
        int countcap = waitlistCounts.value(cs.crn,0);
        if (countcap >= listLim)
        {
            QList<QStandardItem*> row;
            row.append(new QStandardItem(cs.crn));
            row.append(new QStandardItem(cs.courseTitle));
            row.append(new QStandardItem(cs.sectionNum));
            row.append(new QStandardItem(QString::number(countcap)));
            row.append(new QStandardItem(QString::number(listLim)));
            model->appendRow(row);
        }
    }

    emit fullWaitlistReportReady(model);
}

