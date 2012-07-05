#include "Subject.hpp"

Subject::Subject():
    m_hourCount(0)
{
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
