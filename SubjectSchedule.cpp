#include "SubjectSchedule.hpp"
#include "ui_SubjectSchedule.h"

#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>

SubjectSchedule::SubjectSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectSchedule)
{
    ui->setupUi(this);
}

void SubjectSchedule::setGroupSubject(Group &group, const QString &subjectId, Subject &subject)
{
    disconnect(ui->scheduleTable, 0, this, 0);
    m_group = &group;
    m_subjectId = subjectId;
    m_subject = &subject;
    ui->scheduleTable->setRowCount(m_group->memberNames().size());
    ui->scheduleTable->setColumnCount(m_subject->hourCount()/2+1);
    for (int i = 0; i<m_group->memberNames().size(); ++i)
    {
        ui->scheduleTable->setVerticalHeaderItem(i, new QTableWidgetItem(QString().setNum(i+1)));
        ui->scheduleTable->setCellWidget(i, 0, new QLabel(m_group->memberNames().at(i)));
    }
    m_dates = m_subject->autoDates();
    if (m_subject->dates())
        m_dates = *m_subject->dates();
    ui->scheduleTable->setHorizontalHeaderItem(0, new QTableWidgetItem(trUtf8("Студент")));
    ui->scheduleTable->setRowCount(m_group->members().size());
    ui->scheduleTable->setColumnCount(m_dates.size()+1);
    for (int i = 0; i<m_dates.size(); ++i)
    {
        ui->scheduleTable->setHorizontalHeaderItem(i+1, new QTableWidgetItem(m_dates[i].toString("dd.MM")));
        for (int j = 0; j<m_group->members().size(); ++j)
            ui->scheduleTable->setItem(j, i+1, new QTableWidgetItem(m_group->member(j).data[m_subjectId][m_dates[i]]));
    }
    connect(ui->scheduleTable, SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int,int)));
}

void SubjectSchedule::cellChanged(int row, int column)
{
    const int studentId = row;
    const int dateId = column-1;
    const QString value = ui->scheduleTable->item(row, column)->text();
    m_group->member(studentId).data[m_subjectId][m_dates[dateId]] = value;
}

namespace
{
    QString escape(const QString &str)
    {
        return QString(str).replace("&","&amp;").replace(">","&gt;").replace("<","&lt;");
    }
}

void SubjectSchedule::saveTable()
{
    const QString fileName = QFileDialog::getSaveFileName(this, trUtf8("Сохранить таблицу"), QString(), tr("HTML (*.html)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, trUtf8("Ошибка"), trUtf8("Не получается открыть файл на запись!"));
    }
    else
    {
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out<<"<html>\n";
        {
            out<<"<head>\n";
            out<<"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n";
            out<<"</head>\n";
        }
        {
            out<<"<body>\n";
            {
                out<<"<table border=\"1\">\n";
                out<<"<caption>"<<escape(trUtf8("%1 (%2 курс %3 группа)").arg(m_subjectId).arg(m_group->course()).arg(m_group->name()))<<"</caption>\n";
                {
                    out<<"<tr>";
                    out<<"<th>"+escape(trUtf8("Студент"))+"</th>";
                    foreach (const QDate &date, m_dates)
                    {
                        out<<"<th>"<<escape(date.toString("dd.MM"))<<"</th>";
                    }
                    out<<"</tr>\n";
                }
                foreach (const Student &student, m_group->members())
                {
                    out<<"<tr>";
                    out<<"<th>"<<escape(student.name)<<"</th>";
                    foreach (const QDate &date, m_dates)
                    {
                        out<<"<td>";
                        out<<escape(student.data[m_subjectId][date]);
                        out<<"</td>";
                    }
                    out<<"</tr>\n";
                }
                out<<"</table>\n";
            }
            out<<"</body>\n";
        }
        out<<"</html>\n";
    }
}

void SubjectSchedule::printTable()
{
    QPrintDialog *dialog = new QPrintDialog(this);
    if (dialog->exec()==QDialog::Accepted)
    {
        QWidget *widget = ui->scheduleTable;
        QPrinter *printer = dialog->printer();
        QPainter painter(printer);
        double xscale = printer->pageRect().width()/double(widget->width());
        double yscale = printer->pageRect().height()/double(widget->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer->paperRect().x() + printer->pageRect().width()/2,
                           printer->paperRect().y() + printer->pageRect().height()/2);
        painter.scale(scale, scale);
        painter.translate(-width()/2, -height()/2);
        widget->render(&painter);
    }
    dialog->deleteLater();
}

SubjectSchedule::~SubjectSchedule()
{
    delete ui;
}
