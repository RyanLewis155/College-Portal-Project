#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include "queryparams.h"

class Database
{
public:
    static void init(const QString &baseUrl, const QString &apiKey);

    static QJsonArray fetch(const QString &table,
                            const QueryParams &params);

private:
    static QString m_baseUrl;
    static QString m_apiKey;
    static QNetworkAccessManager* m_manager;

    static QUrl buildUrl(const QString &table, const QueryParams &params);
    static QString opToString(Operator op);
};

#endif