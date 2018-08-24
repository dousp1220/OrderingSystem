#include "SelectedWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include "Common.h"
#include "SelectedOrderFormDelegate.h"
#include "sqlUtils/sqlUntils.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>

SelectedWidget::SelectedWidget(QWidget *parent) :
    QWidget(parent)
    , m_fTotalPrice(0)
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
    m_fTotalPrice = fTotalPrice;
    m_pTotalLabel->setText(QString(QStringLiteral("总计：%1元")).arg(fTotalPrice));
}

void SelectedWidget::onCookBookCountChanged(QString id, QString classilyId, int nCount)
{
    totalPrice();
    emit cookBookCountChanged(id, classilyId, nCount);
}

void SelectedWidget::onConfirmOrder()
{
    QVector<CookBookSelectedInfo *> list = m_pSeletedModel->cookBookSelectedInfoList();

    QString order_id = sqlUntils::getSqlUntils()->getGUID();
    bool isSuccess = sqlUntils::getSqlUntils()->execSql(QString(
        "insert into order_item (order_id, discount, offer_count, wipe_zero, orig_price_count, real_price_count, table_num, insert_date)\
         values ('%1', %2, %3, %4, %5, %6, %7, '%8')")
        .arg(order_id).arg(m_fTotalPrice).arg(0).arg(0).arg(m_fTotalPrice).arg(m_fTotalPrice).arg(12)
        .arg(dateTimeToString(QDateTime::currentDateTime())));

    if (!isSuccess)
    {
        QMessageBox::about(this, QStringLiteral("错误"), QStringLiteral("下单错误，请重试！"));
        return;
    }

    QString sql = "insert into order_detail_rela (relaton_id, count, remark, order_id, menu_id) values";
    for (int i = 0; i < list.length(); ++i)
    {
        CookBookSelectedInfo* info = list[i];
        QString id = sqlUntils::getSqlUntils()->getGUID();
        if (i != 0)
        {
            sql+=",";
        }
        sql += QString(" ('%1', %2, '%3', '%4', '%5')")
            .arg(id).arg(info->addedCount()).arg(info->remarks()).arg(order_id).arg(info->getMenu_id());
    }
    if (list.length() > 0)
    {
        if (!sqlUntils::getSqlUntils()->execSql(sql))
        {
            QMessageBox::about(this, QStringLiteral("错误"), QStringLiteral("下单错误，请重试！"));
            sqlUntils::getSqlUntils()->execSql(QString("delete FROM order_item where order_id='%1'").arg(order_id));
            return;
        }
    }
    QMessageBox::about(this, QStringLiteral("提示"), QStringLiteral("下单成功！"));
    onCancelOrder();
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
