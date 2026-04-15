#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
explicit User(const QString& UserID, const QString& Email, const QString& FirstName, const QString& LastName, QObject *parent = nullptr) :
                UserID(UserID), Email(Email), FirstName(FirstName), LastName(LastName) {};
private:
    QString UserID;
    QString Email;
    QString FirstName;
    QString LastName;

signals:
    void attemptRegistration();
};

#endif // USER_H
