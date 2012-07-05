#include "SubjectDateModel.hpp"

SubjectDateModel::SubjectDateModel(QObject *parent) :
    QAbstractListModel(parent),
    m_editable(false)
{
}

int SubjectDateModel::rowCount(const QModelIndex &parent) const
{
    return m_dateList.size();
}

QVariant SubjectDateModel::data(const QModelIndex &index, int role) const
{
    if (0<=index.row() && index.row()<m_dateList.size())
    {
        switch (role)
        {
        case Qt::DisplayRole:
            return m_dateList.at(index.row()).toString();
            break;
        case Qt::EditRole:
            return m_dateList.at(index.row());
            break;
        default:
            return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags SubjectDateModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags ret = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    if (m_editable)
        ret |= Qt::ItemIsEditable;
    return ret;
}

bool SubjectDateModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (0<=index.row() && index.row()<m_dateList.size())
    {
        switch (role)
        {
        case Qt::EditRole:
            {
                m_dateList[index.row()] = value.toDate();
                emit dataChanged(index, index);
            }
            break;
        default:
            return false;
        }
    }
    return false;
}

void SubjectDateModel::setEditable(const bool editable_)
{
    beginResetModel();
    m_editable = editable_;
    endResetModel();
}

const DateList &SubjectDateModel::dateList() const
{
    return m_dateList;
}

void SubjectDateModel::setDateList(const DateList &dateList_)
{
    beginResetModel();
    m_dateList = dateList_;
    endResetModel();
}
