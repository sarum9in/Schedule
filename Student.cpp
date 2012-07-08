#include "Student.hpp"

#include <QHash>

uint qHash(const QDate &date)
{
    return qHash(date.toString("yyyy/MM/dd"));
}

QDataStream &operator>>(QDataStream &in, Student &student)
{
    return in>>student.name>>student.data;
}

QDataStream &operator<<(QDataStream &out, const Student &student)
{
    return out<<student.name<<student.data;
}
