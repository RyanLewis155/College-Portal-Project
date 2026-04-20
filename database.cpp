#include "database.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QEventLoop>
#include <QDebug>
#include <qjsonobject.h>
#include "coursesection.h"

// Static members
QString Database::m_baseUrl = "";
QString Database::m_apiKey = "";
QNetworkAccessManager* Database::m_manager = nullptr;

void Database::init(const QString &baseUrl, const QString &apiKey)
{
    m_baseUrl = baseUrl;
    m_apiKey = apiKey;

    if (!m_manager) {
        m_manager = new QNetworkAccessManager();
    }
}

QVector<CourseSection> Database::getCourseData(const QStringList &crns,
                                               const QString &building,
                                               const QString &professor,
                                               const QString &days,
                                               const QString &term,
                                               const QString &course,
                                               const int &sectionNum,
                                               const QString &level,
                                               const QString &subject,
                                               const QString &courseNum)
{
    QueryParams params;

    // SELECT clause (Supabase embedded joins)
    params.select({
        "CRN",  
        "startTime",
        "endTime",
        "days",
        "section:sectionNum",
        "subject",
        "courseNum",
        "room:Room!CourseSection_roomID_fkey(building,room,capacity)",
        "Course!CourseSection_courseID_fkey(course:name)",
        "User!CourseSection_profID_fkey(instructor:name)"
    });

    // WHERE clauses (only if provided)
    if (!crns.isEmpty() && !crns[0].isEmpty()) {
        if (crns.size() == 1) {
            params.where("CRN", EQ, crns[0]);
        } else {
            QStringList quoted;
            for (const QString &crn : crns)
                quoted << crn;

            QString inClause = "(" + quoted.join(",") + ")";
            params.where("CRN", IN, inClause);
        }
    }

    if(!building.isEmpty())
        params.where("Room.building", EQ, building);

    if(!professor.isEmpty())
        params.where("User.name", ILIKE, QString("%" + professor + "%"));

    if(!course.isEmpty())
        params.where("Course.name", ILIKE, QString("%" + course + "%"));


    if (!term.isEmpty())
        params.where("term", EQ, term);

    if (sectionNum > 0)
        params.where("sectionNum", EQ, QString::number(sectionNum));

    if (!subject.isEmpty())
        params.where("subject", EQ, subject);

    if (!courseNum.isEmpty())
        params.where("courseNum", EQ, courseNum);

    if (!days.isEmpty() && days != "")
        params.where("days", EQ, days);

    QJsonArray raw = fetch("CourseSection", params);

    QVector<CourseSection> results;
    results.reserve(raw.size());

    for (int i = 0; i < raw.size(); ++i)
    {
        const QJsonValue &val = raw.at(i);

        if (!val.isObject())
            continue;

        CourseSection cs = fromJson(val.toObject());
        results.append(cs);
    }

    return results;
}



QJsonArray Database::getUserData(const QString &email,
                                 const QString &name,
                                 const QString &role,
                                 const QString &userId)
{
    QueryParams params;

    // SELECT clause (Supabase embedded joins)
    params.select({
        "id",
        "name",
        "passwordHash",
        "role",
        "email"
    });

    // WHERE clauses (only if provided)

    if (!userId.isEmpty())
        params.where("id", EQ, userId);

    if (!name.isEmpty())
        params.where("name", EQ, name);

    if (!email.isEmpty())
        params.where("email", EQ, email);

    if (!role.isEmpty())
        params.where("role", EQ, role);

    return fetch("User", params);
}

QJsonArray Database::getRegistrations(const QString &userId,
                                   const QStringList &crns,
                                   const QString &status)
{
    QueryParams params;

    // SELECT clause (Supabase embedded joins)
    params.select({
        "studentID",
        "CRN",
        "status",
        "timestamp"
    });

    // WHERE clauses (only if provided)

    if (!userId.isEmpty())
        params.where("studentID", EQ, userId);

    if (!crns.isEmpty() && !crns[0].isEmpty()) {
        if (crns.size() == 1) {
            params.where("CRN", EQ, crns[0]);
        } else {
            QStringList quoted;
            for (const QString &crn : crns)
                quoted << crn;

            QString inClause = "(" + quoted.join(",") + ")";
            params.where("CRN", IN, inClause);
        }
    }

    if (!status.isEmpty())
        params.where("status", EQ, status);

    return fetch("Registration", params);
}

QJsonArray Database::fetch(const QString &table,
                           const QueryParams &params)
{
    // get API url for desired query
    QUrl url = buildUrl(table, params);

    // build request
    QNetworkRequest request(url);
    request.setRawHeader("apikey", m_apiKey.toUtf8());
    request.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_manager->get(request);

    QEventLoop loop;

    QJsonArray result;

    QObject::connect(reply, &QNetworkReply::finished,
                     &loop, &QEventLoop::quit);

    loop.exec(); // blocks here until reply finishes

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Database error:" << reply->errorString();
        reply->deleteLater();
        return {};
    }

    QByteArray response = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(response);

    if (!doc.isArray()) {
        qWarning() << "Invalid JSON response (expected array)";
        reply->deleteLater();
        return {};
    }

    result = doc.array();

    reply->deleteLater();
    return result;
}


QString jsonValueToString(const QJsonValue &v)
{
    if (v.isString()) return v.toString();
    if (v.isDouble()) return QString::number(v.toDouble());
    if (v.isBool())   return v.toBool() ? "true" : "false";
    return "";
}

// flatten hierarchical JSON into simple key/value pairs
QJsonObject Database::flattenObject(
    const QJsonObject &obj,
    const QHash<QString, QStringList> &flattenRules)
{
    QJsonObject result = obj;

    for (auto it = flattenRules.begin(); it != flattenRules.end(); ++it)
    {
        QString key = it.key();

        if (!result.contains(key) || !result[key].isObject())
            continue;

        QJsonObject nested = result[key].toObject();
        QStringList fields = it.value();

        // Promote fields to top-level
        for (const QString &field : fields)
        {
            if (nested.contains(field))
            {
                result[field] = nested[field];
            }
        }
    }

    return result;
}

// flatten array of JSON
QJsonArray Database::flattenArray(
    const QJsonArray &array,
    const QHash<QString, QStringList> &flattenRules)
{
    QJsonArray result;

    for (const QJsonValue &val : array)
    {
        if (!val.isObject())
            continue;

        result.append(flattenObject(val.toObject(), flattenRules));
    }

    return result;
}

// convert operator signals to usable strings
QString Database::opToString(Operator op)
{
    switch (op)
    {
    case EQ:  return "eq";
    case GT:  return "gt";
    case LT:  return "lt";
    case GTE: return "gte";
    case LTE: return "lte";
    case NEQ: return "neq";
    case IN:  return "in";
    case ILIKE: return "ilike";
    default:  return "eq";
    }
}

// append query parameters to base URL
QUrl Database::buildUrl(const QString &table, const QueryParams &params)
{
    QUrl url(m_baseUrl + "/" + table, QUrl::StrictMode);
    QUrlQuery query;

    // -------------------------
    // SELECT
    // -------------------------
    if (!params.selectColumns.isEmpty())
    {
        query.addQueryItem(
            "select",
            params.selectColumns.join(",")
            );
    }
    else
    {
        query.addQueryItem("select", "*");
    }

    // -------------------------
    // WHERE CLAUSES
    // -------------------------
    for (const WhereClause &clause : params.whereClauses)
    {
        QString value = opToString(clause.op) + "." + clause.value;
        query.addQueryItem(clause.column, value);
    }


    // -------------------------
    // ORDER BY
    // -------------------------
    if (!params.orderByColumn.isEmpty())
    {
        QString orderValue = params.orderByColumn;

        if (params.orderDescending)
            orderValue += ".desc";
        else
            orderValue += ".asc";

        query.addQueryItem("order", orderValue);
    }

    url.setQuery(query);
    return url;
}

QJsonObject Database::insert(const QString &table,
                             const QJsonObject &data)
{
    // Build URL (same as fetch, but usually no filters)
    QUrl url = buildUrl(table, {});

    // Build request
    QNetworkRequest request(url);
    request.setRawHeader("apikey", m_apiKey.toUtf8());
    request.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    request.setRawHeader("Prefer", "return=representation");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    QByteArray body = QJsonDocument(data).toJson();


    // Send POST request
    QNetworkReply *reply = m_manager->post(request, body);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished,
                     &loop, &QEventLoop::quit);

    loop.exec(); // block until finished

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Insert error:" << reply->errorString();
        qWarning() << "HTTP status:" << reply->attribute(
            QNetworkRequest::HttpStatusCodeAttribute
            );
        reply->deleteLater();
        return {};
    }

    QByteArray response = reply->readAll();
    QJsonDocument responseDoc = QJsonDocument::fromJson(response);
    reply->deleteLater();

    if (responseDoc.isArray()) {
        QJsonArray arr = responseDoc.array();
        if (!arr.isEmpty() && arr.first().isObject())
            return arr.first().toObject();  // return first inserted row
    }

    return {};
}
