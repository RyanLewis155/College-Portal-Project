#ifndef STUDENTREGISTRATIONFORM_H
#define STUDENTREGISTRATIONFORM_H

#include <QWidget>
#include <QStyleFactory>
#include "user.h"

namespace Ui {
class StudentRegistrationForm;
}

class StudentRegistrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentRegistrationForm(User* u, QWidget *parent = nullptr);
    ~StudentRegistrationForm();

private slots:
    void handleRegistrationComplete(const QString &message);

private:
    Ui::StudentRegistrationForm *ui;
    User* u;
};

#endif // STUDENTREGISTRATIONFORM_H
