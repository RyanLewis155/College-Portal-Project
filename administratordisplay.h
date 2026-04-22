#ifndef ADMINISTRATORDISPLAY_H
#define ADMINISTRATORDISPLAY_H

#include <QWidget>
#include <QStandardItemModel>
#include "user.h"

namespace Ui {
class AdministratorDisplay;
}

class AdministratorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit AdministratorDisplay(User* loggedIn, QWidget *parent = nullptr);
    ~AdministratorDisplay();

private:
    Ui::AdministratorDisplay *ui;
    User *u;

    void clearModificationUI();
private slots:
    void handleConflictReports(QStandardItemModel* model);
    void handleSearchResults(QStandardItemModel* model);
    void handleSingleCourseSearch(CourseSection cs);

    void on_pushButton_Save_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // ADMINISTRATORDISPLAY_H
