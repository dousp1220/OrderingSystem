#ifndef SELECTEDWIDGET_H
#define SELECTEDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableView>
#include <QLabel>
#include <QStandardItemModel>
#include "CookBookItemInfo.h"
#include "SelectedOrderFormModel.h"

/**
 * @brief The SelectedWidget class
 * 点餐窗口
 */

class SelectedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectedWidget(QWidget *parent = 0);
    ~SelectedWidget();

public slots:
    void onAddCook(CookBookSelectedInfo* pCookBookSelectedInfo);
    void totalPrice();
    void onCookBookCountChanged(QString id, QString classilyId, int nCount);
    void onConfirmOrder();
    void onCancelOrder();

signals:
    void cookBookCountChanged(QString id, QString classilyId, int nCount);

private:
    void init();
    void initDate();

private:
    QTableView *m_pSeletedListView;
    SelectedOrderFormModel *m_pSeletedModel;

    QLabel *m_pTotalLabel;

    QPushButton *m_pConfirmBtn;
    QPushButton *m_pCancelBtn;
};

#endif // SELECTEDWIDGET_H
