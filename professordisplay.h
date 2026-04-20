#ifndef PROFESSORDISPLAY_H
#define PROFESSORDISPLAY_H

#include <QWidget>
#include "user.h"

namespace Ui {
class ProfessorDisplay;
}

class ProfessorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ProfessorDisplay(User* loggedIn, QWidget *parent = nullptr);
    ~ProfessorDisplay();

private:
    Ui::ProfessorDisplay *ui;
    User* u;
};

#endif // PROFESSORDISPLAY_H
