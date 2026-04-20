#ifndef STUDENTREGISTRATIONFORM_H
#define STUDENTREGISTRATIONFORM_H

#include <QWidget>
#include <QStyleFactory>
#include <QStandardItemModel>
#include "user.h"

namespace Ui {
class StudentRegistrationForm;
}

class StudentRegistrationForm : public QWidget
{
    Q_OBJECT

/*public:
    explicit StudentRegistrationForm(User* u, QWidget *parent = nullptr);
    ~StudentRegistrationForm();*/

private slots:
    void handleRegistrationComplete(const QString &message);
    explicit StudentRegistrationForm(User* loggedIn, QWidget *parent = nullptr);
    ~StudentRegistrationForm();

private slots:
    void handleSearchResults(QStandardItemModel* model);
    void onSearchClicked();
    void onRegisterClicked();
    void onWaitlistClicked();
private:
    Ui::StudentRegistrationForm *ui;
    User* u;
};

#endif // STUDENTREGISTRATIONFORM_H
