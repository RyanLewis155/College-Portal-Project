#include "plan.h"

Plan::Plan(QString id, QString planName, QObject *parent)
    : QObject{parent}
{
    this->id = id;
    this->planName = planName;
}
