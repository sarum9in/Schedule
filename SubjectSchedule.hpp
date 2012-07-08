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
    void setGroupSubject(Group &group, Subject &subject);
    ~SubjectSchedule();

private:
    Ui::SubjectSchedule *ui;
    Group *m_group;
    Subject *m_subject;
};
