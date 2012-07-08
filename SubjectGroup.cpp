#include "SubjectGroup.hpp"

QDataStream &operator>>(QDataStream &in, SubjectGroup &sg)
{
    return in>>sg.name>>sg.lab>>sg.lection>>sg.seminar>>sg.test;
}

QDataStream &operator<<(QDataStream &out, const SubjectGroup &sg)
{
    return out<<sg.name<<sg.lab<<sg.lection<<sg.seminar<<sg.test;
}
