#include "database.h"



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

    qDebug() << "Url: " << url.toString();

    // Build request
    QNetworkRequest request(url);
    request.setRawHeader("apikey", m_apiKey.toUtf8());
    request.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
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

    if (responseDoc.isObject())
        return responseDoc.object();

    return {};
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
    QString errorString;

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
