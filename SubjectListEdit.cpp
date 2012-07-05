#include "SubjectListEdit.hpp"
#include "ui_SubjectListEdit.h"

SubjectListEdit::SubjectListEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectListEdit),
    m_group(0),
    m_studentsModel(new QStringListModel(this))
{
    ui->setupUi(this);
    ui->studentList->setModel(m_studentsModel);
}

void SubjectListEdit::accept()
{
}

void SubjectListEdit::goBack()
{
    emit back();
}

void SubjectListEdit::setGroup(Group &group_)
{
    m_group = &group_;
}

SubjectListEdit::~SubjectListEdit()
{
    delete ui;
}
