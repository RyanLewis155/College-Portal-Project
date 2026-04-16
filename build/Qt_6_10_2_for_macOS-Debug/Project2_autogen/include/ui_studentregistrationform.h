/********************************************************************************
** Form generated from reading UI file 'studentregistrationform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTREGISTRATIONFORM_H
#define UI_STUDENTREGISTRATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentRegistrationForm
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_CourseEntries;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_course3;
    QTextEdit *textEdit_course2;
    QTextEdit *textEdit_course1;
    QPushButton *pushButton_CRNRegister;
    QFrame *frame_Semester;
    QVBoxLayout *verticalLayout;
    QLabel *label_SemesterPicker;
    QComboBox *comboBox_RegSemester;

    void setupUi(QWidget *StudentRegistrationForm)
    {
        if (StudentRegistrationForm->objectName().isEmpty())
            StudentRegistrationForm->setObjectName("StudentRegistrationForm");
        StudentRegistrationForm->resize(411, 300);
        StudentRegistrationForm->setMaximumSize(QSize(600, 300));
        StudentRegistrationForm->setStyleSheet(QString::fromUtf8("QWidget#StudentRegistrationForm {\n"
"	background-color: white;\n"
"}"));
        gridLayout = new QGridLayout(StudentRegistrationForm);
        gridLayout->setObjectName("gridLayout");
        frame_CourseEntries = new QFrame(StudentRegistrationForm);
        frame_CourseEntries->setObjectName("frame_CourseEntries");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_CourseEntries->sizePolicy().hasHeightForWidth());
        frame_CourseEntries->setSizePolicy(sizePolicy);
        frame_CourseEntries->setMinimumSize(QSize(0, 150));
        frame_CourseEntries->setMaximumSize(QSize(16777215, 100));
        frame_CourseEntries->setStyleSheet(QString::fromUtf8("QFrame#frame_CourseEntries {\n"
"	background-color: #EDEBD1;\n"
"}"));
        frame_CourseEntries->setFrameShape(QFrame::Shape::StyledPanel);
        frame_CourseEntries->setFrameShadow(QFrame::Shadow::Raised);
        frame_CourseEntries->setLineWidth(1);
        gridLayout_2 = new QGridLayout(frame_CourseEntries);
        gridLayout_2->setObjectName("gridLayout_2");
        textEdit_course3 = new QTextEdit(frame_CourseEntries);
        textEdit_course3->setObjectName("textEdit_course3");
        textEdit_course3->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(textEdit_course3, 0, 2, 1, 1);

        textEdit_course2 = new QTextEdit(frame_CourseEntries);
        textEdit_course2->setObjectName("textEdit_course2");
        textEdit_course2->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(textEdit_course2, 0, 1, 1, 1);

        textEdit_course1 = new QTextEdit(frame_CourseEntries);
        textEdit_course1->setObjectName("textEdit_course1");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit_course1->sizePolicy().hasHeightForWidth());
        textEdit_course1->setSizePolicy(sizePolicy1);
        textEdit_course1->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(textEdit_course1, 0, 0, 1, 1);

        pushButton_CRNRegister = new QPushButton(frame_CourseEntries);
        pushButton_CRNRegister->setObjectName("pushButton_CRNRegister");
        pushButton_CRNRegister->setMinimumSize(QSize(0, 35));
        pushButton_CRNRegister->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_CRNRegister->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_CRNRegister {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #006747;\n"
"	border: 1px solid #006747; \n"
"}\n"
"\n"
"QPushButton#pushButton_CRNRegister:hover {\n"
"    font: 16pt 'Inter-VariableFont_opsz,wght';\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"	background-color: #005432;\n"
"	border: 1px solid #005432; \n"
"}"));

        gridLayout_2->addWidget(pushButton_CRNRegister, 1, 1, 1, 1);


        gridLayout->addWidget(frame_CourseEntries, 1, 0, 1, 1);

        frame_Semester = new QFrame(StudentRegistrationForm);
        frame_Semester->setObjectName("frame_Semester");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_Semester->sizePolicy().hasHeightForWidth());
        frame_Semester->setSizePolicy(sizePolicy2);
        frame_Semester->setMinimumSize(QSize(0, 40));
        frame_Semester->setMaximumSize(QSize(16777215, 150));
        frame_Semester->setStyleSheet(QString::fromUtf8("QFrame#frame_Semester {\n"
"	background-color: white;\n"
"}"));
        verticalLayout = new QVBoxLayout(frame_Semester);
        verticalLayout->setObjectName("verticalLayout");
        label_SemesterPicker = new QLabel(frame_Semester);
        label_SemesterPicker->setObjectName("label_SemesterPicker");
        sizePolicy1.setHeightForWidth(label_SemesterPicker->sizePolicy().hasHeightForWidth());
        label_SemesterPicker->setSizePolicy(sizePolicy1);
        label_SemesterPicker->setMaximumSize(QSize(16777215, 50));
        label_SemesterPicker->setStyleSheet(QString::fromUtf8("QLabel#label_SemesterPicker {\n"
"	background-color: white;\n"
"	color: black;\n"
"}"));

        verticalLayout->addWidget(label_SemesterPicker);

        comboBox_RegSemester = new QComboBox(frame_Semester);
        comboBox_RegSemester->addItem(QString());
        comboBox_RegSemester->addItem(QString());
        comboBox_RegSemester->addItem(QString());
        comboBox_RegSemester->setObjectName("comboBox_RegSemester");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_RegSemester->sizePolicy().hasHeightForWidth());
        comboBox_RegSemester->setSizePolicy(sizePolicy3);
        comboBox_RegSemester->setMinimumSize(QSize(200, 0));
        comboBox_RegSemester->setMaximumSize(QSize(250, 40));
        comboBox_RegSemester->setAutoFillBackground(false);
        comboBox_RegSemester->setStyleSheet(QString::fromUtf8("QComboBox#comboBox_RegSemester {\n"
"	background-color: #EDEBD1;\n"
"	color: black;\n"
"}"));

        verticalLayout->addWidget(comboBox_RegSemester);


        gridLayout->addWidget(frame_Semester, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);


        retranslateUi(StudentRegistrationForm);

        QMetaObject::connectSlotsByName(StudentRegistrationForm);
    } // setupUi

    void retranslateUi(QWidget *StudentRegistrationForm)
    {
        StudentRegistrationForm->setWindowTitle(QCoreApplication::translate("StudentRegistrationForm", "Form", nullptr));
        pushButton_CRNRegister->setText(QCoreApplication::translate("StudentRegistrationForm", "Register", nullptr));
        label_SemesterPicker->setText(QCoreApplication::translate("StudentRegistrationForm", "Semester: ", nullptr));
        comboBox_RegSemester->setItemText(0, QCoreApplication::translate("StudentRegistrationForm", "Summer 2026", nullptr));
        comboBox_RegSemester->setItemText(1, QCoreApplication::translate("StudentRegistrationForm", "Fall 2026", nullptr));
        comboBox_RegSemester->setItemText(2, QCoreApplication::translate("StudentRegistrationForm", "Spring 2027", nullptr));

        comboBox_RegSemester->setCurrentText(QCoreApplication::translate("StudentRegistrationForm", "Summer 2026", nullptr));
        comboBox_RegSemester->setPlaceholderText(QCoreApplication::translate("StudentRegistrationForm", "Semester...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentRegistrationForm: public Ui_StudentRegistrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTREGISTRATIONFORM_H
