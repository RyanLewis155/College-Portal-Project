#ifndef DASHBOARD_H
#define DASHBOARD_H

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
    explicit DashBoard(Role role, QWidget *parent = nullptr);
    ~DashBoard();




private:
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
