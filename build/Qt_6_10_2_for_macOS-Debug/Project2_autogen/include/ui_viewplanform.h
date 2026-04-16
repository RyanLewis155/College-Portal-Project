/********************************************************************************
** Form generated from reading UI file 'viewplanform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPLANFORM_H
#define UI_VIEWPLANFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewPlanForm
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_ViewPlan;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_PlansList;
    QTableWidget *tableWidget_PlanView;

    void setupUi(QWidget *ViewPlanForm)
    {
        if (ViewPlanForm->objectName().isEmpty())
            ViewPlanForm->setObjectName("ViewPlanForm");
        ViewPlanForm->resize(1125, 825);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ViewPlanForm->sizePolicy().hasHeightForWidth());
        ViewPlanForm->setSizePolicy(sizePolicy);
        ViewPlanForm->setMinimumSize(QSize(788, 578));
        ViewPlanForm->setMaximumSize(QSize(1125, 825));
        ViewPlanForm->setBaseSize(QSize(1125, 825));
        ViewPlanForm->setStyleSheet(QString::fromUtf8("QWidget#ViewPlanForm {\n"
"	background-color: green;\n"
"}"));
        gridLayout = new QGridLayout(ViewPlanForm);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_ViewPlan = new QFrame(ViewPlanForm);
        frame_ViewPlan->setObjectName("frame_ViewPlan");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_ViewPlan->sizePolicy().hasHeightForWidth());
        frame_ViewPlan->setSizePolicy(sizePolicy1);
        frame_ViewPlan->setMinimumSize(QSize(0, 1000));
        frame_ViewPlan->setMaximumSize(QSize(16777215, 1000));
        frame_ViewPlan->setStyleSheet(QString::fromUtf8("QFrame#frame_ViewPlan {\n"
"	background-color: green;\n"
"}"));
        horizontalLayout = new QHBoxLayout(frame_ViewPlan);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        horizontalLayout->setContentsMargins(15, 15, 15, 15);
        listWidget_PlansList = new QListWidget(frame_ViewPlan);
        listWidget_PlansList->setObjectName("listWidget_PlansList");
        listWidget_PlansList->setMinimumSize(QSize(250, 0));
        listWidget_PlansList->setMaximumSize(QSize(300, 16777215));
        listWidget_PlansList->setStyleSheet(QString::fromUtf8("QListWidget#listWidget_PlansList {\n"
"	background-color: white;\n"
"	border: 2px black;\n"
"	border-style: solid;\n"
"}"));

        horizontalLayout->addWidget(listWidget_PlansList);

        tableWidget_PlanView = new QTableWidget(frame_ViewPlan);
        tableWidget_PlanView->setObjectName("tableWidget_PlanView");
        tableWidget_PlanView->setMinimumSize(QSize(600, 0));
        tableWidget_PlanView->setMaximumSize(QSize(600, 16777215));
        tableWidget_PlanView->setStyleSheet(QString::fromUtf8("QTableWidget#tableWidget_PlanView {\n"
"	background-color: white;\n"
"	border: 2px black;\n"
"	border-style: solid;\n"
"}"));

        horizontalLayout->addWidget(tableWidget_PlanView);


        gridLayout->addWidget(frame_ViewPlan, 0, 0, 1, 1);


        retranslateUi(ViewPlanForm);

        QMetaObject::connectSlotsByName(ViewPlanForm);
    } // setupUi

    void retranslateUi(QWidget *ViewPlanForm)
    {
        ViewPlanForm->setWindowTitle(QCoreApplication::translate("ViewPlanForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewPlanForm: public Ui_ViewPlanForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPLANFORM_H
