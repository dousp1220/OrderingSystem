#include "MainWidget.h"
#include <QHBoxLayout>
#include "OreringWidget.h"
#include "OrderDetailsWidget.h"
#include "GLXSqlUtils.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    GLXSqlUtils::getGlxSqlUtils();
    GLXSqlUtils::initGlxSqlUtils("haha.db");

    this->setWindowFlags(this->windowFlags()/*& ~Qt::WindowMaximizeButtonHint | Qt::FramelessWindowHint*/);
//    this->setWindowState(Qt::WindowMaximized);

    init();
}

MainWidget::~MainWidget()
{
    GLXSqlUtils::deleteGlxSqlUtils();
}

void MainWidget::init()
{
    m_pTabWidget = new QTabWidget(this);

    m_pQrderingWidget = new OrderingWidget(this);
    m_pOrderDetailsWidget = new OrderDetailsWidget(this);

    m_pTabWidget->addTab(m_pQrderingWidget, QStringLiteral("点餐"));
    m_pTabWidget->addTab(m_pOrderDetailsWidget, QStringLiteral("订单清单"));

    QHBoxLayout *pMainLayout = new QHBoxLayout;
    pMainLayout->setMargin(4);
    pMainLayout->addWidget(m_pTabWidget);


    this->setLayout(pMainLayout);
}
