#ifndef EDITSUBJECT_HPP
#define EDITSUBJECT_HPP

#include <QDialog>

namespace Ui {
class EditSubject;
}

class EditSubject : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditSubject(QWidget *parent = 0);
    ~EditSubject();
    
private:
    Ui::EditSubject *ui;
};

#endif // EDITSUBJECT_HPP
