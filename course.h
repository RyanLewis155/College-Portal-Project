#ifndef COURSE_H
#define COURSE_H

#include <QObject>
#include "section.h"

class Course : public QObject
{
    Q_OBJECT
public:
    explicit Course(QObject *parent = nullptr) : QObject(parent) {};

explicit Course(const QString& courseID, const QString& name, const QList<Section*> sections) :
                    courseID(courseID), name(name), sections(sections) {};

private:
    QString courseID;
    QString name;
    QList<Section*> sections;

};

#endif // COURSE_H
