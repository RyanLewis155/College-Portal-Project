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

private slots:
    void handleSearchResults(QStandardItemModel* model);
    void handleConflictReports(QStandardItemModel* model);

private:
    Ui::AdministratorDisplay *ui;
    User *u;
    void saveConflictReportToTxt(QStandardItemModel* model);

};

#endif // ADMINISTRATORDISPLAY_H
