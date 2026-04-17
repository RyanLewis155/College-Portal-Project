#ifndef STUDENTDISPLAY_H
#define STUDENTDISPLAY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
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

private:
    Ui::StudentDisplay *ui;

};

#endif // STUDENTDISPLAY_H
