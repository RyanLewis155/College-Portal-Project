#ifndef QUERYPARAMS_H
#define QUERYPARAMS_H

#include <QString>
#include <QStringList>
#include <QList>

enum Operator {
    EQ,
    GT,
    LT,
    GTE,
    LTE,
    NEQ,
    IN
};

struct WhereClause {
    QString column;
    Operator op;
    QString value;
};

class QueryParams {
public:
    QStringList selectColumns;
    QList<WhereClause> whereClauses;
    QString orderByColumn;
    bool orderDescending = false;

    void select(const QStringList &cols) {
        selectColumns = cols;
    }

    void where(const QString &col, Operator op, const QString &val) {
        whereClauses.append({col, op, val});
    }

    void orderBy(const QString &col, bool desc = false) {
        orderByColumn = col;
        orderDescending = desc;
    }
};

#endif