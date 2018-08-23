#ifndef SELECTEDORDERFORMMODEL_H
#define SELECTEDORDERFORMMODEL_H

#include <QAbstractItemModel>
#include "CookBookSelectedInfo.h"
#include "CookBookItemInfo.h"
#include <QVector>

/**
 * @brief The SelectedOrderFormModel class
 * 点菜列表model
 */
class SelectedOrderFormModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit SelectedOrderFormModel(QObject *parent = 0);
    ~SelectedOrderFormModel();

    void updateView();

signals:
    void calcTotalPrice();
    void cookBookCountChanged(QString id, QString classilyId, int nCount);

public slots:
    void addCook(CookBookSelectedInfo *pCookBookSelectedInfo);
    void clearDate();

private:
    void init();
    /**
     * @brief findCookBookItem
     * @param id  菜品ID
     * @return
     */
    int findCookBookItem(QString id);

public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    QVector<CookBookSelectedInfo *> cookBookSelectedInfoList() const;

private:
    QVector<CookBookSelectedInfo*> m_oCookBookSelectedInfoList;
    QVector<QString> m_sHeaderList;
};

#endif // SELECTEDORDERFORMMODEL_H
