#pragma once

#include <QWidget>

#include "SubjectGroup.hpp"
#include "EditSubject.hpp"

namespace Ui {
    class EditSubjectGroup;
}

class EditSubjectGroup : public QWidget
{
    Q_OBJECT

public:
    explicit EditSubjectGroup(QWidget *parent = 0);
    ~EditSubjectGroup();

    void setSubjectGroup(SubjectGroup &sg);
    SubjectGroup *subjectGroup();

private slots:
    void goBack();

signals:
    void back();

private:
    Ui::EditSubjectGroup *ui;
    SubjectGroup *m_subjectGroup;
};
