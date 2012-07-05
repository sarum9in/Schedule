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
    void addSubject();
    void subjectClicked(const QModelIndex &index);
    void subjectClicked(const QString &subject);
    void showSubjectList();

signals:
    void back();

private:
    Ui::SubjectListEdit *ui;
    Group *m_group;
    QStringListModel *m_studentsModel;
    QStringListModel *m_subjectsModel;
};

#endif // SUBJECTLISTEDIT_HPP
