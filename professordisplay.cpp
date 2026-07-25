#include "professordisplay.h"
#include "ui_professordisplay.h"

ProfessorDisplay::ProfessorDisplay(User* loggedIn, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfessorDisplay)
{
    ui->setupUi(this);
    u = loggedIn;

    ui->label_WelcomeHeader->setText("Welcome, " + u->name);
}

ProfessorDisplay::~ProfessorDisplay()
{
    delete ui;
}
