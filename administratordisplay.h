#ifndef ADMINISTRATORDISPLAY_H
#define ADMINISTRATORDISPLAY_H

#include <QWidget>

namespace Ui {
class AdministratorDisplay;
}

class AdministratorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit AdministratorDisplay(QWidget *parent = nullptr);
    ~AdministratorDisplay();

private:
    Ui::AdministratorDisplay *ui;
};

#endif // ADMINISTRATORDISPLAY_H
