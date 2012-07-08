#include "SubjectListEdit.hpp"
#include "ui_SubjectListEdit.h"

SubjectListEdit::SubjectListEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectListEdit),
    m_group(0),
    m_studentsModel(new QStringListModel(this)),
    m_subjectsModel(new QStringListModel(this))
{
    connect(m_studentsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(studentChanged(QModelIndex,QModelIndex)));
    ui->setupUi(this);
    ui->studentList->setModel(m_studentsModel);
    ui->subjectList->setModel(m_subjectsModel);
    connect(m_studentsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(accept()));
    connect(m_subjectsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(accept()));
    connect(ui->editSubjectGroup, SIGNAL(back()), this, SLOT(showSubjectList()));
    connect(ui->subjectGroupSchedule, SIGNAL(back()), this, SLOT(showSubjectList()));
}

void SubjectListEdit::accept()
{
}

void SubjectListEdit::goBack()
{
    emit back();
}

void SubjectListEdit::addSubject()
{
    m_group->appendSubject();
    m_subjectsModel->setStringList(m_group->subjectNames());
    ui->editSubjectGroup->setSubjectGroup(m_group->subject(m_subjectsModel->rowCount()-1));
    ui->stackedWidget->setCurrentWidget(ui->editSubjectGroupPage);
}

void SubjectListEdit::removeSubject()
{
    QModelIndexList selected = ui->subjectList->selectionModel()->selectedIndexes();
    if (!selected.isEmpty())
    {
        Q_ASSERT(selected.size()==1);
        m_subjectsModel->removeRow(selected.first().row());
    }
}

void SubjectListEdit::addStudent()
{
    m_group->appendMember();
    m_studentsModel->setStringList(m_group->members());
}

void SubjectListEdit::removeStudent()
{
    QModelIndexList selected = ui->studentList->selectionModel()->selectedIndexes();
    if (!selected.isEmpty())
    {
        Q_ASSERT(selected.size()==1);
        m_group->removeMember(selected.first().row());
    }
}

void SubjectListEdit::studentChanged(const QModelIndex &a, const QModelIndex &b)
{
    if (a.row()==b.row())
    {
        m_group->member(a.row()).name = a.data().toString();
    }
}

void SubjectListEdit::subjectClicked(const QModelIndex &index)
{
    subjectClicked(index.row());
}

void SubjectListEdit::subjectClicked(const int n)
{
    SubjectGroup &subj = m_group->subject(n);
    ui->subjectGroupSchedule->setGroupSubject(*m_group, subj);
    ui->stackedWidget->setCurrentWidget(ui->subjectGroupSchedulePage);
}

void SubjectListEdit::showSubjectList()
{
    ui->stackedWidget->setCurrentWidget(ui->subjectListPage);
    if (ui->editSubjectGroup->subjectGroup())
        m_group->subject(m_subjectsModel->rowCount()-1) = *ui->editSubjectGroup->subjectGroup();
    m_subjectsModel->setStringList(m_group->subjectNames());
}

void SubjectListEdit::setGroup(Group &group_)
{
    m_group = &group_;
    ui->courseAndGroup->setText(trUtf8("%1 курс %2 группа").arg(m_group->course()).arg(m_group->name()));
    m_studentsModel->setStringList(m_group->members());
    m_subjectsModel->setStringList(m_group->subjectNames());
}

SubjectListEdit::~SubjectListEdit()
{
    delete ui;
}
