#include "SelectedWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include "Common.h"
#include "SelectedOrderFormDelegate.h"

SelectedWidget::SelectedWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedWidth(400);
    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet("border-left: 1px solid #545454;");
    init();
    initDate();
}

SelectedWidget::~SelectedWidget()
{
}

void SelectedWidget::onAddCook(CookBookItemInfo *pCookBookItemInfo)
{
    m_pSeletedModel->addCook(pCookBookItemInfo);
    totalPrice();
}

void SelectedWidget::totalPrice()
{
    QVector<CookBookSelectedInfo *> list = m_pSeletedModel->cookBookSelectedInfoList();

    float fTotalPrice = 0;

    for (int i = 0; i < list.count(); ++i)
    {
        fTotalPrice += list[i]->getPrice() * list[i]->addedCount();
    }
    m_pTotalLabel->setText(QString(QStringLiteral("总计：%1元")).arg(fTotalPrice));
}

void SelectedWidget::onCookBookCountChanged(QString id, QString classilyId, int nCount)
{
    totalPrice();
    emit cookBookCountChanged(id, classilyId, nCount);
}

void SelectedWidget::onConfirmOrder()
{

}

void SelectedWidget::onCancelOrder()
{
    m_pSeletedModel->clearDate();
}

void SelectedWidget::init()
{
    m_pConfirmBtn = new QPushButton(QStringLiteral("确认下单"), this);
    m_pCancelBtn = new QPushButton(QStringLiteral("取消下单"), this);

    connect(m_pConfirmBtn, &QPushButton::clicked, this, &SelectedWidget::onConfirmOrder);
    connect(m_pCancelBtn, &QPushButton::clicked, this, &SelectedWidget::onCancelOrder);

    QHBoxLayout *pBtnLayout = new QHBoxLayout;
    pBtnLayout->addWidget(m_pCancelBtn);
    pBtnLayout->addWidget(m_pConfirmBtn);

    m_pSeletedListView = new QTableView(this);
    m_pSeletedListView->setStyleSheet("border:none;");

    QLabel *pTitleLabel = new QLabel(QStringLiteral("确认订单"), this);
    pTitleLabel->setAlignment(Qt::AlignCenter);
    pTitleLabel->setStyleSheet("border: none; font-family: Microsoft YaHei; font-size: 15px; color: #434343;");

    m_pTotalLabel = new QLabel(this);
    m_pTotalLabel->setStyleSheet("border: none; font-family: Microsoft YaHei; font-size: 22px; color: #434343;");
    m_pTotalLabel->setAlignment(Qt::AlignRight);
    m_pTotalLabel->setText(QStringLiteral("总计：0元"));

    QVBoxLayout *pMainLayout = new QVBoxLayout;
    pMainLayout->addWidget(pTitleLabel);
    pMainLayout->addWidget(m_pSeletedListView);
    pMainLayout->addWidget(m_pTotalLabel);
    pMainLayout->addLayout(pBtnLayout);

    this->setLayout(pMainLayout);
}

void SelectedWidget::initDate()
{
    //添加根节点
    m_pSeletedModel = new SelectedOrderFormModel(m_pSeletedListView);
    m_pSeletedListView->setModel(m_pSeletedModel);
    m_pSeletedListView->setItemDelegate(new SelectedOrderFormDelegate(m_pSeletedListView));

    connect(m_pSeletedModel, SIGNAL(cookBookCountChanged(QString ,QString ,int)), this, SLOT(onCookBookCountChanged(QString, QString, int)));

    m_pSeletedListView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pSeletedListView->setColumnWidth(EN_name, 100);
    m_pSeletedListView->setColumnWidth(EN_count, 50);
    m_pSeletedListView->setColumnWidth(EN_price, 50);

    m_pSeletedListView->horizontalHeader()->setSectionResizeMode(EN_Remarks, QHeaderView::Stretch);

}
