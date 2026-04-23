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

    cs.crn = QString::number(obj.value("CRN").toInt());

    cs.startTime = getString(obj, "startTime");
    cs.endTime   = getString(obj, "endTime");
    cs.days      = getString(obj, "days");

    cs.sectionNum = obj.value("section").toInt();

    cs.subject   = getString(obj, "subject");
    cs.courseNum = getString(obj, "courseNum");
    cs.term      = getString(obj, "term");

    cs.level    = getString(obj, "level");

    cs.building    = getString(obj, "building");
    cs.room        = getString(obj, "room");
    cs.capacity    = getString(obj, "capacity");

    cs.coursename    = getString(obj, "course");
    cs.instructorname = getString(obj, "instructor");
    cs.level         = getString(obj, "level");

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
    QJsonObject obj;
    obj["CRN"] = cs.crn;
    obj["roomID"] = cs.buildingID;
    obj["profID"] = cs.professorID;
    obj["startTime"] = cs.startTime;
    obj["endTime"] = cs.endTime;
    obj["days"] = cs.days;
    obj["term"] = cs.term;
    obj["courseID"] = cs.courseID;
    obj["sectionNum"] = cs.sectionNum;
    if(!cs.level.isEmpty())
    {
        obj["level"] = cs.level;
    }
    obj["subject"] = cs.subject;
    obj["courseNum"] = cs.courseNum;

    return obj;
}
