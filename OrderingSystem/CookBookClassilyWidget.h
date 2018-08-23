#ifndef COOKBOOKCLASSILYWIDGET_H
#define COOKBOOKCLASSILYWIDGET_H

#include <QWidget>
#include <QMap>
#include <QVector>
#include "CookBookItemWidget.h"
#include "CookBookItemInfo.h"
#include <QGridLayout>
#include "CookBooikFlipPageBar.h"

const int g_nColCount = 4;
const int g_nRowCount = 5;

/**
 * @brief The CookBookClassilyWidget class
 * 菜品按分类grid布局展示页面
 */
class CookBookClassilyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CookBookClassilyWidget(QVector<CookBookItemInfo*> CookBookItemInfoList, QWidget *parent = 0);
    ~CookBookClassilyWidget();

    void setCookBookSelectedCount(QString id, int nCount);

signals:
    void addCook(CookBookSelectedInfo *pCookBookSelectedInfo);

public slots:
    void updateLayout(int page);

private:
    void init();

private:
    QGridLayout *m_pGridLayout;
    QMap<QString, CookBookItemWidget*> m_oCookBookItemMap;
    QVector<CookBookItemInfo*> m_oCookBookItemInfoList;

    CookBooikFlipPageBar *m_pCookBooikFlipPageBar;

    QWidget *m_pGridWidget;
};

#endif // COOKBOOKCLASSILYWIDGET_H
