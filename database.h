#ifndef DATABASE_H
#define DATABASE_H

#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QEventLoop>
#include <QDebug>
#include "coursesection.h"

#include "queryparams.h"

class Database
{
public:
    static void init(const QString &baseUrl, const QString &apiKey);
    // API methods
    static QVector<CourseSection> getCourseData(const QStringList &crns = {},
                                                const QString &room = "",
                                                const QString &professor = "",
                                                const QString &days = "",
                                                const QString &term = "",
                                                const QString &course = "",
                                                const int &sectionNum = 0,
                                                const QString &level = "",
                                                const QString &subject = "",
                                                const QString &courseNum = ""
                                                );

    static QJsonArray getCourseNameData(const int &CourseID = -1,
                                        const QString &Description = "",
                                        const QString &CourseName = ""
                                        );

    static QJsonArray getRoomData(const QString &roomID = "",
                                  const QString &building = "",
                                  const int &room = 0,
                                  const int &capacity = 0
                                  );

    static QJsonArray getUserData(const QString &email = "",
                                  const QString &name = "",
                                  const QString &role = "",
                                  const QString &userId = "");

    static QJsonArray getRegistrations(const QString &userId = "",
                                       const QStringList &crns = {},
                                       const QString &status = "Registered");

    static QJsonArray getPlans(const QString &studentID = "");

    static QJsonArray getPlanItems(const QString &planID = "");

    static QHash<QString, int> getNumRegistered(const QStringList &crns);

    // public helpers
    static QString jsonValueToString(const QJsonValue &v)
    {
        if (v.isString()) return v.toString();
        if (v.isDouble()) return QString::number(v.toDouble());
        if (v.isBool())   return v.toBool() ? "true" : "false";
        return "";
    }

    static QJsonObject insert(const QString &table,
                              const QJsonObject &data);

    static CourseSection getSingleCourseData(const QString &crn);

    static QJsonObject upsertCourseSection(const QString &table, const QJsonObject &data);
private:
    static QString m_baseUrl;
    static QString m_apiKey;
    static QNetworkAccessManager* m_manager;

    // basic operations
    static QJsonArray fetch(const QString &table,
                            const QueryParams &params);

    // internal helpers
    static QUrl buildUrl(const QString &table, const QueryParams &params);

    static QString opToString(Operator op);

    static QJsonObject flattenObject(
        const QJsonObject &obj,
        const QHash<QString, QStringList> &flattenRules
        );

    static QJsonArray flattenArray(
        const QJsonArray &array,
        const QHash<QString, QStringList> &flattenRules
        );
};

#endif
