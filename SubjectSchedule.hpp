#ifndef SUBJECTSCHEDULE_HPP
#define SUBJECTSCHEDULE_HPP

#include <QDialog>

namespace Ui {
class SubjectSchedule;
}

class SubjectSchedule : public QDialog
{
    Q_OBJECT
    
public:
    explicit SubjectSchedule(QWidget *parent = 0);
    ~SubjectSchedule();
    
private:
    Ui::SubjectSchedule *ui;
};

#endif // SUBJECTSCHEDULE_HPP
