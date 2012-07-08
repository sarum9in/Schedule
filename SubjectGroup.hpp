#pragma once

#include <QList>
#include <QMap>
#include <QString>

#include "Subject.hpp"

struct SubjectGroup
{
    QString name;
    Subject lection, seminar, lab, test;
};

typedef QMap<QString, SubjectGroup> SubjectGroupByNameMap;
