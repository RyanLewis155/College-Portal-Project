#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QGraphicsDropShadowEffect>
#include "queryparams.h"
#include <QCryptographicHash>
#include "database.h"
#include <QPasswordDigestor>
#include <QRandomGenerator>
#include <QMessageBox>




LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    ui->formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);


    m_validRegistration.email = false;
    m_validRegistration.firstName = false;
    m_validRegistration.lastName = false;
    m_validRegistration.password = false;
    m_validRegistration.passwordmatch = false;
    ui->label_FirstNameError->setText("");
    ui->label_LastNameError->setText("");
    ui->label_InvalidEmail->setText("");
    ui->label_PasswordError->setText("");
    ui->label_PasswordMatchError->setText("");

    connect(ui->lineEdit_FirstName, &QLineEdit::textChanged,
            this, &LoginWindow::validateNameField);
    connect(ui->lineEdit_LastName, &QLineEdit::textChanged,
            this, &LoginWindow::validateNameField);
    connect(ui->lineEdit_RegEmail, &QLineEdit::textChanged,
            this, &LoginWindow::validateEmailField);
    connect(ui->lineEdit_RegPassword, &QLineEdit::textChanged,
            this, &LoginWindow::validatePasswordField);
    connect(ui->lineEdit_RegRePassword, &QLineEdit::textChanged,
            this, &LoginWindow::validatePasswordMatchField);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(10);
    shadow->setOffset(0, 2);
    shadow->setColor(QColor(0, 0, 0, 160));



    applyDropShadow(ui->lineEdit_Email);
    applyDropShadow(ui->lineEdit_Password);
    applyDropShadow(ui->pushButton_Login);
    applyDropShadow(ui->lineEdit_RegPassword);
    applyDropShadow(ui->lineEdit_RegEmail);
    applyDropShadow(ui->lineEdit_RegRePassword);
    applyDropShadow(ui->lineEdit_FirstName);
    applyDropShadow(ui->lineEdit_LastName);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::applyDropShadow(QWidget *widget) {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(15);
    shadow->setOffset(0, 2);
    shadow->setColor(QColor(0, 0, 0, 160));
    widget->setGraphicsEffect(shadow);
}

void LoginWindow::setFieldValid(QLineEdit *field, bool valid)
{
    field->setProperty("invalid", !valid);
    field->style()->unpolish(field);
    field->style()->polish(field);
}

void LoginWindow::on_pushButton_Registration_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Registration);
}


void LoginWindow::on_pushButton_GoToLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Login);
}

void LoginWindow::on_pushButton_Login_clicked()
{
    bool validEmail = validateEmail(ui->lineEdit_Email->text());
    bool validPassword = validatePassword(ui->lineEdit_Password->text());

    if(validEmail && validPassword)
    {

    }
}


void LoginWindow::on_pushButton_Register_clicked()
{
    if(!canRegister())
        return;

    UserInfo registrationInfo;

    registrationInfo.FullName = ui->lineEdit_FirstName->text() + " " + ui->lineEdit_LastName->text();
    registrationInfo.email = ui->lineEdit_RegEmail->text();
    registrationInfo.password = ui->lineEdit_RegPassword->text();
    registrationInfo.role = ui->comboBox_RoleSelection->currentText();
    bool registrationSuccess = RegisterAccount(registrationInfo);
    if (registrationSuccess) {
        QMessageBox::information(this, "Success", "Account created!");
        ui->lineEdit_FirstName->clear();
        ui->lineEdit_LastName->clear();
        ui->lineEdit_RegEmail->clear();
        ui->lineEdit_RegPassword->clear();
    } else {
        QMessageBox::warning(this, "Error", "Registration failed.");
    }
}

bool LoginWindow::RegisterAccount(const UserInfo &userInfo)
{

    QJsonObject registrationInfo;
    registrationInfo["email"] = userInfo.email;
    registrationInfo["passwordHash"] = QString(QCryptographicHash::hash(userInfo.password.toUtf8(), QCryptographicHash::Sha256).toHex());
    registrationInfo["name"] = userInfo.FullName;
    registrationInfo["role"] = userInfo.role;

    QJsonObject result = Database::insert("User", registrationInfo);

    return !result.isEmpty();
}

QString LoginWindow::hashPassword(const QString &password)
{
    QByteArray salt = QByteArray::number(QRandomGenerator::global()->generate64());

    QByteArray hash = QPasswordDigestor::deriveKeyPbkdf2(
        QCryptographicHash::Sha256,
        password.toUtf8(),
        salt,
        100000,   // iterations (adjust as needed)
        32        // key length
        );

    // Store BOTH salt + hash (important!)
    return salt.toHex() + ":" + hash.toHex();
}

void LoginWindow::validateEmailField(const QString &text)
{
    bool valid = validateEmail(text);

    setFieldValid(ui->lineEdit_RegEmail, valid);

    ui->label_InvalidEmail->setText(valid ? "" : "Invalid email");
    m_validRegistration.email = valid;
}

void LoginWindow::validateNameField(const QString &text)
{
    bool validFirst = validateName(ui->lineEdit_FirstName->text());
    bool validLast = validateName(ui->lineEdit_LastName->text());

    setFieldValid(ui->lineEdit_FirstName, validFirst);
    setFieldValid(ui->lineEdit_LastName, validLast);

    ui->label_FirstNameError->setText(validFirst ? "" : "Invalid First Name");
    ui->label_LastNameError->setText(validLast ? "" : "Invalid Last Name");

    m_validRegistration.firstName = validFirst;
    m_validRegistration.lastName = validLast;
}

void LoginWindow::validatePasswordField(const QString &text)
{
    bool valid = validatePassword(text);

    setFieldValid(ui->lineEdit_RegPassword, valid);

    ui->label_PasswordError->setText(valid ? "" : "Invalid Password");
    m_validRegistration.password = valid;
}

void LoginWindow::validatePasswordMatchField(const QString &text)
{
    bool valid = validatePasswordMatch(text, ui->lineEdit_RegPassword->text());

    setFieldValid(ui->lineEdit_RegPassword, valid);

    ui->label_PasswordMatchError->setText(valid ? "" : "Password's Do Not Match");
    m_validRegistration.passwordmatch = valid;
}

void LoginWindow::handleLoginReqest(const QString &email, const QString &password)
{

}

bool LoginWindow::canRegister()
{
    return (m_validRegistration.email && m_validRegistration.firstName && m_validRegistration.lastName && m_validRegistration.password && m_validRegistration.passwordmatch);
}

bool LoginWindow::validateEmail(const QString &Email)
{
    QString trimmed = Email.trimmed();

    static const QRegularExpression regex(
        R"((^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$))"
        );

    return regex.match(trimmed).hasMatch();
}

bool LoginWindow::validateName(const QString &Name)
{
    QString trimmed = Name.trimmed();

    if (trimmed.isEmpty())
        return false;

    static const QRegularExpression regex(
        R"(^[A-Za-zÀ-ÖØ-öø-ÿ' -]+$)"
        );

    return regex.match(trimmed).hasMatch();
}

bool LoginWindow::validatePassword(const QString &password)
{
    // At least 8 chars, 1 uppercase, 1 lowercase, 1 digit, 1 special char
    static const QRegularExpression regex(
        R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[^A-Za-z\d]).{8,}$)"
        );

    return regex.match(password).hasMatch();
}

bool LoginWindow::validatePasswordMatch(const QString &password1, const QString &password2)
{
    return password1 == password2;
}
