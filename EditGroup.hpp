#ifndef EDITGROUP_HPP
#define EDITGROUP_HPP

#include <QDialog>

namespace Ui {
class EditGroup;
}

class EditGroup : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditGroup(QWidget *parent = 0);
    ~EditGroup();
    
private:
    Ui::EditGroup *ui;
};

#endif // EDITGROUP_HPP
