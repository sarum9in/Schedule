#pragma once

#include <QMainWindow>
#include <QModelIndex>
#include <QStringListModel>

#include "Group.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void groupClicked(const QModelIndex &index);
    void groupClicked(const QString &group);
    void repack();
    void showAddGroupDialog();
    void showCourses();

private:
    Ui::MainWindow *ui;
    GroupByNameMap m_groupByName;
    QStringListModel *m_course[5];
};
