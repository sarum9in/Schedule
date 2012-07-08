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

SubjectGroup &Group::subject(const QString &name)
{
    SubjectGroup &subj = m_subjectByName[name];
    subj.name = name;
    return subj;
}

QDataStream &operator>>(QDataStream &in, Group &group)
{
    return in>>group.m_name>>group.m_course>>group.m_members>>group.m_subjectNames>>group.m_subjectByName;
}

QDataStream &operator<<(QDataStream &out, const Group &group)
{
    return out<<group.m_name<<group.m_course<<group.m_members<<group.m_subjectNames<<group.m_subjectByName;
}
