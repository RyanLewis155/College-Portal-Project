#ifndef STUDENTDISPLAY_H
#define STUDENTDISPLAY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QMap>
#include <QGridLayout>
#include <QStandardItemModel>
#include "classscheduleitem.h"
#include "user.h"

namespace Ui {
class StudentDisplay;
}

class StudentDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit StudentDisplay(User* u, QWidget *parent = nullptr);
    ~StudentDisplay();

    void PopulateClasses(QList<ClassScheduleItem*> classSchedule);


private slots:
    void handleSearchResults(QStandardItemModel* model);

private:
    Ui::StudentDisplay *ui;
    User* u;
};

#endif // STUDENTDISPLAY_H
