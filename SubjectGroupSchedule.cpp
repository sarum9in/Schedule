#include "SubjectGroupSchedule.hpp"
#include "ui_SubjectGroupSchedule.h"

SubjectGroupSchedule::SubjectGroupSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectGroupSchedule),
    m_lab(new SubjectSchedule),
    m_lection(new SubjectSchedule),
    m_seminar(new SubjectSchedule),
    m_test(new SubjectSchedule)
{
    ui->setupUi(this);
}

SubjectGroupSchedule::~SubjectGroupSchedule()
{
    delete ui;
}

void SubjectGroupSchedule::setGroupSubject(Group &group, SubjectGroup &subject)
{
    m_group = &group;
    m_subjectGroup = &subject;
    ui->label->setText(trUtf8("%1 (%2 курс %3 группа)").arg(m_subjectGroup->name).arg(m_group->course()).arg(m_group->name()));
    ui->subjectScheduleTab->clear();
#define ADD_TAB(NAME, TEXT) \
    if (m_subjectGroup->NAME) \
    { \
        m_##NAME->setGroupSubject(*m_group, subject.name+"::"+TEXT, m_subjectGroup->NAME); \
        ui->subjectScheduleTab->addTab(m_##NAME, TEXT); \
    }
    ADD_TAB(lection, trUtf8("Лекции"));
    ADD_TAB(lab, trUtf8("Лабораторные"));
    ADD_TAB(seminar, trUtf8("Семинары"));
    ADD_TAB(test, trUtf8("Контрольные"));
}

void SubjectGroupSchedule::goBack()
{
    emit back();
}
