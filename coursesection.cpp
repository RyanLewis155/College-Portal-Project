#include "coursesection.h"
#include "database.h"


static QString getString(const QJsonObject &object, const QString &key)
{
    // return object.value(key).toString();
    return Database::jsonValueToString(object.value(key));
}

static int getInt(const QJsonObject &object, const QString &key)
{
    return object.value(key).toInt();
}

CourseSection fromJson(const QJsonObject &obj)
{
    CourseSection cs;

    cs.crn = obj["crn"].toString();
    QString meeting_times = obj["meeting_times"].toString();

    if (!meeting_times.isEmpty()){
        QStringList split_times = meeting_times.split(" - ");
        cs.startTime = split_times[0];
        cs.endTime = split_times[1];
    } else {
        cs.startTime = "TBD";
        cs.endTime = "TBD";
    }

    cs.days      = getString(obj, "meeting_days");
    cs.level         = getString(obj, "crse_level");
    cs.sectionNum = obj["section_number"].toString();

    QJsonObject course = obj["Course"].toObject();
    cs.subject   = course["subj"].toString();
    cs.courseNum = course["number"].toString();
    cs.courseTitle = course["title"].toString();

    QJsonObject room = obj["Room"].toObject();
    cs.room    = room["name"].toString();

    QJsonObject professor = obj["Prof"].toObject();
    cs.professorName = professor["name"].toString();


    // if (obj.contains("room") && obj["room"].isObject()) {
    //     QJsonObject r = obj["room"].toObject();
    //     cs.building = r.value("building").toString();
    //     cs.room = QString::number(r.value("room").toInt());
    //     cs.capacity = QString::number(r.value("capacity").toInt());
    // }

    // if(obj.contains("Course") && obj["Course"].isObject()) {
    //     QJsonObject c = obj["Course"].toObject();
    //     cs.coursename = c.value("course").toString();
    // }

    // if (obj.contains("User") && obj["User"].isObject()) {
    //     QJsonObject u = obj["User"].toObject();
    //     cs.instructorname = u.value("instructor").toString();
    // }

    return cs;
}
QJsonObject toJson(const CourseSection &cs)
{
    QJsonObject course;
    course["subj"] = cs.subject;
    course["number"] = cs.courseNum;
    course["title"] = cs.courseTitle;

    QJsonObject room;
    room["name"] = cs.room;

    QJsonObject prof;
    prof["name"] = cs.professorName;
    prof["email"] = cs.professorEmail;

    QJsonObject section;
    section["Course"] = course;
    section["Prof"] = prof;
    section["Room"] = room;
    section["crn"] = cs.crn;
    QString combined_times = cs.startTime + " - " + cs.endTime;
    section["meeting_times"] = combined_times;

    section["meeting_days"] = cs.days;
    section["term"] = cs.term;
    if(!cs.level.isEmpty())
    {
        section["crse_level"] = cs.level;
    }

    return section;
}
