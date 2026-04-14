/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashBoard
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DashBoard)
    {
        if (DashBoard->objectName().isEmpty())
            DashBoard->setObjectName("DashBoard");
        DashBoard->resize(800, 600);
        centralwidget = new QWidget(DashBoard);
        centralwidget->setObjectName("centralwidget");
        DashBoard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DashBoard);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        DashBoard->setMenuBar(menubar);
        statusbar = new QStatusBar(DashBoard);
        statusbar->setObjectName("statusbar");
        DashBoard->setStatusBar(statusbar);

        retranslateUi(DashBoard);

        QMetaObject::connectSlotsByName(DashBoard);
    } // setupUi

    void retranslateUi(QMainWindow *DashBoard)
    {
        DashBoard->setWindowTitle(QCoreApplication::translate("DashBoard", "DashBoard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashBoard: public Ui_DashBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
