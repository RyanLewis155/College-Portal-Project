#ifndef VIEWPLANFORM_H
#define VIEWPLANFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonObject>
#include "database.h"
#include "user.h"
#include "plan.h"

struct PlanItem {
    QString planID;
    QString crn;
};

namespace Ui {
class ViewPlanForm;
}

class ViewPlanForm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewPlanForm(User* loggedIn, QWidget *parent = nullptr);
    ~ViewPlanForm();

    QString enterNewPlan(const QString &studentID, const QString &planName);
    QJsonObject enterPlanItem(const QString &planID, const QString &crn);

private slots:
    void on_pushButton_AddPlan_clicked();

    void on_pushButton_AddPlanItem_clicked();

private:
    Ui::ViewPlanForm *ui;
    User* u;
};

#endif // VIEWPLANFORM_H
