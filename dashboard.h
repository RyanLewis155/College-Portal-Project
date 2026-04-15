#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "studentdisplay.h"
#include <QMainWindow>

namespace Ui {
class DashBoard;
}

class DashBoard : public QMainWindow
{
    Q_OBJECT

public:
    enum class Role {
        Student,
        Professor,
        Administrator,
        BoardMember
    };


    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();

    void setDisplay(QWidget *displayWidget);




private:
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
