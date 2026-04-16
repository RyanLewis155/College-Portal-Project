#include "viewplanform.h"
#include "ui_viewplanform.h"

ViewPlanForm::ViewPlanForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewPlanForm)
{
    ui->setupUi(this);
}

ViewPlanForm::~ViewPlanForm()
{
    delete ui;
}
