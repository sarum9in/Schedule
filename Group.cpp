#include "Group.hpp"

Group::Group()
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
