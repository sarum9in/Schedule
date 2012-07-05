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
