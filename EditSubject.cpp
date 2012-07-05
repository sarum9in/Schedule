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

void EditSubject::setSubject(Subject &subject_)
{
    m_subject = &subject_;
    ui->subjectName->setText(m_subject->name());
    ui->hourCount->setValue(m_subject->hourCount());
    ui->firstClassDate->setDate(m_subject->firstClass());
    if (m_subject->dates())
    {
        ui->audoDates->setChecked(false);
    }
    else
    {
        ui->audoDates->setChecked(true);
    }
    updateDates();
}

void EditSubject::accept()
{
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
    m_subject->setHourCount(count);
    accept();
}

void EditSubject::updateDates()
{
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
