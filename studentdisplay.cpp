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
    //viewPlanLayout->addWidget(new ViewPlanForm());

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
    setupGroupedSchedule();

    QGridLayout* gridLayout = qobject_cast<QGridLayout*>(ui->widget_ClassSchedule->layout());
    if (!gridLayout)
        return;

    QList<ClassScheduleItem*> mwClasses;
    QList<ClassScheduleItem*> trClasses;
    QList<ClassScheduleItem*> fridayClasses;

    QString studentId = u->id;
    QJsonArray registrations = Database::getRegistrations(studentId);

    qDebug() << "Student ID:" << studentId;
    qDebug() << "Registration count:" << registrations.size();

    if (registrations.isEmpty()) {
        qDebug() << "No registrations found for student:" << studentId;
        return;
    }

    QStringList crns;
    for (int i = 0; i < registrations.size(); ++i)
    {
        QJsonValue val = registrations.at(i);

        if (!val.isObject())
            continue;

        QJsonObject obj = val.toObject();
        QJsonValue crnValue = obj.value("CRN");

        QString crn;
        if (crnValue.isString())
            crn = crnValue.toString();
        else if (crnValue.isDouble())
            crn = QString::number(crnValue.toInt());

        qDebug() << "Registration object:" << obj;
        qDebug() << "CRN read:" << crn;

        if (!crn.isEmpty())
            crns.append(crn);
    }

    if (crns.isEmpty()) {
        qDebug() << "Registrations returned, but no CRNs were found.";
        return;
    }

    QVector<CourseSection> sections = Database::getCourseData(crns);

    for (int i = 0; i < sections.size(); ++i)
    {
        const CourseSection& cs = sections.at(i);

        ClassScheduleItem* item = new ClassScheduleItem();

        QString courseCode = buildCourseCode(cs);
        QString courseName = cs.coursename.isEmpty() ? "Unnamed Course" : cs.coursename;
        QString meetText = buildMeetingText(cs);

        item->setFields(courseCode, courseName, meetText);

        int column = getScheduleColumn(cs.days);

        if (column == 0)
            mwClasses.append(item);
        else if (column == 1)
            trClasses.append(item);
        else if (column == 2)
            fridayClasses.append(item);
    }

    for (int i = 0; i < mwClasses.size(); ++i)
        gridLayout->addWidget(mwClasses[i], i + 1, 0);

    for (int i = 0; i < trClasses.size(); ++i)
        gridLayout->addWidget(trClasses[i], i + 1, 1);

    for (int i = 0; i < fridayClasses.size(); ++i)
        gridLayout->addWidget(fridayClasses[i], i + 1, 2);
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

    while (QLayoutItem* item = gridLayout->takeAt(0))
    {
        if (item->widget())
            item->widget()->deleteLater();
        delete item;
    }

    for (int i = 0; i < classSchedule.count(); ++i)
    {
        gridLayout->addWidget(classSchedule[i], i / 3, i % 3, Qt::AlignTop | Qt::AlignLeft);
    }
}
void StudentDisplay::setupGroupedSchedule()
{
    QGridLayout* gridLayout = qobject_cast<QGridLayout*>(ui->widget_ClassSchedule->layout());

    if (!gridLayout) {
        gridLayout = new QGridLayout(ui->widget_ClassSchedule);
        ui->widget_ClassSchedule->setLayout(gridLayout);
    }

    while (QLayoutItem* item = gridLayout->takeAt(0))
    {
        if (item->widget())
            item->widget()->deleteLater();
        delete item;
    }

    gridLayout->setSpacing(8);

    QLabel* mwHeader = new QLabel("Monday / Wednesday");
    QLabel* trHeader = new QLabel("Tuesday / Thursday");
    QLabel* fHeader = new QLabel("Friday");

    mwHeader->setAlignment(Qt::AlignCenter);
    trHeader->setAlignment(Qt::AlignCenter);
    fHeader->setAlignment(Qt::AlignCenter);

    mwHeader->setStyleSheet("font-weight: bold; padding: 6px; border: 1px solid lightgray;");
    trHeader->setStyleSheet("font-weight: bold; padding: 6px; border: 1px solid lightgray;");
    fHeader->setStyleSheet("font-weight: bold; padding: 6px; border: 1px solid lightgray;");

    gridLayout->addWidget(mwHeader, 0, 0);
    gridLayout->addWidget(trHeader, 0, 1);
    gridLayout->addWidget(fHeader, 0, 2);
}
int StudentDisplay::getScheduleColumn(const QString& days)
{
    if (days.contains('M') || days.contains('W'))
        return 0;

    if (days.contains('T') || days.contains('R'))
        return 1;

    if (days.contains('F'))
        return 2;

    return -1;
}

