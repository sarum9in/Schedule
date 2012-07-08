#pragma once

#include <QString>
#include <QStringList>
#include <QList>
#include <QMap>

#include "SubjectGroup.hpp"

class Group
{
public:
    Group();
    const QString &name() const;
    void setName(const QString &name_);
    int course() const;
    void setCourse(const int course_);
    const QStringList &members() const;
    void setMembers(const QStringList &members_);
    const QStringList &subjectNames() const;
    void setSubjectNames(const QStringList &subjectNames_);
    SubjectGroup &subject(const QString &name);

private:
    QString m_name;
    int m_course;
    QStringList m_members;
    QStringList m_subjectNames;
    SubjectGroupByNameMap m_subjectByName;
};

typedef QList<Group> GroupList;
typedef QMap<QString, Group> GroupByNameMap;
