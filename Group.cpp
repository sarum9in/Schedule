#include "Group.hpp"

Group::Group():
    m_course(1)
{
}

const QString &Group::name() const
{
    return m_name;
}

void Group::setName(const QString &name_)
{
    m_name = name_;
}

int Group::course() const
{
    return m_course;
}

void Group::setCourse(const int course_)
{
    m_course = course_;
}

const QStringList &Group::members() const
{
    return m_members;
}

void Group::setMembers(const QStringList &members_)
{
    m_members = members_;
}

const QStringList &Group::subjectNames() const
{
    return m_subjectNames;
}

void Group::setSubjectNames(const QStringList &subjectNames_)
{
    m_subjectNames = subjectNames_;
}

Subject &Group::subject(const QString &name)
{
    Subject &subj = m_subjectByName[name];
    subj.setName(name);
    return subj;
}
