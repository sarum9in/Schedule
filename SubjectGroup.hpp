#pragma once

#include <QList>
#include <QMap>
#include <QString>
#include <QDataStream>

#include "Subject.hpp"

struct SubjectGroup
{
    QString name;
    Subject lection, seminar, lab, test;
};

QDataStream &operator>>(QDataStream &in, SubjectGroup &sg);
QDataStream &operator<<(QDataStream &out, const SubjectGroup &sg);

typedef QMap<QString, SubjectGroup> SubjectGroupByNameMap;
