#include "EditGroup.hpp"
#include "ui_EditGroup.h"

EditGroup::EditGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditGroup)
{
    ui->setupUi(this);
}

EditGroup::~EditGroup()
{
    delete ui;
}
