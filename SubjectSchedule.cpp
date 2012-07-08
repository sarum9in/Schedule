#include "SubjectSchedule.hpp"
#include "ui_SubjectSchedule.h"

#include <QLabel>

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
    ui->scheduleTable->setRowCount(m_group->members().size());
    ui->scheduleTable->setColumnCount(m_subject->hourCount()/2+1);
    for (int i = 0; i<m_group->members().size(); ++i)
    {
        ui->scheduleTable->setVerticalHeaderItem(i, new QTableWidgetItem(QString().setNum(i+1)));
        ui->scheduleTable->setCellWidget(i, 0, new QLabel(m_group->members().at(i)));
    }
    DateList lst = m_subject->autoDates();
    if (m_subject->dates())
        lst = *m_subject->dates();
    ui->scheduleTable->setHorizontalHeaderItem(0, new QTableWidgetItem(trUtf8("Студент")));
    for (int i = 0; 2*i<m_subject->hourCount(); ++i)
        ui->scheduleTable->setHorizontalHeaderItem(i+1, new QTableWidgetItem(lst[i].toString()));
}

SubjectSchedule::~SubjectSchedule()
{
    delete ui;
}
