#pragma once

#include <QMap>
#include <QDate>
#include <QList>
#include <QString>
#include <QDataStream>

uint qHash(const QDate &date);

struct Student
{
    QString name;
    // subject -> (date -> data)
    QMap<QString, QMap<QDate, QString> > data;
};

typedef QList<Student> StudentList;

QDataStream &operator>>(QDataStream &in, Student &student);
QDataStream &operator<<(QDataStream &out, const Student &student);
