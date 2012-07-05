#include "SubjectSchedule.hpp"
#include "ui_SubjectSchedule.h"

SubjectSchedule::SubjectSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectSchedule)
{
    ui->setupUi(this);
}

void SubjectSchedule::setGroupSubject(Group &group, Subject &subject)
{
    m_group = &group;
    m_subject = &subject;
    ui->label->setText(trUtf8("%1 (%2 курс %3 группа)").arg(m_subject->name()).arg(m_group->course()).arg(m_group->name()));
}

void SubjectSchedule::goBack()
{
    emit back();
}

SubjectSchedule::~SubjectSchedule()
{
    delete ui;
}
