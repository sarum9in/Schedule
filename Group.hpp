#pragma once

#include <QDataStream>
#include <QString>
#include <QStringList>
#include <QList>
#include <QMap>

#include "SubjectGroup.hpp"
#include "Student.hpp"

class Group
{
public:
    Group();
    const QString &name() const;
    void setName(const QString &name_);
    int course() const;
    void setCourse(const int course_);
    QStringList memberNames() const;
    const StudentList &members() const;
    void setMembers(const StudentList &studentList);
    void appendMember();
    void removeMember(const int n);
    Student &member(const int n);
    QStringList subjectNames() const;
    void appendSubject();
    void removeSubject(const int n);
    SubjectGroup &subject(const int n);

private:
    friend QDataStream &operator>>(QDataStream &in, Group &group);
    friend QDataStream &operator<<(QDataStream &out, const Group &group);

private:
    QString m_name;
    int m_course;
    StudentList m_members;
    SubjectGroupList m_subjects;
};

QDataStream &operator>>(QDataStream &in, Group &group);
QDataStream &operator<<(QDataStream &out, const Group &group);

typedef QList<Group> GroupList;
typedef QMap<QString, Group> GroupByNameMap;
