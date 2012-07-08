#pragma once

#include <QAbstractListModel>

#include "Subject.hpp"

class SubjectDateModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SubjectDateModel(QObject *parent = 0);
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

    void setEditable(const bool editable_);

    const DateList &dateList() const;
    void setDateList(const DateList &dateList_);

private:
    bool m_editable;
    DateList m_dateList;
};
