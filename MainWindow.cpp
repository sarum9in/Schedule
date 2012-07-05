#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include "EditGroup.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i<5; ++i)
        m_course[i] = new QStringListModel(this);
    ui->course1List->setModel(m_course[0]);
    ui->course2List->setModel(m_course[1]);
    ui->course3List->setModel(m_course[2]);
    ui->course4List->setModel(m_course[3]);
    ui->course5List->setModel(m_course[4]);
    connect(ui->course1List, SIGNAL(clicked(QModelIndex)), this, SLOT(groupClicked(QModelIndex)));
    connect(ui->course2List, SIGNAL(clicked(QModelIndex)), this, SLOT(groupClicked(QModelIndex)));
    connect(ui->course3List, SIGNAL(clicked(QModelIndex)), this, SLOT(groupClicked(QModelIndex)));
    connect(ui->course4List, SIGNAL(clicked(QModelIndex)), this, SLOT(groupClicked(QModelIndex)));
    connect(ui->course5List, SIGNAL(clicked(QModelIndex)), this, SLOT(groupClicked(QModelIndex)));
    connect(ui->subjectListEdit, SIGNAL(back()), this, SLOT(showCourses()));
}

void MainWindow::groupClicked(const QModelIndex &index)
{
    groupClicked(index.data().toString());
}

void MainWindow::groupClicked(const QString &group)
{
    Q_ASSERT(m_groupByName.contains(group));
    Group &group_ = m_groupByName[group];
    ui->stack->setCurrentWidget(ui->subjects);
    ui->subjectListEdit->setGroup(group_);
}

void MainWindow::repack()
{
    QStringList course[5];
    foreach (const Group &group, m_groupByName.values())
    {
        course[group.course()-1].append(group.name());
    }
    for (int i = 0; i<5; ++i)
        m_course[i]->setStringList(course[i]);
}

void MainWindow::showAddGroupDialog()
{
     EditGroup *editGroup = new EditGroup(m_groupByName, QString(), this);
     editGroup->exec();
     editGroup->deleteLater();
     repack();
}

void MainWindow::showCourses()
{
    ui->stack->setCurrentWidget(ui->courses);
}

MainWindow::~MainWindow()
{
    delete ui;
}
