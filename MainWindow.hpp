#pragma once

#include <QMainWindow>
#include <QModelIndex>
#include <QStringListModel>
#include <QString>

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

protected:
    virtual void closeEvent(QCloseEvent *);

private slots:
    void groupClicked(const QModelIndex &index);
    void groupClicked(const QString &group);
    void repack();
    void showAddGroupDialog();
    void showCourses();

private:
    void load();
    void save();
    static QString storageDir();
    static QString storage();

private:
    Ui::MainWindow *ui;
    GroupByNameMap m_groupByName;
    QStringListModel *m_course[5];
};
