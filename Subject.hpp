#ifndef SUBJECT_HPP
#define SUBJECT_HPP

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
    const QString &name() const;
    void setName(const QString &name_);
    int hourCount() const;
    void setHourCount(const int hourCount_);
    const QDate &firstClass() const;
    void setFirstClass(const QDate &firstClass_);
    const DateList *dates() const;
    void setDates(const DateList &dates_);
    void clearDates();

private:
    QString m_name;
    int m_hourCount;
    QDate m_firstClass;
    QScopedPointer<DateList> m_dates;
};

typedef QMap<QString, Subject> SubjectByNameMap;

#endif // SUBJECT_HPP
