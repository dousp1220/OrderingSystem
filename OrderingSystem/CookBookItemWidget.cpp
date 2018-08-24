#include "CookBookItemWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

CookBookItemWidget::CookBookItemWidget(CookBookItemInfo *pCookBookItemInfo, QWidget *parent)
    : QWidget(parent)
    , m_pCookBookItemInfo(pCookBookItemInfo)
    , m_nSelectedCount(0)
{
    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet("background: #00aa00;");
    init();
    updateList();
}

CookBookItemWidget::~CookBookItemWidget()
{
}

void CookBookItemWidget::init()
{
    m_pImageLabel = new QLabel(this);
    m_pImageLabel->setFixedSize(165, 165);
    m_pImageLabel->setPixmap(QPixmap(m_pCookBookItemInfo->getMenu_image()));
    m_pImageLabel->setScaledContents(true);

    m_pNameLabel = new QLabel(this);
    m_pNameLabel->setText(m_pCookBookItemInfo->getMenu_name());
    m_pNameLabel->setStyleSheet("font-family: Microsoft YaHei; font-size: 20px; color: #434343;");
    m_pPriceLabel = new QLabel(this);
    m_pPriceLabel->setAlignment(Qt::AlignRight);
    m_pPriceLabel->setText(QString(QStringLiteral("%1元  ")).arg(m_pCookBookItemInfo->getPrice()));
    m_pPriceLabel->setStyleSheet("font-family: Microsoft YaHei; font-size: 18px; color: #000000;");

    m_pAddedImageLabel = new QLabel(this);
    m_pAddedImageLabel->setScaledContents(true);
    m_pAddedImageLabel->setFixedSize(20, 20);
    m_pAddedImageLabel->setPixmap(QPixmap(":/res/icon/seleted.png"));
    m_pAddedMsgLabel = new QLabel(this);
    m_pAddedMsgLabel->setStyleSheet("font-family: Microsoft YaHei; font-size: 15px; color: #bb0000;");
    m_pAddedMsgLabel->setText(QString(QStringLiteral("已选%1份")).arg(m_nSelectedCount));

    QHBoxLayout *pSelectesLayout = new QHBoxLayout;
    pSelectesLayout->addSpacing(40);
    pSelectesLayout->addWidget(m_pAddedImageLabel);
    pSelectesLayout->addWidget(m_pAddedMsgLabel);

    m_pDetailBtn = new QPushButton(QStringLiteral("食品详情"), this);
    m_pAddSelectesBtn = new QPushButton(QStringLiteral("加入订单"), this);
    connect(m_pDetailBtn, &QPushButton::clicked, this, &CookBookItemWidget::onCookBookDetail);
    connect(m_pAddSelectesBtn, &QPushButton::clicked, this, &CookBookItemWidget::onAddSelectes);

    QHBoxLayout *pBtnLayout = new QHBoxLayout;
    pBtnLayout->addWidget(m_pDetailBtn);
    pBtnLayout->addWidget(m_pAddSelectesBtn);

    QVBoxLayout *pRightLayout = new QVBoxLayout;
    pRightLayout->setMargin(5);
    pRightLayout->addWidget(m_pNameLabel);
    pRightLayout->addWidget(m_pPriceLabel);
    pRightLayout->addLayout(pSelectesLayout);
    pRightLayout->addLayout(pBtnLayout);

    QHBoxLayout *pMainLayout = new QHBoxLayout;
    pMainLayout->setMargin(0);
    pMainLayout->addWidget(m_pImageLabel);
    pMainLayout->addLayout(pRightLayout);

    this->setLayout(pMainLayout);

    updateSelected();
}

void CookBookItemWidget::updateList()
{
    m_pImageLabel->setPixmap(QPixmap(m_pCookBookItemInfo->getMenu_image()));
    m_pNameLabel->setText(m_pCookBookItemInfo->getMenu_name());
    m_pPriceLabel->setText(QString::number(m_pCookBookItemInfo->getPrice()) + QStringLiteral("元  "));
}

void CookBookItemWidget::updateSelected()
{
    if (m_nSelectedCount > 0)
    {
        m_pAddedImageLabel->setVisible(true);
        m_pAddedMsgLabel->setText(QString(QStringLiteral("已选%1份")).arg(m_nSelectedCount));
    }
    else
    {
        m_pAddedImageLabel->setVisible(false);
        m_pAddedMsgLabel->setText("");
    }
}

int CookBookItemWidget::selectedCount() const
{
    return m_nSelectedCount;
}

void CookBookItemWidget::setSelectedCount(int nSelectedCount)
{
    m_nSelectedCount = nSelectedCount;
    updateSelected();
}

CookBookItemInfo *CookBookItemWidget::cookBookItemInfo() const
{
    return m_pCookBookItemInfo;
}

void CookBookItemWidget::setCookBookItemInfo(CookBookItemInfo *pCookBookItemInfo)
{
    m_pCookBookItemInfo = pCookBookItemInfo;
    updateList();
}

void CookBookItemWidget::onCookBookDetail()
{
    //TODO 查看菜品详情
    QMessageBox::about(nullptr, m_pCookBookItemInfo->getMenu_name() + QStringLiteral("-详情"), m_pCookBookItemInfo->getDesc());
}

void CookBookItemWidget::onAddSelectes()
{
    //TODO 添加到已选中
    m_nSelectedCount++;

    emit addCook(m_pCookBookItemInfo);

//    updateSelected();
}
