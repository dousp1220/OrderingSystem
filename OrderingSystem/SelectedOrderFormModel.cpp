#include "SelectedOrderFormModel.h"
#include "Common.h"
#include <QPixmap>

SelectedOrderFormModel::SelectedOrderFormModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    init();
}

SelectedOrderFormModel::~SelectedOrderFormModel()
{
    QVector<CookBookSelectedInfo*>::Iterator iter = m_oCookBookSelectedInfoList.begin();
    while(iter != m_oCookBookSelectedInfoList.end())
    {
        CookBookSelectedInfo *p = *iter;
        delete p;
        iter++;
    }
}

void SelectedOrderFormModel::updateView()
{
    beginResetModel();
    endResetModel();
}

void SelectedOrderFormModel::addCook(CookBookSelectedInfo *pCookBookSelectedInfo)
{
    int index = findCookBookItem(pCookBookSelectedInfo->id());

    if (index == -1)
    {
        m_oCookBookSelectedInfoList.append(pCookBookSelectedInfo);
    }
    else
    {
        delete pCookBookSelectedInfo;
        CookBookSelectedInfo *p = m_oCookBookSelectedInfoList[index];
        p->setAddedCount(p->addedCount() + 1);
    }
    updateView();
}

void SelectedOrderFormModel::clearDate()
{
    for (int i = m_oCookBookSelectedInfoList.count() - 1; i >= 0; --i)
    {
        //清空选择窗口上的已选信息
        emit cookBookCountChanged(m_oCookBookSelectedInfoList[i]->id(), m_oCookBookSelectedInfoList[i]->classilyId(), 0);
        delete m_oCookBookSelectedInfoList[i];
        m_oCookBookSelectedInfoList.remove(i);
    }
    updateView();
}

void SelectedOrderFormModel::init()
{
    m_sHeaderList << QStringLiteral("菜品") << QStringLiteral("数量")
                  << QStringLiteral("单价") << QStringLiteral("备注");
}

int SelectedOrderFormModel::findCookBookItem(int id)
{
    for (int i = 0; i < m_oCookBookSelectedInfoList.count(); ++i)
    {
        if (m_oCookBookSelectedInfoList[i]->id() == id)
        {
            return i;
        }
    }
    return -1;
}

QModelIndex SelectedOrderFormModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return QModelIndex();
    }
    return createIndex(row, column, (void *)NULL);
}

QModelIndex SelectedOrderFormModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int SelectedOrderFormModel::rowCount(const QModelIndex &parent) const
{
    return m_oCookBookSelectedInfoList.count();
}

int SelectedOrderFormModel::columnCount(const QModelIndex &parent) const
{
    return m_sHeaderList.count();
}

QVariant SelectedOrderFormModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        CookBookSelectedInfo *pCookBookSelectedInfo = m_oCookBookSelectedInfoList[index.row()];
        switch (index.column())
        {
//        case EN_image:
//            return QPixmap(pCookBookSelectedInfo->imageUrl());
        case EN_name:
            return pCookBookSelectedInfo->name();
        case EN_count:
            return pCookBookSelectedInfo->addedCount();
        case EN_price:
            return pCookBookSelectedInfo->price();
//        case EN_total:
//            return pCookBookSelectedInfo->price() * pCookBookSelectedInfo->addedCount();
        case EN_Remarks:
            return pCookBookSelectedInfo->remarks();
        default:
            break;
        }

        return QVariant();
    }
    return QVariant();
}

QVariant SelectedOrderFormModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (role == Qt::DisplayRole)
        {
            return m_sHeaderList[section];
        }
    }

    if (orientation == Qt::Vertical)
    {
        if (role == Qt::DisplayRole)
        {
            return section + 1;
        }
    }
    return QVariant();
}

Qt::ItemFlags SelectedOrderFormModel::flags(const QModelIndex &index) const
{
    switch (index.column())
    {
    case EN_count:
    case EN_Remarks:
        return Qt::ItemIsEditable | Qt::ItemIsEnabled;
    default:
        return Qt::ItemIsEnabled;
    }
    return Qt::ItemIsEnabled;
}

bool SelectedOrderFormModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
    {
        return false;
    }

    if (role == Qt::EditRole)
    {
        CookBookSelectedInfo *pCookBookSelectedInfo = m_oCookBookSelectedInfoList[index.row()];

        switch (index.column())
        {
        case EN_count:
            pCookBookSelectedInfo->setAddedCount(value.toInt());

            //改变选择窗口的已选信息
            emit cookBookCountChanged(pCookBookSelectedInfo->id(), pCookBookSelectedInfo->classilyId(), value.toInt());
            if (value.toInt() == 0)
            {
                delete pCookBookSelectedInfo;
                m_oCookBookSelectedInfoList.remove(index.row());
                updateView();
            }
            break;
        case EN_Remarks:
            pCookBookSelectedInfo->setRemarks(value.toString());
            break;
        default:
            break;
        }

    }

    return true;
}

QVector<CookBookSelectedInfo *> SelectedOrderFormModel::cookBookSelectedInfoList() const
{
    return m_oCookBookSelectedInfoList;
}
