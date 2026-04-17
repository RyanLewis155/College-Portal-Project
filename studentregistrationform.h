#ifndef STUDENTREGISTRATIONFORM_H
#define STUDENTREGISTRATIONFORM_H

#include <QWidget>
#include <QStyleFactory>

namespace Ui {
class StudentRegistrationForm;
}

class StudentRegistrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentRegistrationForm(QWidget *parent = nullptr);
    ~StudentRegistrationForm();

private:
    Ui::StudentRegistrationForm *ui;
};

#endif // STUDENTREGISTRATIONFORM_H
