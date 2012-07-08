#pragma once

#include <QString>
#include <QDate>
#include <QList>
#include <QMap>
#include <QScopedPointer>

typedef QList<QDate> DateList;

class Subject
{
public:
    Subject();
    Subject(const Subject &subj);
    Subject &operator=(const Subject &subj);
    int hourCount() const;
    void setHourCount(const int hourCount_);
    const QDate &firstClass() const;
    void setFirstClass(const QDate &firstClass_);
    const DateList *dates() const;
    void setDates(const DateList &dates_);
    void clearDates();
    DateList autoDates() const;

    operator bool() const;

private:
    int m_hourCount;
    QDate m_firstClass;
    QScopedPointer<DateList> m_dates;
};
