#include "SubjectSchedule.hpp"
#include "ui_SubjectSchedule.h"

SubjectSchedule::SubjectSchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubjectSchedule)
{
    ui->setupUi(this);
}

SubjectSchedule::~SubjectSchedule()
{
    delete ui;
}
