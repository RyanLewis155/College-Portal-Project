/********************************************************************************
** Form generated from reading UI file 'classscheduleitem.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSSCHEDULEITEM_H
#define UI_CLASSSCHEDULEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassScheduleItem
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_CourseAndNumber;
    QLabel *label_CourseName;
    QLabel *label_TimeAndLoc;

    void setupUi(QWidget *ClassScheduleItem)
    {
        if (ClassScheduleItem->objectName().isEmpty())
            ClassScheduleItem->setObjectName("ClassScheduleItem");
        ClassScheduleItem->resize(270, 162);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ClassScheduleItem->sizePolicy().hasHeightForWidth());
        ClassScheduleItem->setSizePolicy(sizePolicy);
        ClassScheduleItem->setMinimumSize(QSize(270, 162));
        ClassScheduleItem->setMaximumSize(QSize(270, 162));
        ClassScheduleItem->setBaseSize(QSize(270, 162));
        ClassScheduleItem->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(ClassScheduleItem);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ClassScheduleItem);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setStyleSheet(QString::fromUtf8("background-color: #EDEBD1;\n"
"border-radius: 25px;"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        label_CourseAndNumber = new QLabel(widget);
        label_CourseAndNumber->setObjectName("label_CourseAndNumber");
        label_CourseAndNumber->setMinimumSize(QSize(0, 16));
        label_CourseAndNumber->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter-VariableFont_opsz,wght")});
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        label_CourseAndNumber->setFont(font);
        label_CourseAndNumber->setStyleSheet(QString::fromUtf8("font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"font-weight: Bold;\n"
"color: black;\n"
""));
        label_CourseAndNumber->setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByMouse);

        verticalLayout->addWidget(label_CourseAndNumber);

        label_CourseName = new QLabel(widget);
        label_CourseName->setObjectName("label_CourseName");
        label_CourseName->setMinimumSize(QSize(0, 16));
        label_CourseName->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter-VariableFont_opsz,wght")});
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        label_CourseName->setFont(font1);
        label_CourseName->setStyleSheet(QString::fromUtf8("font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"color: #006747;"));

        verticalLayout->addWidget(label_CourseName);

        label_TimeAndLoc = new QLabel(widget);
        label_TimeAndLoc->setObjectName("label_TimeAndLoc");
        label_TimeAndLoc->setStyleSheet(QString::fromUtf8("font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"color: black;"));
        label_TimeAndLoc->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(label_TimeAndLoc);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(ClassScheduleItem);

        QMetaObject::connectSlotsByName(ClassScheduleItem);
    } // setupUi

    void retranslateUi(QWidget *ClassScheduleItem)
    {
        ClassScheduleItem->setWindowTitle(QCoreApplication::translate("ClassScheduleItem", "Form", nullptr));
        label_CourseAndNumber->setText(QCoreApplication::translate("ClassScheduleItem", "Course ABV & Number", nullptr));
        label_CourseName->setText(QCoreApplication::translate("ClassScheduleItem", "Course Name", nullptr));
        label_TimeAndLoc->setText(QCoreApplication::translate("ClassScheduleItem", "Meeting Time And Location", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassScheduleItem: public Ui_ClassScheduleItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSSCHEDULEITEM_H
