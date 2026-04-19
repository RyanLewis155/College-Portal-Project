#ifndef PROFESSORDISPLAY_H
#define PROFESSORDISPLAY_H

#include <QWidget>

namespace Ui {
class ProfessorDisplay;
}

class ProfessorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ProfessorDisplay(QWidget *parent = nullptr);
    ~ProfessorDisplay();

private:
    Ui::ProfessorDisplay *ui;
};

#endif // PROFESSORDISPLAY_H
