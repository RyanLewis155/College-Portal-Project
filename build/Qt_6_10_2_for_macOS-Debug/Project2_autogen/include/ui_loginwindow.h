/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_Email;
    QLineEdit *lineEdit_Email;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_ForgotPassword;
    QPushButton *pushButton_Register;
    QPushButton *pushButton_Login;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        LoginWindow->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        LoginWindow->setAutoFillBackground(false);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: #006747"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(364, 389));
        frame->setMaximumSize(QSize(364, 389));
        frame->setBaseSize(QSize(364, 389));
        frame->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        widget = new QWidget(frame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(15, 15, 331, 361));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(15, 15, 15, 15);
        label_Email = new QLabel(widget);
        label_Email->setObjectName("label_Email");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Email->sizePolicy().hasHeightForWidth());
        label_Email->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(16);
        label_Email->setFont(font);
        label_Email->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));
        label_Email->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_Email->setIndent(0);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_Email);

        lineEdit_Email = new QLineEdit(widget);
        lineEdit_Email->setObjectName("lineEdit_Email");
        lineEdit_Email->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        lineEdit_Email->setFont(font1);
        lineEdit_Email->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        lineEdit_Email->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 0px solid gray;\n"
"border-radius: 8px;"));
        lineEdit_Email->setEchoMode(QLineEdit::EchoMode::Normal);
        lineEdit_Email->setCursorPosition(0);
        lineEdit_Email->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_Email);

        label_Password = new QLabel(widget);
        label_Password->setObjectName("label_Password");
        label_Password->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_Password->sizePolicy().hasHeightForWidth());
        label_Password->setSizePolicy(sizePolicy2);
        label_Password->setMinimumSize(QSize(0, 40));
        label_Password->setBaseSize(QSize(0, 40));
        label_Password->setFont(font);
        label_Password->setStyleSheet(QString::fromUtf8("color: black;"));
        label_Password->setScaledContents(true);
        label_Password->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_Password);

        lineEdit_Password = new QLineEdit(widget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_Password->sizePolicy().hasHeightForWidth());
        lineEdit_Password->setSizePolicy(sizePolicy3);
        lineEdit_Password->setMinimumSize(QSize(0, 40));
        lineEdit_Password->setFont(font1);
        lineEdit_Password->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        lineEdit_Password->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 0px solid gray;\n"
"border-radius: 8px;"));
        lineEdit_Password->setFrame(true);
        lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit_Password->setCursorPosition(0);
        lineEdit_Password->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_Password);

        pushButton_ForgotPassword = new QPushButton(widget);
        pushButton_ForgotPassword->setObjectName("pushButton_ForgotPassword");
        sizePolicy2.setHeightForWidth(pushButton_ForgotPassword->sizePolicy().hasHeightForWidth());
        pushButton_ForgotPassword->setSizePolicy(sizePolicy2);
        pushButton_ForgotPassword->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_ForgotPassword->setAutoFillBackground(false);
        pushButton_ForgotPassword->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: #D9D9D9;\n"
"border-radius: 8px;\n"
"text-align: left;"));

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, pushButton_ForgotPassword);

        pushButton_Register = new QPushButton(widget);
        pushButton_Register->setObjectName("pushButton_Register");
        sizePolicy2.setHeightForWidth(pushButton_Register->sizePolicy().hasHeightForWidth());
        pushButton_Register->setSizePolicy(sizePolicy2);
        pushButton_Register->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_Register->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: #D9D9D9;\n"
"border-radius: 8px;\n"
"text-align: left;"));

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, pushButton_Register);

        pushButton_Login = new QPushButton(widget);
        pushButton_Login->setObjectName("pushButton_Login");
        sizePolicy3.setHeightForWidth(pushButton_Login->sizePolicy().hasHeightForWidth());
        pushButton_Login->setSizePolicy(sizePolicy3);
        pushButton_Login->setMinimumSize(QSize(0, 40));
        pushButton_Login->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_Login->setAutoFillBackground(false);
        pushButton_Login->setStyleSheet(QString::fromUtf8("background-color: #2C2C2C;\n"
"color: white;\n"
"border-radius: 8px;"));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, pushButton_Login);


        horizontalLayout->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        label_Email->setText(QCoreApplication::translate("LoginWindow", "Email:", nullptr));
        lineEdit_Email->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Email...", nullptr));
        label_Password->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password...", nullptr));
        pushButton_ForgotPassword->setText(QCoreApplication::translate("LoginWindow", "Forgot your Password? Click Here.", nullptr));
        pushButton_Register->setText(QCoreApplication::translate("LoginWindow", "Dont have an account? Register Here.", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
