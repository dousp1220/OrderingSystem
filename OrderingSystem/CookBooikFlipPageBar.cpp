#include "CookBooikFlipPageBar.h"

#include <QHBoxLayout>
#include <QValidator>

CookBooikFlipPageBar::CookBooikFlipPageBar(QWidget *parent)
    : QWidget(parent)
    , m_nCurrentPage(1)
    , m_nPageCount(2)
{
    this->setFixedHeight(40);
    init();
}

CookBooikFlipPageBar::~CookBooikFlipPageBar()
{
}

void CookBooikFlipPageBar::init()
{
    m_pUpPageBtn = new  QPushButton(QStringLiteral("上一页"), this);
    m_pDownPageBtn = new  QPushButton(QStringLiteral("下一页"), this);

    connect(m_pUpPageBtn, &QPushButton::clicked, this, &CookBooikFlipPageBar::onFlipPage);
    connect(m_pDownPageBtn, &QPushButton::clicked, this, &CookBooikFlipPageBar::onFlipPage);

    m_pMsgLabel = new QLabel("0/0", this);

    m_pInputPageEdit = new QLineEdit(this);
    m_pInputPageEdit->setFixedWidth(50);
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, m_pInputPageEdit);
    m_pInputPageEdit->setValidator( validator );

    m_pJumpPageBtn = new QPushButton(QStringLiteral("跳转"), this);
    connect(m_pJumpPageBtn, &QPushButton::clicked, this, &CookBooikFlipPageBar::onFlipPage);

    QHBoxLayout *pMainLayout = new QHBoxLayout;
    pMainLayout->setContentsMargins(20, 5, 10, 5);

    pMainLayout->addStretch();
    pMainLayout->addWidget(m_pUpPageBtn);
    pMainLayout->addWidget(m_pMsgLabel);
    pMainLayout->addWidget(m_pDownPageBtn);
    pMainLayout->addStretch();
    pMainLayout->addWidget(m_pInputPageEdit);
    pMainLayout->addWidget(m_pJumpPageBtn);

    this->setLayout(pMainLayout);
}

int CookBooikFlipPageBar::pageCount() const
{
    return m_nPageCount;
}

void CookBooikFlipPageBar::setPageCount(int nPageCount)
{
    m_nPageCount = nPageCount;
    updateMegLabel();
}

void CookBooikFlipPageBar::updateMegLabel()
{
    m_pMsgLabel->setText(QString("%1/%2").arg(m_nCurrentPage).arg(m_nPageCount));
}

void CookBooikFlipPageBar::onFlipPage()
{
    if (m_pUpPageBtn == sender() && m_nCurrentPage > 1)
    {
        emit flipPage(--m_nCurrentPage);
    }
    else if (m_pDownPageBtn == sender() && m_nCurrentPage < m_nPageCount)
    {
        emit flipPage(++m_nCurrentPage);
    }
    else if (m_pJumpPageBtn == sender())
    {
        if (m_pInputPageEdit->text().isEmpty())
        {
            return;
        }

        int nIndex = m_pInputPageEdit->text().toInt();
        if (nIndex >= 1 && nIndex <= m_nPageCount)
        {
            m_nCurrentPage = nIndex;
            emit flipPage(nIndex);
        }
    }
    updateMegLabel();
}

int CookBooikFlipPageBar::currentPage() const
{
    return m_nCurrentPage;
}

void CookBooikFlipPageBar::setCurrentPage(int nCurrentPage)
{
    m_nCurrentPage = nCurrentPage;
    updateMegLabel();
}
