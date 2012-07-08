#pragma once

#include <QWidget>

#include "Subject.hpp"
#include "SubjectDateModel.hpp"

namespace Ui {
class EditSubject;
}

class EditSubject : public QWidget
{
    Q_OBJECT

public:
    explicit EditSubject(QWidget *parent = 0);
    Subject *subject();
    void setSubject(Subject &subject_);
    ~EditSubject();

private slots:
    void accept();
    void setDatesState(int state);
    void setHourCount(int count);
    void updateDates();

private:
    Ui::EditSubject *ui;
    Subject *m_subject;
    SubjectDateModel *m_subjectDateModel;
};
