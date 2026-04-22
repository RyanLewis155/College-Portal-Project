/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page_Login;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QFrame *frame_Login;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_Email;
    QLineEdit *lineEdit_Email;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_ForgotPassword;
    QPushButton *pushButton_Registration;
    QPushButton *pushButton_Login;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_ForgotPassword;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_5;
    QFrame *frame_ForgotPassword;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_ForgotPass;
    QLineEdit *lineEdit_ForgotPass;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_ForgotSubmit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_ForgotCancel;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_Registration;
    QGridLayout *gridLayout_2;
    QFrame *frame_Registration;
    QFrame *frame;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_FirstName;
    QLineEdit *lineEdit_FirstName;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_LastName;
    QLineEdit *lineEdit_LastName;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_RegEmail;
    QLineEdit *lineEdit_RegEmail;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_RegPassword;
    QLineEdit *lineEdit_RegPassword;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_RegRePassword;
    QLineEdit *lineEdit_RegRePassword;
    QPushButton *pushButton_Register;
    QPushButton *pushButton_GoToLogin;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 639);
        LoginWindow->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        LoginWindow->setAutoFillBackground(false);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: #006747"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page_Login = new QWidget();
        page_Login->setObjectName("page_Login");
        gridLayout = new QGridLayout(page_Login);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        frame_Login = new QFrame(page_Login);
        frame_Login->setObjectName("frame_Login");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_Login->sizePolicy().hasHeightForWidth());
        frame_Login->setSizePolicy(sizePolicy1);
        frame_Login->setMinimumSize(QSize(525, 364));
        frame_Login->setMaximumSize(QSize(525, 364));
        frame_Login->setBaseSize(QSize(525, 364));
        frame_Login->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px;"));
        frame_Login->setFrameShape(QFrame::Shape::StyledPanel);
        frame_Login->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget = new QWidget(frame_Login);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 501, 341));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(15, 15, 15, 15);
        label_Email = new QLabel(layoutWidget);
        label_Email->setObjectName("label_Email");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_Email->sizePolicy().hasHeightForWidth());
        label_Email->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(16);
        label_Email->setFont(font);
        label_Email->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));
        label_Email->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_Email->setIndent(0);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_Email);

        lineEdit_Email = new QLineEdit(layoutWidget);
        lineEdit_Email->setObjectName("lineEdit_Email");
        lineEdit_Email->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        lineEdit_Email->setFont(font1);
        lineEdit_Email->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        lineEdit_Email->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 0px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"padding-left: 10px;"));
        lineEdit_Email->setEchoMode(QLineEdit::EchoMode::Normal);
        lineEdit_Email->setCursorPosition(0);
        lineEdit_Email->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_Email);

        label_Password = new QLabel(layoutWidget);
        label_Password->setObjectName("label_Password");
        label_Password->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_Password->sizePolicy().hasHeightForWidth());
        label_Password->setSizePolicy(sizePolicy3);
        label_Password->setMinimumSize(QSize(0, 40));
        label_Password->setBaseSize(QSize(0, 40));
        label_Password->setFont(font);
        label_Password->setStyleSheet(QString::fromUtf8("color: black;"));
        label_Password->setScaledContents(true);
        label_Password->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_Password);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_Password->sizePolicy().hasHeightForWidth());
        lineEdit_Password->setSizePolicy(sizePolicy4);
        lineEdit_Password->setMinimumSize(QSize(0, 40));
        lineEdit_Password->setFont(font1);
        lineEdit_Password->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        lineEdit_Password->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 0px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"padding-left: 10px;"));
        lineEdit_Password->setFrame(true);
        lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit_Password->setCursorPosition(0);
        lineEdit_Password->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_Password);

        pushButton_ForgotPassword = new QPushButton(layoutWidget);
        pushButton_ForgotPassword->setObjectName("pushButton_ForgotPassword");
        sizePolicy3.setHeightForWidth(pushButton_ForgotPassword->sizePolicy().hasHeightForWidth());
        pushButton_ForgotPassword->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(14);
        pushButton_ForgotPassword->setFont(font2);
        pushButton_ForgotPassword->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_ForgotPassword->setAutoFillBackground(false);
        pushButton_ForgotPassword->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: #D9D9D9;\n"
"border-radius: 8px;\n"
"text-align: left;"));

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, pushButton_ForgotPassword);

        pushButton_Registration = new QPushButton(layoutWidget);
        pushButton_Registration->setObjectName("pushButton_Registration");
        sizePolicy3.setHeightForWidth(pushButton_Registration->sizePolicy().hasHeightForWidth());
        pushButton_Registration->setSizePolicy(sizePolicy3);
        pushButton_Registration->setFont(font2);
        pushButton_Registration->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_Registration->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: #D9D9D9;\n"
"border-radius: 8px;\n"
"text-align: left;"));

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, pushButton_Registration);

        pushButton_Login = new QPushButton(layoutWidget);
        pushButton_Login->setObjectName("pushButton_Login");
        sizePolicy4.setHeightForWidth(pushButton_Login->sizePolicy().hasHeightForWidth());
        pushButton_Login->setSizePolicy(sizePolicy4);
        pushButton_Login->setMinimumSize(QSize(0, 40));
        pushButton_Login->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_Login->setAutoFillBackground(false);
        pushButton_Login->setStyleSheet(QString::fromUtf8("background-color: #2C2C2C;\n"
"color: white;\n"
"border-radius: 8px;"));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, pushButton_Login);


        gridLayout->addWidget(frame_Login, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_Login);
        page_ForgotPassword = new QWidget();
        page_ForgotPassword->setObjectName("page_ForgotPassword");
        gridLayout_3 = new QGridLayout(page_ForgotPassword);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer_5 = new QSpacerItem(20, 202, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 0, 0, 1, 1);

        frame_ForgotPassword = new QFrame(page_ForgotPassword);
        frame_ForgotPassword->setObjectName("frame_ForgotPassword");
        sizePolicy1.setHeightForWidth(frame_ForgotPassword->sizePolicy().hasHeightForWidth());
        frame_ForgotPassword->setSizePolicy(sizePolicy1);
        frame_ForgotPassword->setMinimumSize(QSize(505, 182));
        frame_ForgotPassword->setMaximumSize(QSize(505, 182));
        frame_ForgotPassword->setBaseSize(QSize(505, 182));
        frame_ForgotPassword->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px;"));
        verticalLayout_8 = new QVBoxLayout(frame_ForgotPassword);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(15, 15, 15, 15);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_ForgotPass = new QLabel(frame_ForgotPassword);
        label_ForgotPass->setObjectName("label_ForgotPass");
        sizePolicy2.setHeightForWidth(label_ForgotPass->sizePolicy().hasHeightForWidth());
        label_ForgotPass->setSizePolicy(sizePolicy2);
        label_ForgotPass->setFont(font);
        label_ForgotPass->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));

        verticalLayout_7->addWidget(label_ForgotPass);

        lineEdit_ForgotPass = new QLineEdit(frame_ForgotPassword);
        lineEdit_ForgotPass->setObjectName("lineEdit_ForgotPass");
        lineEdit_ForgotPass->setMinimumSize(QSize(0, 40));
        lineEdit_ForgotPass->setMaximumSize(QSize(16777215, 40));
        lineEdit_ForgotPass->setBaseSize(QSize(0, 40));
        lineEdit_ForgotPass->setFont(font1);
        lineEdit_ForgotPass->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 0px solid gray;\n"
"border-radius: 8px;\n"
"color: black;\n"
"padding-left: 10px;"));

        verticalLayout_7->addWidget(lineEdit_ForgotPass);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(15, 15, 15, 15);
        pushButton_ForgotSubmit = new QPushButton(frame_ForgotPassword);
        pushButton_ForgotSubmit->setObjectName("pushButton_ForgotSubmit");
        sizePolicy4.setHeightForWidth(pushButton_ForgotSubmit->sizePolicy().hasHeightForWidth());
        pushButton_ForgotSubmit->setSizePolicy(sizePolicy4);
        pushButton_ForgotSubmit->setMinimumSize(QSize(0, 40));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Verdana")});
        font3.setPointSize(14);
        pushButton_ForgotSubmit->setFont(font3);
        pushButton_ForgotSubmit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_ForgotSubmit->setAutoFillBackground(false);
        pushButton_ForgotSubmit->setStyleSheet(QString::fromUtf8("background-color: #2C2C2C;\n"
"color: white;\n"
"border-radius: 8px;"));

        horizontalLayout_3->addWidget(pushButton_ForgotSubmit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_ForgotCancel = new QPushButton(frame_ForgotPassword);
        pushButton_ForgotCancel->setObjectName("pushButton_ForgotCancel");
        sizePolicy4.setHeightForWidth(pushButton_ForgotCancel->sizePolicy().hasHeightForWidth());
        pushButton_ForgotCancel->setSizePolicy(sizePolicy4);
        pushButton_ForgotCancel->setMinimumSize(QSize(0, 40));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Verdana")});
        font4.setPointSize(14);
        font4.setKerning(true);
        pushButton_ForgotCancel->setFont(font4);
        pushButton_ForgotCancel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_ForgotCancel->setAutoFillBackground(false);
        pushButton_ForgotCancel->setStyleSheet(QString::fromUtf8("background-color: #006747;\n"
"color: white;\n"
"border-radius: 8px;"));

        horizontalLayout_3->addWidget(pushButton_ForgotCancel);


        verticalLayout_8->addLayout(horizontalLayout_3);


        gridLayout_3->addWidget(frame_ForgotPassword, 1, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 201, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 2, 0, 1, 1);

        stackedWidget->addWidget(page_ForgotPassword);
        page_Registration = new QWidget();
        page_Registration->setObjectName("page_Registration");
        gridLayout_2 = new QGridLayout(page_Registration);
        gridLayout_2->setObjectName("gridLayout_2");
        frame_Registration = new QFrame(page_Registration);
        frame_Registration->setObjectName("frame_Registration");
        sizePolicy1.setHeightForWidth(frame_Registration->sizePolicy().hasHeightForWidth());
        frame_Registration->setSizePolicy(sizePolicy1);
        frame_Registration->setMinimumSize(QSize(525, 508));
        frame_Registration->setMaximumSize(QSize(525, 508));
        frame_Registration->setBaseSize(QSize(525, 530));
        frame_Registration->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 8px;"));
        frame_Registration->setFrameShape(QFrame::Shape::StyledPanel);
        frame_Registration->setFrameShadow(QFrame::Shadow::Raised);
        frame = new QFrame(frame_Registration);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 10, 477, 491));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(frame);
        verticalLayout_6->setSpacing(15);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(15, 15, 15, 15);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(50);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        label_FirstName = new QLabel(frame);
        label_FirstName->setObjectName("label_FirstName");
        sizePolicy2.setHeightForWidth(label_FirstName->sizePolicy().hasHeightForWidth());
        label_FirstName->setSizePolicy(sizePolicy2);
        label_FirstName->setFont(font);
        label_FirstName->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));

        verticalLayout->addWidget(label_FirstName);

        lineEdit_FirstName = new QLineEdit(frame);
        lineEdit_FirstName->setObjectName("lineEdit_FirstName");
        lineEdit_FirstName->setMinimumSize(QSize(0, 40));
        lineEdit_FirstName->setMaximumSize(QSize(16777215, 40));
        lineEdit_FirstName->setBaseSize(QSize(0, 40));
        lineEdit_FirstName->setFont(font1);
        lineEdit_FirstName->setStyleSheet(QString::fromUtf8("color: black;\n"
"padding-left: 10px;"));

        verticalLayout->addWidget(lineEdit_FirstName);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_LastName = new QLabel(frame);
        label_LastName->setObjectName("label_LastName");
        sizePolicy2.setHeightForWidth(label_LastName->sizePolicy().hasHeightForWidth());
        label_LastName->setSizePolicy(sizePolicy2);
        label_LastName->setFont(font);
        label_LastName->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));

        verticalLayout_2->addWidget(label_LastName);

        lineEdit_LastName = new QLineEdit(frame);
        lineEdit_LastName->setObjectName("lineEdit_LastName");
        lineEdit_LastName->setMinimumSize(QSize(0, 40));
        lineEdit_LastName->setMaximumSize(QSize(16777215, 40));
        lineEdit_LastName->setBaseSize(QSize(0, 40));
        lineEdit_LastName->setFont(font1);
        lineEdit_LastName->setStyleSheet(QString::fromUtf8("color: black;\n"
"padding-left: 10px;"));

        verticalLayout_2->addWidget(lineEdit_LastName);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_RegEmail = new QLabel(frame);
        label_RegEmail->setObjectName("label_RegEmail");
        sizePolicy2.setHeightForWidth(label_RegEmail->sizePolicy().hasHeightForWidth());
        label_RegEmail->setSizePolicy(sizePolicy2);
        label_RegEmail->setFont(font);
        label_RegEmail->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));

        verticalLayout_3->addWidget(label_RegEmail);

        lineEdit_RegEmail = new QLineEdit(frame);
        lineEdit_RegEmail->setObjectName("lineEdit_RegEmail");
        lineEdit_RegEmail->setMinimumSize(QSize(0, 40));
        lineEdit_RegEmail->setMaximumSize(QSize(16777215, 40));
        lineEdit_RegEmail->setBaseSize(QSize(0, 40));
        lineEdit_RegEmail->setFont(font1);
        lineEdit_RegEmail->setStyleSheet(QString::fromUtf8("color: black;\n"
"padding-left: 10px;"));

        verticalLayout_3->addWidget(lineEdit_RegEmail);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_RegPassword = new QLabel(frame);
        label_RegPassword->setObjectName("label_RegPassword");
        sizePolicy2.setHeightForWidth(label_RegPassword->sizePolicy().hasHeightForWidth());
        label_RegPassword->setSizePolicy(sizePolicy2);
        label_RegPassword->setFont(font);
        label_RegPassword->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));

        verticalLayout_4->addWidget(label_RegPassword);

        lineEdit_RegPassword = new QLineEdit(frame);
        lineEdit_RegPassword->setObjectName("lineEdit_RegPassword");
        lineEdit_RegPassword->setMinimumSize(QSize(0, 40));
        lineEdit_RegPassword->setMaximumSize(QSize(16777215, 40));
        lineEdit_RegPassword->setBaseSize(QSize(0, 40));
        lineEdit_RegPassword->setStyleSheet(QString::fromUtf8("color: black;\n"
"padding-left: 10px;"));

        verticalLayout_4->addWidget(lineEdit_RegPassword);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        label_RegRePassword = new QLabel(frame);
        label_RegRePassword->setObjectName("label_RegRePassword");
        sizePolicy2.setHeightForWidth(label_RegRePassword->sizePolicy().hasHeightForWidth());
        label_RegRePassword->setSizePolicy(sizePolicy2);
        label_RegRePassword->setFont(font);
        label_RegRePassword->setStyleSheet(QString::fromUtf8("color: black;\n"
"text-align: left;"));

        verticalLayout_5->addWidget(label_RegRePassword);

        lineEdit_RegRePassword = new QLineEdit(frame);
        lineEdit_RegRePassword->setObjectName("lineEdit_RegRePassword");
        lineEdit_RegRePassword->setMinimumSize(QSize(0, 40));
        lineEdit_RegRePassword->setMaximumSize(QSize(16777215, 40));
        lineEdit_RegRePassword->setBaseSize(QSize(0, 40));
        lineEdit_RegRePassword->setStyleSheet(QString::fromUtf8("color: black;\n"
"padding-left: 10px;"));

        verticalLayout_5->addWidget(lineEdit_RegRePassword);


        verticalLayout_6->addLayout(verticalLayout_5);

        pushButton_Register = new QPushButton(frame);
        pushButton_Register->setObjectName("pushButton_Register");
        sizePolicy3.setHeightForWidth(pushButton_Register->sizePolicy().hasHeightForWidth());
        pushButton_Register->setSizePolicy(sizePolicy3);
        pushButton_Register->setMinimumSize(QSize(0, 40));
        pushButton_Register->setMaximumSize(QSize(16777215, 40));
        pushButton_Register->setBaseSize(QSize(0, 40));
        pushButton_Register->setFont(font2);
        pushButton_Register->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_Register->setStyleSheet(QString::fromUtf8("background-color: #2C2C2C;"));

        verticalLayout_6->addWidget(pushButton_Register);

        pushButton_GoToLogin = new QPushButton(frame);
        pushButton_GoToLogin->setObjectName("pushButton_GoToLogin");
        pushButton_GoToLogin->setEnabled(true);
        sizePolicy3.setHeightForWidth(pushButton_GoToLogin->sizePolicy().hasHeightForWidth());
        pushButton_GoToLogin->setSizePolicy(sizePolicy3);
        pushButton_GoToLogin->setMinimumSize(QSize(0, 30));
        pushButton_GoToLogin->setMaximumSize(QSize(16777215, 30));
        pushButton_GoToLogin->setBaseSize(QSize(0, 30));
        pushButton_GoToLogin->setFont(font2);
        pushButton_GoToLogin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_GoToLogin->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: #D9D9D9;\n"
"border-radius: 8px;\n"
"text-align: left;"));

        verticalLayout_6->addWidget(pushButton_GoToLogin);


        gridLayout_2->addWidget(frame_Registration, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page_Registration);

        horizontalLayout->addWidget(stackedWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        LoginWindow->setCentralWidget(centralwidget);

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
        pushButton_Registration->setText(QCoreApplication::translate("LoginWindow", "Dont have an account? Register Here.", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label_ForgotPass->setText(QCoreApplication::translate("LoginWindow", "Email:", nullptr));
        lineEdit_ForgotPass->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Email...", nullptr));
        pushButton_ForgotSubmit->setText(QCoreApplication::translate("LoginWindow", "Cancel", nullptr));
        pushButton_ForgotCancel->setText(QCoreApplication::translate("LoginWindow", "Reset", nullptr));
        label_FirstName->setText(QCoreApplication::translate("LoginWindow", "First Name:", nullptr));
        lineEdit_FirstName->setPlaceholderText(QCoreApplication::translate("LoginWindow", "First name...", nullptr));
        label_LastName->setText(QCoreApplication::translate("LoginWindow", "Last Name:", nullptr));
        lineEdit_LastName->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Last name...", nullptr));
        label_RegEmail->setText(QCoreApplication::translate("LoginWindow", "Email:", nullptr));
        lineEdit_RegEmail->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Email...", nullptr));
        label_RegPassword->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        lineEdit_RegPassword->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password...", nullptr));
        label_RegRePassword->setText(QCoreApplication::translate("LoginWindow", "Re-Enter Password:", nullptr));
        lineEdit_RegRePassword->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password...", nullptr));
        pushButton_Register->setText(QCoreApplication::translate("LoginWindow", "Register", nullptr));
        pushButton_GoToLogin->setText(QCoreApplication::translate("LoginWindow", "Already have an account? Log in here.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
