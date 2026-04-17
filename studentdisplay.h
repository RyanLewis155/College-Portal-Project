#ifndef STUDENTDISPLAY_H
#define STUDENTDISPLAY_H

#include <QMainWindow>
<<<<<<< HEAD
#include <QGraphicsScene>
#include <QGraphicsView>
=======
#include <QVector>
#include <QMap>
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
    explicit StudentDisplay(QWidget *parent = nullptr);
    ~StudentDisplay();

    void PopulateClasses(QList<ClassScheduleItem*> classSchedule);


private slots:

<<<<<<< HEAD
=======
    void on_pushButton_RegSC_clicked();

    void on_pushButton_RegCS_clicked();

    void on_pushButton_RegViewPlans_clicked();

    void on_pushButton_SCCS_clicked();

    void on_pushButton_SCReg_clicked();

    void on_pushButton_SCViewPlans_clicked();

    void on_pushButton_VPCS_clicked();

    void on_pushButton_VPReg_clicked();

    void on_pushButton_VPSC_clicked();

    void on_pushButton_CSReg_clicked();

    void on_pushButton_CSViewPlans_clicked();

    void on_pushButton_CSSC_clicked();

    void handleSearchResults(QStandardItemModel* model);

>>>>>>> c0144334e1c664c51a63687de216404671a9009a
private:
    Ui::StudentDisplay *ui;
    User* u;
};

#endif // STUDENTDISPLAY_H
