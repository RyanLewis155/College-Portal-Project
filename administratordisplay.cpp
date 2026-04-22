#include "administratordisplay.h"
#include "ui_administratordisplay.h"
#include <qtabbar.h>
#include <QMessageBox>
#include "database.h"
#include "room.h"

AdministratorDisplay::AdministratorDisplay(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdministratorDisplay)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->setCursor(Qt::PointingHandCursor);
    u = loggedIn;

    if(!u->name.isNull())
    {
        ui->label_WelcomeHeader->setText(QString("Welcome, " + u->name));
    }

    QList<UserInfo> professors = u->getProfessors();

    for (int i = 0; i < professors.count(); ++i) {
        ui->comboBox_instructor->addItem(professors[i].FullName, QVariant::fromValue(professors[i].id));
    }

    QList<Room> rooms = u->getRooms();

    for (int i = 0; i < rooms.count(); ++i)
    {
        ui->comboBox_building->addItem(rooms[i].building, QVariant::fromValue(rooms[i].roomID));
    }

    QList<Course> courses = u->getCourses();

    for (int i = 0; i < courses.count(); ++i)
    {
        ui->comboBox_modifyCourse->addItem(courses[i].name, QVariant::fromValue(courses[i].courseID));
    }


    connect(ui->pushButton_search, &QPushButton::clicked, [=]() {
        u->searchCoursesEX(
            ui->lineEdit_CRN->text(),
            ui->lineEdit_Room->text(),
            ui->lineEdit_Professor->text(),
            ui->comboBox_days->currentText(),
            ui->comboBox_term->currentText(),
            ui->lineEdit_Course->text(),
            ui->lineEdit_sectionNum->text().toInt(),
            ui->comboBox_Level->currentText(),
            ui->lineEdit_subject->text(),
            ui->lineEdit_courseNum->text()
            );
    });

    connect(ui->pushButton_getCourse, &QPushButton::clicked, [=]() {
        u->searchForSingleCourse({ui->lineEdit_getCourse->text()});
    });

    connect(u, &User::searchForCourseReady,
            this, &AdministratorDisplay::handleSingleCourseSearch);

    // conflict report handlers
    connect(ui->pushButton_generate, &QPushButton::clicked, [=]() {
        u->getConflictReport(ui->comboBox_term->currentText());
    });
    connect(u, &User::conflictReportReady,
            this, &AdministratorDisplay::handleConflictReports);
}

AdministratorDisplay::~AdministratorDisplay()
{
    delete ui;
}

void AdministratorDisplay::clearModificationUI()
{
    ui->label_modifyCRN->clear(); // sets CRN
    ui->lineEdit_courseNumber->clear();
    ui->lineEdit_section->clear();
    ui->lineEdit_modifySubject->clear();
    ui->comboBox_modifyCourse->setCurrentIndex(-1);
    ui->timeEdit_startTime->setTime(QTime(0,0));
    ui->timeEdit_endTime->setTime(QTime(0,0));
    ui->checkBox_monday->setCheckState(Qt::Unchecked);
    ui->checkBox_wednesday->setCheckState(Qt::Unchecked);
    ui->checkBox_tuesday->setCheckState(Qt::Unchecked);
    ui->checkBox_thursday->setCheckState(Qt::Unchecked);
    ui->checkBox_friday->setCheckState(Qt::Unchecked);
    ui->comboBox_building->setCurrentIndex(-1);
    ui->lineEdit_room->clear();
    ui->comboBox_instructor->setCurrentIndex(-1);
}

void AdministratorDisplay::handleSearchResults(QStandardItemModel *model)
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
    ui->tableView_results->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_results->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

void AdministratorDisplay::handleSingleCourseSearch(CourseSection cs)
{
    ui->label_modifyCRN->setText(cs.crn); // sets CRN
    ui->lineEdit_courseNumber->setText(cs.courseNum);
    ui->lineEdit_section->setText(QString::number(cs.sectionNum));
    ui->lineEdit_modifySubject->setText(cs.subject);
    ui->comboBox_modifyCourse->setCurrentText(cs.coursename);
    ui->timeEdit_startTime->setTime(QTime::fromString(cs.startTime));
    ui->timeEdit_endTime->setTime(QTime::fromString(cs.endTime));
    if(cs.days == "MW")
    {
        ui->checkBox_monday->setCheckState(Qt::Checked);
        ui->checkBox_wednesday->setCheckState(Qt::Checked);
    } else if (cs.days == "TR")
    {
        ui->checkBox_tuesday->setCheckState(Qt::Checked);
        ui->checkBox_thursday->setCheckState(Qt::Checked);
    } else if (cs.days == "F")
    {
        ui->checkBox_friday->setCheckState(Qt::Checked);
    }
    
    ui->comboBox_building->setCurrentText(cs.building);
    ui->lineEdit_room->setText(cs.room);

    ui->comboBox_instructor->setCurrentText(cs.instructorname);

}

void AdministratorDisplay::handleConflictReports(QStandardItemModel* model)
{
    if (!model) {
        qDebug() << "Received null model";
        return;
    }

    qDebug() << "Received model with rows:" << model->rowCount();

    // -----------------------------
    // Clean up previous model safely
    // -----------------------------
    QAbstractItemModel *oldModel = ui->tableView_results1->model();
    if (oldModel && oldModel != model) {
        oldModel->deleteLater();
    }

    // -----------------------------
    // Transfer ownership to the view
    // -----------------------------
    model->setParent(ui->tableView_results1);
    ui->tableView_results1->setModel(model);

    // -----------------------------
    // UI polish
    // -----------------------------
    ui->tableView_results1->resizeColumnsToContents();
    ui->tableView_results1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_results1->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

void AdministratorDisplay::on_pushButton_Save_clicked()
{
    CourseSection cs;
    cs.crn = ui->label_modifyCRN->text();
    cs.startTime = ui->timeEdit_startTime->time().toString("HH:mm");
    cs.endTime = ui->timeEdit_endTime->time().toString("HH:mm");
    bool isMonday = ui->checkBox_monday->isChecked();
    bool isTuesday = ui->checkBox_tuesday->isChecked();
    bool isWednesday = ui->checkBox_wednesday->isChecked();
    bool isThursday = ui->checkBox_thursday->isChecked();
    bool isFriday = ui->checkBox_friday->isChecked();

    if(isMonday && isWednesday)
    {
        cs.days = "MW";
    } else if (isTuesday && isThursday)
    {
        cs.days = "TR";
    } else if (isFriday)
    {
        cs. days = "F";
    }

    cs.sectionNum = ui->lineEdit_modifySubject->text().toInt();

    cs.subject = ui->lineEdit_modifySubject->text();
    cs.courseNum = ui->lineEdit_courseNumber->text();
    cs.term = ui->comboBox_term->currentText();
    cs.buildingID = ui->comboBox_building->currentData().toInt();
    cs.room = ui->lineEdit_room->text();
    cs.courseID = ui->comboBox_modifyCourse->currentData().toInt();
    cs.professorID = ui->comboBox_instructor->currentData().toInt();

    QJsonObject SectionData = toJson(cs);

    QJsonObject result = Database::upsertCourseSection("CourseSection", SectionData);

    if(!result.isEmpty())
    {
        QMessageBox::information(this, "Success",
                                 "Course saved successfully.");
        clearModificationUI();
    }
    else
    {
        QMessageBox::warning(this, "Error",
                             "Failed to save course.");
    }
}


void AdministratorDisplay::on_pushButton_Cancel_clicked()
{
    clearModificationUI();
}

