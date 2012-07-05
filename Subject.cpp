#include "Subject.hpp"

Subject::Subject():
    m_hourCount(0)
{
}

Subject::Subject(const Subject &subj):
    m_name(subj.m_name),
    m_hourCount(subj.m_hourCount),
    m_firstClass(subj.m_firstClass)
{
    if (subj.m_dates)
        m_dates.reset(new DateList(*subj.m_dates.data()));
}

Subject &Subject::operator=(const Subject &subj)
{
    m_name = subj.m_name;
    m_hourCount = subj.m_hourCount;
    m_firstClass = subj.m_firstClass;
    if (subj.m_dates)
        m_dates.reset(new DateList(*subj.m_dates.data()));
    return *this;
}

const QString &Subject::name() const
{
    return m_name;
}

void Subject::setName(const QString &name_)
{
    m_name = name_;
}

int Subject::hourCount() const
{
    return m_hourCount;
}

void Subject::setHourCount(const int hourCount_)
{
    m_hourCount = hourCount_;
}

const QDate &Subject::firstClass() const
{
    return m_firstClass;
}

void Subject::setFirstClass(const QDate &firstClass_)
{
    m_firstClass = firstClass_;
}

const DateList *Subject::dates() const
{
    return m_dates.data();
}

void Subject::setDates(const DateList &dates_)
{
    m_dates.reset(new DateList(dates_));
}

void Subject::clearDates()
{
    m_dates.reset();
}
