#pragma once

#include <QDialog>
#include <QStringListModel>

#include "Group.hpp"

namespace Ui {
class EditGroup;
}

class EditGroup : public QDialog
{
    Q_OBJECT

public:
    explicit EditGroup(GroupByNameMap &groupByName_, const QString &group, QWidget *parent = 0);
    virtual void accept();
    ~EditGroup();

private slots:
    void addStudent();
    void removeStudent();

private:
    Ui::EditGroup *ui;
    QStringListModel *m_studentsModel;
    GroupByNameMap &m_groupByName;
    Group m_group;
    const QString m_name;
};
