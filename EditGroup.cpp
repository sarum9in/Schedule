#include "EditGroup.hpp"
#include "ui_EditGroup.h"

#include <QMessageBox>

EditGroup::EditGroup(GroupByNameMap &groupByName_, const QString &group, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditGroup),
    m_studentsModel(new QStringListModel(this)),
    m_groupByName(groupByName_),
    m_name(group)
{
    ui->setupUi(this);
    ui->studentList->setModel(m_studentsModel);
    if (m_groupByName.contains(group))
        m_group = m_groupByName.value(group);
    ui->group->setText(m_group.name());
    ui->course->setCurrentIndex(m_group.course()-1);
    m_studentsModel->setStringList(m_group.members());
}

void EditGroup::accept()
{
    m_group.setName(ui->group->text());
    m_group.setCourse(ui->course->currentIndex()+1);
    m_group.setMembers(m_studentsModel->stringList());
    if (m_groupByName.contains(m_group.name()) && m_group.name()!=m_name)
    {
        QMessageBox::warning(this, trUtf8("Ошибка"), trUtf8("Такая группа уже существует!"));
    }
    else
    {
        m_groupByName.remove(m_name);
        m_groupByName[m_group.name()] = m_group;
        QDialog::accept();
    }
}

void EditGroup::addStudent()
{
    m_studentsModel->insertRow(m_studentsModel->rowCount());
}

void EditGroup::removeStudent()
{
    if (m_studentsModel->rowCount())
    {
        m_studentsModel->removeRow(m_studentsModel->rowCount()-1);
    }
}

EditGroup::~EditGroup()
{
    delete ui;
}
