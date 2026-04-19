#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QLineEdit>

namespace Ui {
class LoginWindow;
}

struct ValidationState {
    bool email = false;
    bool password = false;
    bool passwordmatch = false;
    bool firstName = false;
    bool lastName = false;
};

struct UserInfo {
    QString email;
    QString password;
    QString FullName;
    QString role;
};

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

    void on_pushButton_Login_clicked();

    void on_pushButton_Register_clicked();

    void validateEmailField(const QString &text);

    void validateNameField(const QString &text);

    void validatePasswordField(const QString &text);

    void validatePasswordMatchField(const QString &text);

    void handleLoginReqest(const QString &email, const QString &password);

signals:
    void loginSuccessful();

    void requestLogin(const QString &email, const QString &password);



private:
    Ui::LoginWindow *ui;
    ValidationState m_validRegistration;

    bool canRegister();
    bool validateEmail(const QString& Email);
    bool validateName(const QString &Name);
    bool validatePassword(const QString &password);
    bool validatePasswordMatch(const QString &password1, const QString &password2);
    void setFieldValid(QLineEdit *field, bool valid);
    bool RegisterAccount(const UserInfo &userInfo);
    QString hashPassword(const QString &password);

};

#endif // LOGINWINDOW_H
