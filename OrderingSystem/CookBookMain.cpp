#include "CookBookMain.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ClassifyBox.h"

CookBookMain::CookBookMain(QWidget *parent) :
    QWidget(parent)
{
    init();
    initDate();
}

CookBookMain::~CookBookMain()
{
}

void CookBookMain::onCookBookCountChanged(int id, int classilyId, int nCount)
{
    CookBookClassilyWidget * pCookBookClassilyWidget = dynamic_cast<CookBookClassilyWidget *>(m_pStackedWidget->widget(classilyId));
    pCookBookClassilyWidget->setCookBookSelectedCount(id, nCount);
}

void CookBookMain::onAddCookBookClassilyPage()
{
    QVector<CookBookItemInfo*> infoList;
//    infoList << new CookBookItemInfo(100, 8,  QStringLiteral("猪蹄"), 55, ":/res/icon/item.png");
    CookBookClassilyWidget *pCookBookClassilyWidget = new CookBookClassilyWidget(infoList, this);
    connect(pCookBookClassilyWidget, SIGNAL(addCook(CookBookSelectedInfo *)), this, SIGNAL(addCook(CookBookSelectedInfo*)));
    m_pStackedWidget->addWidget(pCookBookClassilyWidget);
}

void CookBookMain::onRemoveCookBookClassilyPage(int index)
{
    m_pStackedWidget->removeWidget(m_pStackedWidget->widget(index));
}

void CookBookMain::init()
{
    m_pClassifyBox = new ClassifyBox(this);

    m_pStackedWidget = new QStackedWidget(this);

    connect(m_pClassifyBox, SIGNAL(switchCookBookClassilyPage(int)), m_pStackedWidget, SLOT(setCurrentIndex(int)));
    connect(m_pClassifyBox, SIGNAL(addCookBookClassilyPage()), this, SLOT(onAddCookBookClassilyPage()));
    connect(m_pClassifyBox, SIGNAL(removeCookBookClassilyPage(int)), this, SLOT(onRemoveCookBookClassilyPage(int)));

    QHBoxLayout *pMainLayout = new QHBoxLayout;

    pMainLayout->setMargin(0);
    pMainLayout->addWidget(m_pClassifyBox);
    pMainLayout->addWidget(m_pStackedWidget);

    this->setLayout(pMainLayout);
}

void CookBookMain::initDate()
{
    for (int i = 0; i < m_pClassifyBox->getClassifyCount(); ++i)
    {
        QVector<CookBookItemInfo*> infoList;
        infoList << new CookBookItemInfo(0 + i*22, i,  QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(1 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(2 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(3 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(4 + i*22, i,  QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(5 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(6 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(7 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(8 + i*22, i,  QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(9 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(10 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(11 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(12 + i*22, i,  QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(13 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(14 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(15 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(16 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(17 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(18 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(19 + i*22, i,  QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(20 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(21 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png")
                 << new CookBookItemInfo(22 + i*22, i, QStringLiteral("猪蹄"), 10+i, ":/res/icon/item.png");
        CookBookClassilyWidget *pCookBookClassilyWidget = new CookBookClassilyWidget(infoList, this);
        connect(pCookBookClassilyWidget, SIGNAL(addCook(CookBookSelectedInfo *)), this, SIGNAL(addCook(CookBookSelectedInfo*)));
        m_pStackedWidget->addWidget(pCookBookClassilyWidget);
    }
    m_pStackedWidget->setCurrentIndex(0);
}
