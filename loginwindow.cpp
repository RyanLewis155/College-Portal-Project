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
