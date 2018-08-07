#ifndef COOKBOOKITEM_H
#define COOKBOOKITEM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "CookBookItemInfo.h"
#include "CookBookSelectedInfo.h"

/**
 * @brief The CookBookItemWidget class
 * 菜品Item界面
 */
class CookBookItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CookBookItemWidget(CookBookItemInfo *cookBookItemInfo = NULL, QWidget *parent = 0);
    ~CookBookItemWidget();

    CookBookItemInfo *cookBookItemInfo() const;
    void setCookBookItemInfo(CookBookItemInfo *cookBookItemInfo);

    int selectedCount() const;

public slots:
    void onCookBookDetail();
    void onAddSelectes();
    void setSelectedCount(int selectedCount);

signals:
    void addCook(CookBookSelectedInfo *pCookBookSelectedInfo);

private:
    void init();
    void updateList();
    void updateSelected();

private:
    CookBookItemInfo *m_pCookBookItemInfo;

    QLabel *m_pImageLabel;
    QLabel *m_pNameLabel;
    QLabel *m_pPriceLabel;

    QLabel *m_pAddedImageLabel;
    QLabel *m_pAddedMsgLabel;

    QPushButton *m_pDetailBtn;
    QPushButton *m_pAddSelectesBtn;

    int m_nSelectedCount;
};

#endif // COOKBOOKITEM_H
