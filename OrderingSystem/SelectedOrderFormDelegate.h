#ifndef SELECTEDORDERFORMDELEGATE_H
#define SELECTEDORDERFORMDELEGATE_H

#include <QObject>
#include <QItemDelegate>

/**
 * @brief The SelectedOrderFormDelegate class
 * 点菜列表delegate
 */
class SelectedOrderFormDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    SelectedOrderFormDelegate(QObject *parent = Q_NULLPTR);

    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // SELECTEDORDERFORMDELEGATE_H
