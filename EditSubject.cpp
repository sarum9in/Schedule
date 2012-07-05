#include "EditSubject.hpp"
#include "ui_EditSubject.h"

EditSubject::EditSubject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditSubject),
    m_subjectDateModel(new SubjectDateModel(this))
{
    ui->setupUi(this);
    ui->classList->setModel(m_subjectDateModel);
    connect(ui->subjectName, SIGNAL(textChanged(QString)), this, SLOT(accept()));
    connect(ui->firstClassDate, SIGNAL(dateChanged(QDate)), this, SLOT(accept()));
    connect(ui->audoDates, SIGNAL(clicked()), this, SLOT(accept()));
}

Subject *EditSubject::subject()
{
    return m_subject;
}

void EditSubject::setSubject(Subject &subject_)
{
    m_subject = 0;
    ui->subjectName->setText(subject_.name());
    if (subject_.dates())
    {
        ui->audoDates->setChecked(false);
    }
    else
    {
        ui->audoDates->setChecked(true);
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
    m_subject->setName(ui->subjectName->text());
    m_subject->setHourCount(ui->hourCount->value());
    m_subject->setFirstClass(ui->firstClassDate->date());
    m_subject->clearDates();
    if (ui->audoDates->checkState()!=Qt::Checked)
    {
        m_subject->setDates(m_subjectDateModel->dateList());
    }
    updateDates();
}

void EditSubject::goBack()
{
    accept();
    emit back();
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
    if (ui->audoDates->checkState()!=Qt::Checked)
    {
        Q_ASSERT(m_subject->dates());
        m_subjectDateModel->setEditable(true);
        m_subjectDateModel->setDateList(*m_subject->dates());
    }
    else
    {
        Q_ASSERT(!m_subject->dates());
        m_subjectDateModel->setEditable(false);
        m_subjectDateModel->setDateList(m_subject->audoDates());
    }
}

EditSubject::~EditSubject()
{
    delete ui;
}
