// #ifndef USER_H
// #define USER_H

// #include <QObject>

// class User : public QObject
// {
//     Q_OBJECT
// public:
//     explicit User(QObject *parent = nullptr);
// explicit User(const QString& UserID, const QString& Email, const QString& FirstName, const QString& LastName, QObject *parent = nullptr) :
//                 UserID(UserID), Email(Email), FirstName(FirstName), LastName(LastName) {};
// private:
//     QString UserID;
//     QString Email;
//     QString FirstName;
//     QString LastName;

// signals:
//     void attemptRegistration();
// };

// #endif // USER_H

#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QMap>
#include <QStandardItemModel>

class User : public QObject
{
    Q_OBJECT

public:
    explicit User(QObject *parent = nullptr);
    ~User();

    // handler methods
    void searchCourses(const QString &term,
                        const QString &crn,
                        const QString &subject,
                        const QString &courseNum,
                        const QString &days);

    void searchCoursesEX(const QString &CRN, const QString &Building, const QString &Professor, const QString &Days, const QString &Term, const QString &Course, const int &SectionNum, const QString &Level, const QString &Subject, const QString &CourseNum);
signals:
    // Search results: list of rows (column name -> value)
    void searchResultsReady(QStandardItemModel* model);
};

#endif // USER_H