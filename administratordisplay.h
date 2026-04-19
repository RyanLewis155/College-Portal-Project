#ifndef ADMINISTRATORDISPLAY_H
#define ADMINISTRATORDISPLAY_H

#include <QWidget>
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

private slots:
    void handleConflictReports(QStandardItemModel* model);

};

#endif // ADMINISTRATORDISPLAY_H
