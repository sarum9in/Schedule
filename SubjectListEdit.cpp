#include "SubjectListEdit.hpp"
#include "ui_SubjectListEdit.h"

SubjectListEdit::SubjectListEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectListEdit)
{
    ui->setupUi(this);
}

SubjectListEdit::~SubjectListEdit()
{
    delete ui;
}
