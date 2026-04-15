#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QGraphicsDropShadowEffect>




LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    ui->formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);

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
    applyDropShadow(ui->lineEdit_ForgotPass);
    applyDropShadow(ui->pushButton_ForgotSubmit);
    applyDropShadow(ui->pushButton_ForgotCancel);
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

void LoginWindow::on_pushButton_Registration_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Registration);
}


void LoginWindow::on_pushButton_GoToLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Login);
}


void LoginWindow::on_pushButton_ForgotPassword_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_ForgotPassword);
}


void LoginWindow::on_pushButton_ForgotSubmit_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_Login);
}


void LoginWindow::on_pushButton_Login_clicked()
{
    if(true)
    {
        loginSuccessful();
    }
}

