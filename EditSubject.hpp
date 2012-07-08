#pragma once

#include <QWidget>
#include <QScopedPointer>

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
    Subject subject() const;
    void setSubject(const Subject &subject_);
    ~EditSubject();

private slots:
    void accept();
    void setDatesState(int state);
    void setHourCount(int count);
    void updateDates();

private:
    Ui::EditSubject *ui;
    QScopedPointer<Subject> m_subject;
    SubjectDateModel *m_subjectDateModel;
};
