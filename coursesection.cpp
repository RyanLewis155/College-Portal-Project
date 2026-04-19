#include "coursesection.h"


static QString getString(const QJsonObject &object, const QString &key)
{
    return object.value(key).toString();
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

    if (obj.contains("room") && obj["room"].isObject()) {
        QJsonObject r = obj["room"].toObject();
        cs.building = r.value("building").toString();
        cs.room = QString::number(r.value("room").toInt());
    }

    if(obj.contains("Course") && obj["Course"].isObject()) {
        QJsonObject c = obj["Course"].toObject();
        cs.coursename = c.value("course").toString();
    }

    if (obj.contains("User") && obj["User"].isObject()) {
        QJsonObject u = obj["User"].toObject();
        cs.instructorname = u.value("instructor").toString();
    }

    return cs;
}