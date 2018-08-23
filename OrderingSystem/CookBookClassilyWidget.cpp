#include "CookBookClassilyWidget.h"
#include <QVBoxLayout>

CookBookClassilyWidget::CookBookClassilyWidget(QVector<CookBookItemInfo*> CookBookItemInfoList, QWidget *parent)
    : QWidget(parent)
    , m_oCookBookItemInfoList(CookBookItemInfoList)
    , m_pGridLayout(NULL)
{
    init();
    updateLayout(1);
}

CookBookClassilyWidget::~CookBookClassilyWidget()
{
}

void CookBookClassilyWidget::setCookBookSelectedCount(QString id, int nCount)
{
    m_oCookBookItemMap[id]->setSelectedCount(nCount);
}

void CookBookClassilyWidget::init()
{
//    m_oCookBookItemInfoList;

    QVector<CookBookItemInfo*>::iterator iter = m_oCookBookItemInfoList.begin();
    while(iter != m_oCookBookItemInfoList.end())
    {
        CookBookItemInfo *pCookBookItemInfo = *iter;
        CookBookItemWidget *pCookBookItemWidget = new CookBookItemWidget(pCookBookItemInfo, this);

        m_oCookBookItemMap[pCookBookItemInfo->getMenu_id()] = pCookBookItemWidget;
        connect(pCookBookItemWidget, SIGNAL(addCook(CookBookSelectedInfo *)), this, SIGNAL(addCook(CookBookSelectedInfo*)));

        iter++;
    }

    m_pGridWidget = new QWidget(this);
    m_pCookBooikFlipPageBar = new CookBooikFlipPageBar(this);
    m_pCookBooikFlipPageBar->setPageCount(m_oCookBookItemMap.count() / (g_nColCount * g_nRowCount) + 1);
    connect(m_pCookBooikFlipPageBar, SIGNAL(flipPage(int)), this , SLOT(updateLayout(int)));

    QVBoxLayout *pMainLayout = new QVBoxLayout;
    pMainLayout->setMargin(0);
    pMainLayout->addWidget(m_pGridWidget);
    pMainLayout->addWidget(m_pCookBooikFlipPageBar);

    this->setLayout(pMainLayout);
}

void CookBookClassilyWidget::updateLayout(int page)
{
    if (m_pGridLayout != NULL)
    {
        delete m_pGridLayout;
    }

    QList<CookBookItemWidget*> widgetList = m_oCookBookItemMap.values();
    QList<CookBookItemWidget*>::iterator iterWidget = widgetList.begin();
    while(iterWidget != widgetList.end())
    {
        (*iterWidget)->setVisible(false);
        iterWidget++;
    }

    m_pGridLayout = new QGridLayout;
    m_pGridLayout->setMargin(8);
    m_pGridLayout->setSpacing(8);

    for (int i = 0; i < g_nRowCount; ++i)
    {
        for (int j = 0; j < g_nColCount; ++j)
        {
            if ((page - 1) * g_nColCount * g_nRowCount + i * g_nColCount + j >= widgetList.count())
            {
//                return;
                m_pGridLayout->addWidget(new QWidget(this), i, j);
                continue;
            }

            CookBookItemWidget *pWidget = widgetList[(page - 1) * g_nColCount * g_nRowCount + i * g_nColCount + j];
            pWidget->setVisible(true);
            m_pGridLayout->addWidget(pWidget, i, j);
        }
    }

    m_pGridWidget->setLayout(m_pGridLayout);
}
