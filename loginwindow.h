#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void applyDropShadow(QWidget *widget);

private slots:
    void on_pushButton_Registration_clicked();

    void on_pushButton_GoToLogin_clicked();

    void on_pushButton_ForgotPassword_clicked();

    void on_pushButton_ForgotSubmit_clicked();

    void on_pushButton_Login_clicked();

signals:
    void loginSuccessful();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
