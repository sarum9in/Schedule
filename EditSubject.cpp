#include "EditSubject.hpp"
#include "ui_EditSubject.h"

EditSubject::EditSubject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditSubject)
{
    ui->setupUi(this);
}

void EditSubject::setSubject(Subject &subject_)
{
    m_subject = &subject_;
    ui->subjectName->setText(m_subject->name());
    ui->hourCount->setValue(m_subject->hourCount());
    ui->firstClassDate->setDate(m_subject->firstClass());
    if (m_subject->dates())
    {
        ui->audoDates->setChecked(false);
        // TODO m_subject.dates()
    }
    else
        ui->audoDates->setChecked(true);
}

void EditSubject::accept()
{
    m_subject->setName(ui->subjectName->text());
    m_subject->setHourCount(ui->hourCount->value());
    m_subject->setFirstClass(ui->firstClassDate->date());
    m_subject->clearDates();
    if (ui->audoDates->checkState()!=Qt::Checked)
    {
        // TODO m_subject.setDates();
    }
}

void EditSubject::goBack()
{
    emit back();
}

EditSubject::~EditSubject()
{
    delete ui;
}
