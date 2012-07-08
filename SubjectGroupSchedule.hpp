#pragma once

#include <QWidget>

#include "Group.hpp"
#include "SubjectGroup.hpp"
#include "SubjectSchedule.hpp"

namespace Ui {
    class SubjectGroupSchedule;
}

class SubjectGroupSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectGroupSchedule(QWidget *parent = 0);
    ~SubjectGroupSchedule();

    void setGroupSubject(Group &group, SubjectGroup &subject);

private slots:
    void goBack();

signals:
    void back();

private:
    Ui::SubjectGroupSchedule *ui;
    Group *m_group;
    SubjectGroup *m_subjectGroup;
    SubjectSchedule *m_lab, *m_lection, *m_seminar, *m_test;
};
