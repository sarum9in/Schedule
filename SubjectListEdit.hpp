#ifndef SUBJECTLISTEDIT_HPP
#define SUBJECTLISTEDIT_HPP

#include <QWidget>
#include <QStringListModel>

#include "Group.hpp"

namespace Ui {
class SubjectListEdit;
}

class SubjectListEdit : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectListEdit(QWidget *parent = 0);
    void setGroup(Group &group_);
    ~SubjectListEdit();

private slots:
    void accept();
    void goBack();

signals:
    void back();

private:
    Ui::SubjectListEdit *ui;
    Group *m_group;
    QStringListModel *m_studentsModel;
};

#endif // SUBJECTLISTEDIT_HPP
