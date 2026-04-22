#include "studentdisplay.h"
#include "ui_studentdisplay.h"
#include <QDebug>
#include <QStandardItemModel>
#include "user.h"
#include "studentregistrationform.h"
#include "viewplanform.h"


StudentDisplay::StudentDisplay(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentDisplay)
{
    ui->setupUi(this);
    ui->comboBox_term->view()->setCursor(Qt::PointingHandCursor);
    ui->comboBox_days->view()->setCursor(Qt::PointingHandCursor);
    ui->tableView_results->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    u = loggedIn;

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

    ui->label_WelcomeHeader->setText("Welcome, " + u->name);
    QList<ClassScheduleItem*> classList;
    ClassScheduleItem* class1 = new ClassScheduleItem();
    ClassScheduleItem* class2 = new ClassScheduleItem();
    ClassScheduleItem* class3 = new ClassScheduleItem();
    ClassScheduleItem* class4 = new ClassScheduleItem();

    class1->setFields(QString("CDA 4205"), QString("Computer Architecture"), QString("MW 10:45am-12:00pm"));
    class2->setFields(QString("CDA 4205L"), QString("Computer Architecture Lab"), QString("F 12:00pm-01:45pm"));
    class3->setFields(QString("CEN 4020"), QString("Software Engineering"), QString("MW 3:30pm-4:45pm"));
    class4->setFields(QString("CIS 4250"), QString("Ethics"), QString("MW 05:00pm-06:15pm"));

    classList.append(class1);
    classList.append(class2);
    classList.append(class3);
    classList.append(class4);

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
        gridLayout->addWidget(classSchedule[i], i/3, i % 3, Qt::AlignTop | Qt::AlignLeft);
    }

}


