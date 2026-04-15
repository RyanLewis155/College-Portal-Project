#ifndef ROOM_H
#define ROOM_H

#include <QObject>

class Room : public QObject
{
    Q_OBJECT


public:
    explicit Room(QObject *parent = nullptr) : QObject(parent) {};

    explicit Room(QString roomID, QString name, int capacity, QObject *parent = nullptr) :
                    roomID(roomID), name(name), capacity(capacity), QObject(parent) {};


signals:

private:
    QString roomID;
    QString name;
    int capacity;
};

#endif // ROOM_H
