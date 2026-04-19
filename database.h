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

#include "queryparams.h"

class Database
{
public:
    static void init(const QString &baseUrl, const QString &apiKey);

    static QJsonArray fetch(const QString &table,
                            const QueryParams &params);

    static QJsonObject insert(const QString &table,
                              const QJsonObject &data);

private:
    static QString m_baseUrl;
    static QString m_apiKey;
    static QNetworkAccessManager* m_manager;

    static QUrl buildUrl(const QString &table, const QueryParams &params);
    static QString opToString(Operator op);
};

#endif
