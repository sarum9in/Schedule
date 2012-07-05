#ifndef SUBJECTLISTEDIT_HPP
#define SUBJECTLISTEDIT_HPP

#include <QWidget>

namespace Ui {
class SubjectListEdit;
}

class SubjectListEdit : public QWidget
{
    Q_OBJECT
    
public:
    explicit SubjectListEdit(QWidget *parent = 0);
    ~SubjectListEdit();
    
private:
    Ui::SubjectListEdit *ui;
};

#endif // SUBJECTLISTEDIT_HPP
