#include "Subject.hpp"

Subject::Subject():
    m_hourCount(0)
{
}

Subject::Subject(const Subject &subj):
    m_hourCount(subj.m_hourCount),
    m_firstClass(subj.m_firstClass)
{
    if (subj.m_dates)
        m_dates.reset(new DateList(*subj.m_dates.data()));
}

Subject &Subject::operator=(const Subject &subj)
{
    if (&subj!=this)
    {
        m_hourCount = subj.m_hourCount;
        m_firstClass = subj.m_firstClass;
        if (subj.m_dates)
            m_dates.reset(new DateList(*subj.m_dates.data()));
    }
    return *this;
}

int Subject::hourCount() const
{
    return m_hourCount;
}

void Subject::setHourCount(const int hourCount_)
{
    m_hourCount = hourCount_;
    if (!m_dates.isNull())
    {
        while (2*m_dates->size()<m_hourCount)
            if (m_dates->isEmpty())
                m_dates->push_back(m_firstClass);
            else
                m_dates->push_back(m_dates->back().addDays(7));
        while (2*m_dates->size()>m_hourCount)
            m_dates->pop_back();
    }
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
    // fast update call
    setHourCount(m_hourCount);
}

void Subject::clearDates()
{
    m_dates.reset();
}

DateList Subject::autoDates() const
{
    DateList lst;
    lst.append(m_firstClass);
    for (int i = 1; 2*i<m_hourCount; ++i)
    {
        lst.append(lst.back().addDays(7));
    }
    return lst;
}

Subject::operator bool() const
{
    return hourCount();
}

QDataStream &operator>>(QDataStream &in, Subject &subject)
{
    bool hasDates;
    DateList dateList;
    in>>subject.m_hourCount>>subject.m_firstClass>>hasDates;
    if (hasDates)
        in>>dateList;
    if (hasDates)
        subject.m_dates.reset(new DateList(dateList));
    else
        subject.m_dates.reset();
    return in;
}

QDataStream &operator<<(QDataStream &out, const Subject &subject)
{
    out<<subject.m_hourCount<<subject.m_firstClass;
    out<<static_cast<bool>(subject.m_dates);
    if (subject.m_dates)
        out<<*subject.m_dates;
    return out;
}
