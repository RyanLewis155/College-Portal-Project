/********************************************************************************
** Form generated from reading UI file 'studentdisplay.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDISPLAY_H
#define UI_STUDENTDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentDisplay
{
public:
    QGridLayout *gridLayout;
    QWidget *CentralWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page_ClassSchedule;
    QPushButton *pushButton_CSReg;
    QPushButton *pushButton_CSViewPlans;
    QPushButton *pushButton_CSSC;
    QWidget *page_Register;
    QPushButton *pushButton_RegViewPlans;
    QPushButton *pushButton_RegCS;
    QPushButton *pushButton_RegSC;
    QWidget *page_ViewPlans;
    QPushButton *pushButton_VPSC;
    QPushButton *pushButton_VPReg;
    QPushButton *pushButton_VPCS;
    QWidget *page_SearchCourses;
    QPushButton *pushButton_SCCS;
    QPushButton *pushButton_SCReg;
    QPushButton *pushButton_SCViewPlans;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *StudentDisplay)
    {
        if (StudentDisplay->objectName().isEmpty())
            StudentDisplay->setObjectName("StudentDisplay");
        StudentDisplay->resize(1523, 1001);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StudentDisplay->sizePolicy().hasHeightForWidth());
        StudentDisplay->setSizePolicy(sizePolicy);
        StudentDisplay->setSizeIncrement(QSize(0, 0));
        StudentDisplay->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(StudentDisplay);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        CentralWidget = new QWidget(StudentDisplay);
        CentralWidget->setObjectName("CentralWidget");
        sizePolicy.setHeightForWidth(CentralWidget->sizePolicy().hasHeightForWidth());
        CentralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(CentralWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(CentralWidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        stackedWidget->setMinimumSize(QSize(1440, 921));
        stackedWidget->setMaximumSize(QSize(1440, 921));
        stackedWidget->setBaseSize(QSize(1440, 921));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #CFC493;"));
        page_ClassSchedule = new QWidget();
        page_ClassSchedule->setObjectName("page_ClassSchedule");
        page_ClassSchedule->setStyleSheet(QString::fromUtf8("QWidget#page_ClassSchedule{ \n"
"	background-image:url(:/assets/ClassSchedule.png);\n"
"}"));
        pushButton_CSReg = new QPushButton(page_ClassSchedule);
        pushButton_CSReg->setObjectName("pushButton_CSReg");
        pushButton_CSReg->setGeometry(QRect(30, 300, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_CSReg->sizePolicy().hasHeightForWidth());
        pushButton_CSReg->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter-VariableFont_opsz,wght")});
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        pushButton_CSReg->setFont(font);
        pushButton_CSReg->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_CSReg->setAutoFillBackground(false);
        pushButton_CSReg->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_CSReg {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_CSReg:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_CSViewPlans = new QPushButton(page_ClassSchedule);
        pushButton_CSViewPlans->setObjectName("pushButton_CSViewPlans");
        pushButton_CSViewPlans->setGeometry(QRect(30, 500, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_CSViewPlans->sizePolicy().hasHeightForWidth());
        pushButton_CSViewPlans->setSizePolicy(sizePolicy1);
        pushButton_CSViewPlans->setFont(font);
        pushButton_CSViewPlans->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_CSViewPlans->setAutoFillBackground(false);
        pushButton_CSViewPlans->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_CSViewPlans {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_CSViewPlans:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_CSViewPlans->setFlat(false);
        pushButton_CSSC = new QPushButton(page_ClassSchedule);
        pushButton_CSSC->setObjectName("pushButton_CSSC");
        pushButton_CSSC->setGeometry(QRect(30, 700, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_CSSC->sizePolicy().hasHeightForWidth());
        pushButton_CSSC->setSizePolicy(sizePolicy1);
        pushButton_CSSC->setFont(font);
        pushButton_CSSC->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_CSSC->setAutoFillBackground(false);
        pushButton_CSSC->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_CSSC {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_CSSC:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        stackedWidget->addWidget(page_ClassSchedule);
        page_Register = new QWidget();
        page_Register->setObjectName("page_Register");
        page_Register->setStyleSheet(QString::fromUtf8("QWidget#page_Register{ \n"
"	background-image:url(:/assets/Register.png);\n"
"}"));
        pushButton_RegViewPlans = new QPushButton(page_Register);
        pushButton_RegViewPlans->setObjectName("pushButton_RegViewPlans");
        pushButton_RegViewPlans->setGeometry(QRect(30, 500, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_RegViewPlans->sizePolicy().hasHeightForWidth());
        pushButton_RegViewPlans->setSizePolicy(sizePolicy1);
        pushButton_RegViewPlans->setFont(font);
        pushButton_RegViewPlans->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_RegViewPlans->setAutoFillBackground(false);
        pushButton_RegViewPlans->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_RegViewPlans {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_RegViewPlans:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_RegViewPlans->setFlat(false);
        pushButton_RegCS = new QPushButton(page_Register);
        pushButton_RegCS->setObjectName("pushButton_RegCS");
        pushButton_RegCS->setGeometry(QRect(30, 100, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_RegCS->sizePolicy().hasHeightForWidth());
        pushButton_RegCS->setSizePolicy(sizePolicy1);
        pushButton_RegCS->setFont(font);
        pushButton_RegCS->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_RegCS->setAutoFillBackground(false);
        pushButton_RegCS->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_RegCS {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_RegCS:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_RegCS->setFlat(false);
        pushButton_RegSC = new QPushButton(page_Register);
        pushButton_RegSC->setObjectName("pushButton_RegSC");
        pushButton_RegSC->setGeometry(QRect(30, 700, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_RegSC->sizePolicy().hasHeightForWidth());
        pushButton_RegSC->setSizePolicy(sizePolicy1);
        pushButton_RegSC->setFont(font);
        pushButton_RegSC->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_RegSC->setAutoFillBackground(false);
        pushButton_RegSC->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_RegSC {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_RegSC:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_RegSC->setFlat(false);
        stackedWidget->addWidget(page_Register);
        page_ViewPlans = new QWidget();
        page_ViewPlans->setObjectName("page_ViewPlans");
        page_ViewPlans->setStyleSheet(QString::fromUtf8("QWidget#page_ViewPlans{ \n"
"	background-image:url(:/assets/ViewPlans.png);\n"
"}"));
        pushButton_VPSC = new QPushButton(page_ViewPlans);
        pushButton_VPSC->setObjectName("pushButton_VPSC");
        pushButton_VPSC->setGeometry(QRect(30, 700, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_VPSC->sizePolicy().hasHeightForWidth());
        pushButton_VPSC->setSizePolicy(sizePolicy1);
        pushButton_VPSC->setFont(font);
        pushButton_VPSC->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_VPSC->setAutoFillBackground(false);
        pushButton_VPSC->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_VPSC {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_VPSC:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_VPSC->setFlat(false);
        pushButton_VPReg = new QPushButton(page_ViewPlans);
        pushButton_VPReg->setObjectName("pushButton_VPReg");
        pushButton_VPReg->setGeometry(QRect(30, 300, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_VPReg->sizePolicy().hasHeightForWidth());
        pushButton_VPReg->setSizePolicy(sizePolicy1);
        pushButton_VPReg->setFont(font);
        pushButton_VPReg->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_VPReg->setAutoFillBackground(false);
        pushButton_VPReg->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_VPReg {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_VPReg:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_VPReg->setFlat(false);
        pushButton_VPCS = new QPushButton(page_ViewPlans);
        pushButton_VPCS->setObjectName("pushButton_VPCS");
        pushButton_VPCS->setGeometry(QRect(30, 100, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_VPCS->sizePolicy().hasHeightForWidth());
        pushButton_VPCS->setSizePolicy(sizePolicy1);
        pushButton_VPCS->setFont(font);
        pushButton_VPCS->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_VPCS->setAutoFillBackground(false);
        pushButton_VPCS->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_VPCS {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_VPCS:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_VPCS->setFlat(false);
        stackedWidget->addWidget(page_ViewPlans);
        page_SearchCourses = new QWidget();
        page_SearchCourses->setObjectName("page_SearchCourses");
        page_SearchCourses->setStyleSheet(QString::fromUtf8("QWidget#page_SearchCourses{ \n"
"	background-image:url(:/assets/SearchCourses.png);\n"
"}"));
        pushButton_SCCS = new QPushButton(page_SearchCourses);
        pushButton_SCCS->setObjectName("pushButton_SCCS");
        pushButton_SCCS->setGeometry(QRect(30, 100, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_SCCS->sizePolicy().hasHeightForWidth());
        pushButton_SCCS->setSizePolicy(sizePolicy1);
        pushButton_SCCS->setFont(font);
        pushButton_SCCS->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_SCCS->setAutoFillBackground(false);
        pushButton_SCCS->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_SCCS {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_SCCS:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_SCCS->setFlat(false);
        pushButton_SCReg = new QPushButton(page_SearchCourses);
        pushButton_SCReg->setObjectName("pushButton_SCReg");
        pushButton_SCReg->setGeometry(QRect(30, 300, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_SCReg->sizePolicy().hasHeightForWidth());
        pushButton_SCReg->setSizePolicy(sizePolicy1);
        pushButton_SCReg->setFont(font);
        pushButton_SCReg->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_SCReg->setAutoFillBackground(false);
        pushButton_SCReg->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_SCReg {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_SCReg:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_SCReg->setFlat(false);
        pushButton_SCViewPlans = new QPushButton(page_SearchCourses);
        pushButton_SCViewPlans->setObjectName("pushButton_SCViewPlans");
        pushButton_SCViewPlans->setGeometry(QRect(30, 500, 208, 97));
        sizePolicy1.setHeightForWidth(pushButton_SCViewPlans->sizePolicy().hasHeightForWidth());
        pushButton_SCViewPlans->setSizePolicy(sizePolicy1);
        pushButton_SCViewPlans->setFont(font);
        pushButton_SCViewPlans->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_SCViewPlans->setAutoFillBackground(false);
        pushButton_SCViewPlans->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_SCViewPlans {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: #006747;\n"
"    border-radius: 8px;\n"
"	background-color: #EDEBD1;\n"
"	border: 1px solid #EDEBD1; \n"
"}\n"
"\n"
"QPushButton#pushButton_SCViewPlans:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}"));
        pushButton_SCViewPlans->setFlat(false);
        stackedWidget->addWidget(page_SearchCourses);

        gridLayout_2->addWidget(stackedWidget, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 2, 1, 1);


        gridLayout->addWidget(CentralWidget, 0, 0, 1, 1);


        retranslateUi(StudentDisplay);

        stackedWidget->setCurrentIndex(2);
        pushButton_CSReg->setDefault(false);
        pushButton_CSViewPlans->setDefault(false);
        pushButton_CSSC->setDefault(false);
        pushButton_RegViewPlans->setDefault(false);
        pushButton_RegCS->setDefault(false);
        pushButton_RegSC->setDefault(false);
        pushButton_VPSC->setDefault(false);
        pushButton_VPReg->setDefault(false);
        pushButton_VPCS->setDefault(false);
        pushButton_SCCS->setDefault(false);
        pushButton_SCReg->setDefault(false);
        pushButton_SCViewPlans->setDefault(false);


        QMetaObject::connectSlotsByName(StudentDisplay);
    } // setupUi

    void retranslateUi(QWidget *StudentDisplay)
    {
        StudentDisplay->setWindowTitle(QCoreApplication::translate("StudentDisplay", "Form", nullptr));
        pushButton_CSReg->setText(QCoreApplication::translate("StudentDisplay", "Register", nullptr));
        pushButton_CSViewPlans->setText(QCoreApplication::translate("StudentDisplay", "View Plans", nullptr));
        pushButton_CSSC->setText(QCoreApplication::translate("StudentDisplay", "Search Courses", nullptr));
        pushButton_RegViewPlans->setText(QCoreApplication::translate("StudentDisplay", "View Plans", nullptr));
        pushButton_RegCS->setText(QCoreApplication::translate("StudentDisplay", "Class Schedule", nullptr));
        pushButton_RegSC->setText(QCoreApplication::translate("StudentDisplay", "Search Courses", nullptr));
        pushButton_VPSC->setText(QCoreApplication::translate("StudentDisplay", "Search Courses", nullptr));
        pushButton_VPReg->setText(QCoreApplication::translate("StudentDisplay", "Register", nullptr));
        pushButton_VPCS->setText(QCoreApplication::translate("StudentDisplay", "Class Schedule", nullptr));
        pushButton_SCCS->setText(QCoreApplication::translate("StudentDisplay", "Class Schedule", nullptr));
        pushButton_SCReg->setText(QCoreApplication::translate("StudentDisplay", "Register", nullptr));
        pushButton_SCViewPlans->setText(QCoreApplication::translate("StudentDisplay", "View Plans", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentDisplay: public Ui_StudentDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDISPLAY_H
