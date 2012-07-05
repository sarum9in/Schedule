#ifndef SUBJECTSCHEDULE_HPP
#define SUBJECTSCHEDULE_HPP

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

private slots:
    void goBack();

signals:
    void back();

private:
    Ui::SubjectSchedule *ui;
    Group *m_group;
    Subject *m_subject;
};

#endif // SUBJECTSCHEDULE_HPP
