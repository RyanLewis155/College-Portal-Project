#ifndef PLAN_H
#define PLAN_H

#include <QObject>

class Plan : public QObject
{
    Q_OBJECT
public:
    //attributes
    QString id;
    QString planName;

    explicit Plan(QObject *parent = nullptr);

signals:
};

#endif // PLAN_H
