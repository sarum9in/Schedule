#include "EditSubject.hpp"
#include "ui_EditSubject.h"

EditSubject::EditSubject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditSubject),
    m_subjectDateModel(new SubjectDateModel(this))
{
    ui->setupUi(this);
    ui->classList->setModel(m_subjectDateModel);
    connect(ui->firstClassDate, SIGNAL(dateChanged(QDate)), this, SLOT(accept()));
    connect(ui->autoDates, SIGNAL(clicked()), this, SLOT(accept()));
}

Subject *EditSubject::subject()
{
    if (ui->hourCount->value())
        return m_subject;
    else
        return 0;
}

void EditSubject::setSubject(Subject &subject_)
{
    m_subject = 0;
    if (subject_.dates())
    {
        ui->autoDates->setChecked(false);
    }
    else
    {
        ui->autoDates->setChecked(true);
    }
    ui->hourCount->setValue(subject_.hourCount());
    ui->firstClassDate->setDate(subject_.firstClass());
    m_subject = &subject_;
    updateDates();
}

void EditSubject::accept()
{
    if (!m_subject)
        return;
    m_subject->setHourCount(ui->hourCount->value());
    m_subject->setFirstClass(ui->firstClassDate->date());
    m_subject->clearDates();
    if (ui->autoDates->checkState()!=Qt::Checked)
    {
        m_subject->setDates(m_subjectDateModel->dateList());
    }
    updateDates();
}

void EditSubject::setDatesState(int state)
{
    m_subjectDateModel->setEditable(state!=Qt::Checked);
    accept();
    updateDates();
}

void EditSubject::setHourCount(int count)
{
    if (!m_subject)
        return;
    m_subject->setHourCount(count);
    accept();
}

void EditSubject::updateDates()
{
    if (!m_subject)
        return;
    if (ui->autoDates->checkState()!=Qt::Checked)
    {
        Q_ASSERT(m_subject->dates());
        m_subjectDateModel->setEditable(true);
        m_subjectDateModel->setDateList(*m_subject->dates());
    }
    else
    {
        Q_ASSERT(!m_subject->dates());
        m_subjectDateModel->setEditable(false);
        m_subjectDateModel->setDateList(m_subject->autoDates());
    }
}

EditSubject::~EditSubject()
{
    delete ui;
}
