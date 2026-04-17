#ifndef STUDENTDISPLAY_H
#define STUDENTDISPLAY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QMap>
#include <QGridLayout>
#include "classscheduleitem.h"


namespace Ui {
class StudentDisplay;
}

class StudentDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit StudentDisplay(QWidget *parent = nullptr);
    ~StudentDisplay();

    void PopulateClasses(QList<ClassScheduleItem*> classSchedule);


private slots:

    void handleSearchResults(const QVector<QMap<QString, QString>> &results);

private:
    Ui::StudentDisplay *ui;

};

#endif // STUDENTDISPLAY_H
