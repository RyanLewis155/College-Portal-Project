#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QMap>
#include <QStandardItemModel>
#include "userinfo.h"

class User : public QObject
{
    Q_OBJECT

public:
    // attributes
    QString id;
    QString role;
    QString name;

    explicit User(UserInfo u, QObject *parent = nullptr);
    ~User();

    // handler methods
    void searchCourses(const QString &term,
                        const QString &crn,
                        const QString &subject,
                        const QString &courseNum,
                        const QString &days);

    void searchCoursesEX(const QString &CRN,
                               const QString &Building,
                               const QString &Professor,
                               const QString &Days,
                               const QString &Term,
                               const QString &Course,
                               const int &SectionNum,
                               const QString &Level,
                               const QString &Subject,
                               const QString &CourseNum
                         );

    void getConflictReport(const QString &term);

    void handleRegistration(const QString &term, const QStringList &crns);

signals:
    // Search results: list of rows (column name -> value)
    void searchResultsReady(QStandardItemModel* model);
    void conflictReportReady(QStandardItemModel* model);
    void registrationComplete(const QString &message);

private:
    // helpers for checking course conflicts
    QHash<QString, QStringList> validateCourses(const QString &term, const QStringList &crns = {});

};

#endif // USER_H