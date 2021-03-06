﻿#include "OreringWidget.h"
#include <QHBoxLayout>

OrderingWidget::OrderingWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground, true);
//    this->setStyleSheet("background: #00ffff;");
    init();
}

OrderingWidget::~OrderingWidget()
{
}

void OrderingWidget::init()
{
//    m_pOrderingTabWidget = new QTabWidget(this);

    m_pSelectedWidget = new SelectedWidget(this);
    m_pCookBookMainWidget = new CookBookMain(this);

    connect(m_pCookBookMainWidget, SIGNAL(addCook(CookBookItemInfo *)), m_pSelectedWidget, SLOT(onAddCook(CookBookItemInfo*)));
    connect(m_pSelectedWidget, SIGNAL(cookBookCountChanged(QString ,QString ,int)), m_pCookBookMainWidget, SLOT(onCookBookCountChanged(QString, QString, int)));

    QHBoxLayout *pMainLayout = new QHBoxLayout;
    pMainLayout->setMargin(1);
    pMainLayout->addWidget(m_pCookBookMainWidget);
    pMainLayout->addWidget(m_pSelectedWidget);

    this->setLayout(pMainLayout);
}
