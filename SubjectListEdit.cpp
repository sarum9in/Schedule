#include "SubjectListEdit.hpp"
#include "ui_SubjectListEdit.h"

SubjectListEdit::SubjectListEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectListEdit),
    m_group(0),
    m_studentsModel(new QStringListModel(this)),
    m_subjectsModel(new QStringListModel(this))
{
    ui->setupUi(this);
    ui->studentList->setModel(m_studentsModel);
    ui->subjectList->setModel(m_subjectsModel);
    connect(m_studentsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(accept()));
    connect(m_subjectsModel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(accept()));
    connect(ui->editSubject, SIGNAL(back()), this, SLOT(showSubjectList()));
}

void SubjectListEdit::accept()
{
    m_group->setMembers(m_studentsModel->stringList());
    m_group->setSubjectNames(m_subjectsModel->stringList());
}

void SubjectListEdit::goBack()
{
    emit back();
}

void SubjectListEdit::addSubject()
{
    m_subjectsModel->insertRow(m_subjectsModel->rowCount());
    m_subjectsModel->setData(m_subjectsModel->index(m_subjectsModel->rowCount()-1), trUtf8("Новый предмет"));
    m_group->setSubjectNames(m_subjectsModel->stringList());
    ui->editSubject->setSubject(m_group->subject(m_group->subjectNames().back()));
    ui->stackedWidget->setCurrentWidget(ui->editSubjectPage);
}

void SubjectListEdit::subjectClicked(const QModelIndex &index)
{
    subjectClicked(index.data().toString());
}

void SubjectListEdit::subjectClicked(const QString &subject)
{
    Subject &subj = m_group->subject(subject);
    ui->stackedWidget->setCurrentWidget(ui->subjectSchedulePage);
}

void SubjectListEdit::showSubjectList()
{
    ui->stackedWidget->setCurrentWidget(ui->subjectListPage);
    QStringList lst = m_group->subjectNames();
    Subject &subj = *ui->editSubject->subject();
    lst.pop_back();
    lst.push_back(subj.name());
    m_group->setSubjectNames(lst);
    m_group->subject(subj.name()) = subj;
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
