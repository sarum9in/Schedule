#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QDir>
#include <QDesktopServices>

#include "EditGroup.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i<5; ++i)
        m_course[i] = new QStringListModel(this);
    m_courseView[0] = ui->course1List;
    m_courseView[1] = ui->course2List;
    m_courseView[2] = ui->course3List;
    m_courseView[3] = ui->course4List;
    m_courseView[4] = ui->course5List;
    for (int i = 0; i<5; ++i)
    {
        m_courseView[i]->setModel(m_course[i]);
        connect(m_courseView[i], SIGNAL(doubleClicked(QModelIndex)), this, SLOT(groupClicked(QModelIndex)));
    }
    connect(ui->subjectListEdit, SIGNAL(back()), this, SLOT(showCourses()));
    load();
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

void MainWindow::removeGroups()
{
    for (int i = 0; i<5; ++i)
    {
        QModelIndexList selected = m_courseView[i]->selectionModel()->selectedIndexes();
        foreach (const QModelIndex &index, selected)
        {
            m_groupByName.remove(index.data().toString());
        }
    }
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

void MainWindow::closeEvent(QCloseEvent *)
{
    save();
}

QString MainWindow::storageDir()
{
    return QDesktopServices::storageLocation(QDesktopServices::DataLocation);
}

QString MainWindow::storage()
{
    return storageDir()+QDir::separator()+"db.data";
}

static const quint64 magic = 0xf3adde19df793d6bULL;

void MainWindow::load()
{
    QFile db(storage());
    if (db.exists())
    {
        const bool ret = db.open(QIODevice::ReadOnly);
        Q_ASSERT(ret);
        QDataStream input(&db);
        quint64 fmagic;
        input>>fmagic;
        if (fmagic==::magic)
        {
            input>>m_groupByName;
            repack();
        }
    }
}

void MainWindow::save()
{
    qDebug()<<storage();
    QFile db(storage());
    QDir dir = QDir::rootPath();
    dir.mkpath(storageDir());
    const bool ret = db.open(QIODevice::WriteOnly);
    Q_ASSERT(ret);
    QDataStream output(&db);
    output<<magic;
    output<<m_groupByName;
}
