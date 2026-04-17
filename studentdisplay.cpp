#include "studentdisplay.h"
#include "ui_studentdisplay.h"
#include <QDebug>
#include <QStandardItemModel>
#include "user.h"
#include "studentregistrationform.h"
#include "viewplanform.h"


StudentDisplay::StudentDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentDisplay)
{
    ui->setupUi(this);

    u = new User();

    // course search handlers
    connect(ui->pushButton_search, &QPushButton::clicked, [=]() {
        u->searchCourses(
            ui->comboBox_term->currentText(),
            ui->lineEdit_CRN->text(),
            ui->lineEdit_subject->text(),
            ui->lineEdit_courseNum->text(),
            ui->comboBox_days->currentText()
        );
    });
    connect(u, &User::searchResultsReady,
            this, &StudentDisplay::handleSearchResults);

    QList<ClassScheduleItem*> classList;
    ClassScheduleItem* class1 = new ClassScheduleItem();
    ClassScheduleItem* class2 = new ClassScheduleItem();
    ClassScheduleItem* class3 = new ClassScheduleItem();
    ClassScheduleItem* class4 = new ClassScheduleItem();
    ClassScheduleItem* class5 = new ClassScheduleItem();

    class1->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class2->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class3->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class4->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class5->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));

    classList.append(class1);
    classList.append(class2);
    classList.append(class3);
    classList.append(class4);
    classList.append(class5);

    PopulateClasses(classList);

    QGridLayout *registrationLayout = qobject_cast<QGridLayout*>(ui->widget_Register->layout());
    QGridLayout *viewPlanLayout = qobject_cast<QGridLayout*>(ui->widget_ViewPlans->layout());


    registrationLayout->addWidget(new StudentRegistrationForm());
    viewPlanLayout->addWidget(new ViewPlanForm());

}

StudentDisplay::~StudentDisplay()
{
    delete ui;
}

void StudentDisplay::handleSearchResults(QStandardItemModel* model)
{
    if (!model) {
        qDebug() << "Received null model";
        return;
    }

    qDebug() << "Received model with rows:" << model->rowCount();

    // -----------------------------
    // Clean up previous model safely
    // -----------------------------
    QAbstractItemModel *oldModel = ui->tableView_results->model();
    if (oldModel) {
        oldModel->deleteLater();
    }

    // -----------------------------
    // Transfer ownership to the view
    // -----------------------------
    model->setParent(ui->tableView_results);
    ui->tableView_results->setModel(model);

    // -----------------------------
    // UI polish
    // -----------------------------
    ui->tableView_results->resizeColumnsToContents();
}

void StudentDisplay::PopulateClasses(QList<ClassScheduleItem*> classSchedule)
{
    QGridLayout* gridLayout = qobject_cast<QGridLayout*>(ui->widget_ClassSchedule->layout());

    for(int i = 0; i < classSchedule.count(); ++i)
    {
        gridLayout->addWidget(classSchedule[i], i/3, i % 3);
    }
}


