#ifndef VIEWPLANFORM_H
#define VIEWPLANFORM_H

#include <QWidget>

namespace Ui {
class ViewPlanForm;
}

class ViewPlanForm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewPlanForm(QWidget *parent = nullptr);
    ~ViewPlanForm();

private:
    Ui::ViewPlanForm *ui;
};

#endif // VIEWPLANFORM_H
