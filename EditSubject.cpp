#include "EditSubject.hpp"
#include "ui_EditSubject.h"

EditSubject::EditSubject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSubject)
{
    ui->setupUi(this);
}

EditSubject::~EditSubject()
{
    delete ui;
}
