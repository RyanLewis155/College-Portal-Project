#include "studentdisplay.h"
#include "ui_studentdisplay.h"
#include <QDebug>
#include <QStandardItemModel>
#include "user.h"
#include "studentregistrationform.h"
#include "viewplanform.h"

#include <QMessageBox>

#include "database.h"

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
    //deleted the hardcoded class that we had for testing

    loadRegisteredClasses();

    QGridLayout *registrationLayout = qobject_cast<QGridLayout*>(ui->widget_Register->layout());
    QGridLayout *viewPlanLayout = qobject_cast<QGridLayout*>(ui->widget_ViewPlans->layout());


    registrationLayout->addWidget(new StudentRegistrationForm(u));
    viewPlanLayout->addWidget(new ViewPlanForm(loggedIn));
}

StudentDisplay::~StudentDisplay()
{
    delete ui;
}
QString StudentDisplay::buildCourseCode(const CourseSection& cs)
{
    return cs.subject + " " + cs.courseNum;
}
QString StudentDisplay::buildMeetingText(const CourseSection& cs)
{
    QString roomText;

    if (!cs.building.isEmpty() && !cs.room.isEmpty())
        roomText = cs.building + " " + cs.room;
    else if (!cs.room.isEmpty())
        roomText = cs.room;
    else
        roomText = "Room TBA";

    return cs.days + " " + cs.startTime + "-" + cs.endTime + " | " + roomText;
}

void StudentDisplay::loadRegisteredClasses()
{
    QList<ClassScheduleItem*> classList;

    QString studentId = u->id;

    QJsonArray registrations = Database::getRegistrations(studentId);

    if (registrations.isEmpty()) {
        qDebug() << "No registrations found for student:" << studentId;
        PopulateClasses(classList);
        return;
    }

    QStringList crns;
    for (const QJsonValue& val : registrations)
    {
        if (!val.isObject())
            continue;

        QJsonObject obj = val.toObject();
        QString crn = obj.value("CRN").toString();

        if (!crn.isEmpty())
            crns.append(crn);
    }

    if (crns.isEmpty()) {
        qDebug() << "Registrations returned, but no CRNs were found.";
        PopulateClasses(classList);
        return;
    }

    QVector<CourseSection> sections = Database::getCourseData(crns);

    for (const CourseSection& cs : sections)
    {
        ClassScheduleItem* item = new ClassScheduleItem();

        QString courseCode = buildCourseCode(cs);
        QString courseName = cs.coursename.isEmpty() ? "Unnamed Course" : cs.coursename;
        QString meetText = buildMeetingText(cs);

        item->setFields(courseCode, courseName, meetText);
        classList.append(item);
    }

    PopulateClasses(classList);
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
    if (!gridLayout)
        return;
    for(int i = 0; i < classSchedule.count(); ++i)
    {
        gridLayout->addWidget(classSchedule[i], i/3, i % 3, Qt::AlignTop | Qt::AlignLeft);
    }

}

