#ifndef GROUP_HPP
#define GROUP_HPP

#include <QString>
#include <QStringList>
#include <QList>
#include <QMap>

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

typedef QList<Group> GroupList;
typedef QMap<QString, Group> GroupByNameMap;

#endif // GROUP_HPP
