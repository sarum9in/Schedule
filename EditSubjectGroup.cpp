#include "EditSubjectGroup.hpp"
#include "ui_EditSubjectGroup.h"

EditSubjectGroup::EditSubjectGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditSubjectGroup)
{
    ui->setupUi(this);
}

EditSubjectGroup::~EditSubjectGroup()
{
    delete ui;
}

void EditSubjectGroup::setSubjectGroup(SubjectGroup &sg)
{
    m_subjectGroup = &sg;
    ui->lab->setSubject(m_subjectGroup->lab);
    ui->lection->setSubject(m_subjectGroup->lection);
    ui->seminar->setSubject(m_subjectGroup->seminar);
    ui->test->setSubject(m_subjectGroup->test);
}

SubjectGroup *EditSubjectGroup::subjectGroup()
{
    return m_subjectGroup;
}

void EditSubjectGroup::goBack()
{
    m_subjectGroup->name = ui->name->text();
    m_subjectGroup->lab = ui->lab->subject();
    m_subjectGroup->lection = ui->lection->subject();
    m_subjectGroup->seminar = ui->seminar->subject();
    m_subjectGroup->test = ui->test->subject();
    emit back();
}
