#pragma once

#include <QWidget>
#include <QStringListModel>

#include "Group.hpp"

namespace Ui {
class SubjectListEdit;
}

class SubjectListEdit : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectListEdit(QWidget *parent = 0);
    void setGroup(Group &group_);
    ~SubjectListEdit();

private slots:
    void accept();
    void goBack();
    void addSubject();
    void removeSubject();
    void subjectClicked(const QModelIndex &index);
    void subjectClicked(const int n);
    void showSubjectList();
    void addStudent();
    void removeStudent();

signals:
    void back();

private:
    Ui::SubjectListEdit *ui;
    Group *m_group;
    QStringListModel *m_studentsModel;
    QStringListModel *m_subjectsModel;
};
