#ifndef ADMINISTRATORDISPLAY_H
#define ADMINISTRATORDISPLAY_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class AdministratorDisplay;
}

class AdministratorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit AdministratorDisplay(QWidget *parent = nullptr);
    ~AdministratorDisplay();

private slots:
    void handleSearchResults(QStandardItemModel* model);

private:
    Ui::AdministratorDisplay *ui;
};

#endif // ADMINISTRATORDISPLAY_H
