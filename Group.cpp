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

QStringList Group::memberNames() const
{
    QStringList lst;
    foreach (const Student &student, m_members)
    {
        lst.append(student.name);
    }
    return lst;
}

void Group::setMembers(const StudentList &studentList)
{
    m_members = studentList;
}

void Group::appendMember()
{
    m_members.append(Student());
    m_members.back().name = QObject::trUtf8("Новый студент");
}

void Group::removeMember(const int n)
{
    m_members.erase(m_members.begin()+n);
}

Student &Group::member(const int n)
{
    return m_members[n];
}

QStringList Group::subjectNames() const
{
    QStringList lst;
    foreach (const SubjectGroup &sg, m_subjects)
    {
        lst.append(sg.name);
    }
    return lst;
}

void Group::appendSubject()
{
    m_subjects.append(SubjectGroup());
    m_subjects.back().name = QObject::trUtf8("Новый предмет");
}

void Group::removeSubject(const int n)
{
    Q_ASSERT(0<=n && n<m_subjects.size());
    m_subjects.erase(m_subjects.begin()+n);
}

SubjectGroup &Group::subject(const int n)
{
    SubjectGroup &subj = m_subjects[n];
    return subj;
}

const StudentList &Group::members() const
{
    return m_members;
}

QDataStream &operator>>(QDataStream &in, Group &group)
{
    return in>>group.m_name>>group.m_course>>group.m_members>>group.m_subjects;
}

QDataStream &operator<<(QDataStream &out, const Group &group)
{
    return out<<group.m_name<<group.m_course<<group.m_members<<group.m_subjects;
}
