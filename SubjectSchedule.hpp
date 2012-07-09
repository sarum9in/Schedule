#pragma once

#include <QWidget>

#include "Group.hpp"

namespace Ui {
class SubjectSchedule;
}

class SubjectSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectSchedule(QWidget *parent = 0);
    void setGroupSubject(Group &group, const QString &m_subjectId, Subject &subject);
    ~SubjectSchedule();

private slots:
    void cellChanged(int row, int column);
    void saveTable();
    void printTable();

private:
    Ui::SubjectSchedule *ui;
    Group *m_group;
    Subject *m_subject;
    DateList m_dates;
    QString m_subjectId;
};
