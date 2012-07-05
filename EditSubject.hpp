#ifndef EDITSUBJECT_HPP
#define EDITSUBJECT_HPP

#include <QWidget>

#include "Subject.hpp"

namespace Ui {
class EditSubject;
}

class EditSubject : public QWidget
{
    Q_OBJECT

public:
    explicit EditSubject(QWidget *parent = 0);
    void setSubject(Subject &subject_);
    ~EditSubject();

private slots:
    void accept();
    void goBack();

signals:
    void back();

private:
    Ui::EditSubject *ui;
    Subject *m_subject;
};

#endif // EDITSUBJECT_HPP
