#ifndef VIEWPLANFORM_H
#define VIEWPLANFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonObject>
#include "database.h"

namespace Ui {
class ViewPlanForm;
}

class ViewPlanForm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewPlanForm(QWidget *parent = nullptr);
    ~ViewPlanForm();

private slots:
    void on_pushButton_AddPlan_clicked();

private:
    Ui::ViewPlanForm *ui;
};

#endif // VIEWPLANFORM_H
