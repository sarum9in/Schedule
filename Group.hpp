#ifndef GROUP_HPP
#define GROUP_HPP

#include <QString>
#include <QStringList>

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

private:
    QString m_name;
    int m_course;
    QStringList m_members;
};

#endif // GROUP_HPP
