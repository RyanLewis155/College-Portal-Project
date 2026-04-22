#ifndef VIEWPLANFORM_H
#define VIEWPLANFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonObject>
#include "user.h"
#include <QListWidget>

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
    void loadPlanItems(const QString &planID);

private slots:
    void on_pushButton_AddPlan_clicked();

    void on_pushButton_AddPlanItem_clicked();

    void on_listWidget_PlanList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::ViewPlanForm *ui;
    User* u;
};

#endif // VIEWPLANFORM_H
