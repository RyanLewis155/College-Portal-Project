#include "professordisplay.h"
#include "ui_professordisplay.h"

ProfessorDisplay::ProfessorDisplay(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfessorDisplay)
{
    ui->setupUi(this);
}

ProfessorDisplay::~ProfessorDisplay()
{
    delete ui;
}
