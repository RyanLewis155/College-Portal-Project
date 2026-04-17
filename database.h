#ifndef DATABASE_H
#define DATABASE_H

// #include <QObject>
// #include <QNetworkAccessManager>
// #include <QJsonArray>
// #include "queryparams.h"

// class Database : public QObject
// {
//     Q_OBJECT

// public:
//     explicit Database(QObject *parent = nullptr);

//     void setConfig(const QString &baseUrl, const QString &apiKey);

//     // Main fetch method
//     void fetch(const QString &table, const QueryParams &params);

// signals:
//     void fetchSucceeded(const QJsonArray &data);
//     void fetchFailed(const QString &error);

// private:
//     QNetworkAccessManager *networkManager;
//     QString m_baseUrl;
//     QString m_apiKey;

//     QString buildUrl(const QString &table, const QueryParams &params);
//     QString opToString(Operator op);
// };

#endif // DATABASE_H