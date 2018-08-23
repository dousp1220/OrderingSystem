#include "ClassifyBox.h"
#include <QHBoxLayout>
#include <QVariant>

#include "sqlUtils/sqlUntils.h"
#include <QSqlQuery>
#include "sqlUtils/entity/menuTypeEntity.h"

ClassifyBox::ClassifyBox(QWidget *parent) :
    QWidget(parent)
  , m_pClassilyWidgetLayout(NULL)
{
    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet("border-right: 1px solid #545454;");
    this->setFixedWidth(150);

    init();
}

ClassifyBox::~ClassifyBox()
{
}

int ClassifyBox::getClassifyCount() const
{
    return m_oBtnList.count();
}

QVector<menuTypeEntity *> ClassifyBox::getMenuTypeList() const
{
    return m_pClassilyTypeEntityList;
}

void ClassifyBox::onSwitchPage()
{
    for (int i = 0; i < m_oBtnList.count(); ++i)
    {
        m_oBtnList[i]->setChecked(false);
    }

    QToolButton *p = (dynamic_cast<QToolButton*>(this->sender()));
    if (p != nullptr)
    {
        p->setChecked(true);
        emit switchCookBookClassilyPage(p->property("ClassilyId").toInt());
    }
}

void ClassifyBox::onAddClassily()
{
//    m_oClassilyNameList << QStringLiteral("推    d");
//    QToolButton *p = new QToolButton(this);
//    p->setFixedWidth(150);
//    p->setFixedHeight(50);
//    p->setCheckable(true);
//    p->setProperty("ClassilyId", m_oClassilyNameList.count() - 1);
//    p->setText(m_oClassilyNameList[m_oClassilyNameList.count() - 1]);

//    connect(p, &QToolButton::clicked, this, &ClassifyBox::onSwitchPage);
//    m_oBtnList.append(p);

//    updateLayout();

//    emit addCookBookClassilyPage();
}

void ClassifyBox::onDeleteClassily()
{
//    if (m_oBtnList.count() <= 1)
//    {
//        return ;
//    }

//    for (int i = 0; i < m_oBtnList.count(); ++i)
//    {
//        if (m_oBtnList[i]->isChecked())
//        {
//            m_oClassilyNameList.removeAt(i);
//            delete m_oBtnList[i];
//            m_oBtnList.remove(i);

//            emit removeCookBookClassilyPage(i);

//            if (i > 0)
//            {
//                emit m_oBtnList[i - 1]->click();
//            }
//            else
//            {
//                emit m_oBtnList[0]->click();
//            }

//            break;
//        }
//    }
//    updateLayout();
}

void ClassifyBox::onEditClassily()
{

}

void ClassifyBox::init()
{
    QSqlQuery query = sqlUntils::getSqlUntils()->execSql("SELECT * FROM menu_type ORDER BY sort_index ASC");

    while(query.next())
    {
        menuTypeEntity *ent = new menuTypeEntity();
        ent->setType_id(query.value("type_id").toString());
        ent->setType_name(query.value("type_name").toString());
        ent->setImage(query.value("image").toString());

        m_pClassilyTypeEntityList.append(ent);

    }

    for (int i = 0; i < m_pClassilyTypeEntityList.count(); ++i)
    {
        QToolButton *p = new QToolButton(this);
        p->setFixedWidth(150);
        p->setFixedHeight(50);
        p->setCheckable(true);
        p->setProperty("ClassilyId", QVariant(i));
        p->setProperty("type_id", m_pClassilyTypeEntityList[i]->getType_id());
        p->setText(m_pClassilyTypeEntityList[i]->getType_name());

        connect(p, &QToolButton::clicked, this, &ClassifyBox::onSwitchPage);
        m_oBtnList.append(p);
    }
    if (m_oBtnList.length() != 0)
    {
        m_oBtnList[0]->setChecked(true);
    }

    m_pClassilyWidgetLayout = new QVBoxLayout;
    m_pClassilyWidgetLayout->setMargin(0);
    m_pClassilyWidgetLayout->setSpacing(5);
    QVector<QToolButton*>::iterator iter = m_oBtnList.begin();
    while(iter != m_oBtnList.end())
    {
        m_pClassilyWidgetLayout->addWidget(*iter);
        iter++;
    }

    m_pClassilyWidgetLayout->addStretch();

    m_pClassilyBtnWidget = new QWidget(this);

    m_pClassilyBtnWidget->setLayout(m_pClassilyWidgetLayout);

    m_pAddBtn = new QPushButton(QStringLiteral("添加"), this);
    m_pDeleteBtn = new QPushButton(QStringLiteral("删除"), this);
    m_pEditBtn = new QPushButton(QStringLiteral("修改"), this);

    connect(m_pAddBtn, &QPushButton::clicked, this, &ClassifyBox::onAddClassily);
    connect(m_pDeleteBtn, &QPushButton::clicked, this, &ClassifyBox::onDeleteClassily);
    connect(m_pEditBtn, &QPushButton::clicked, this, &ClassifyBox::onEditClassily);

    m_pEditLayout = new QHBoxLayout();
    m_pEditLayout->setMargin(0);
    m_pEditLayout->addWidget(m_pAddBtn);
    m_pEditLayout->addWidget(m_pDeleteBtn);
    m_pEditLayout->addWidget(m_pEditBtn);

    QVBoxLayout *pMainLayout = new QVBoxLayout;
    pMainLayout->setMargin(0);
    pMainLayout->addWidget(m_pClassilyBtnWidget);
    pMainLayout->addLayout(m_pEditLayout);

    this->setLayout(pMainLayout);
}

void ClassifyBox::updateLayout()
{
    delete m_pClassilyWidgetLayout;

    m_pClassilyWidgetLayout = new QVBoxLayout;
    m_pClassilyWidgetLayout->setMargin(0);
    m_pClassilyWidgetLayout->setSpacing(5);
    QVector<QToolButton*>::iterator iter = m_oBtnList.begin();
    while(iter != m_oBtnList.end())
    {
        m_pClassilyWidgetLayout->addWidget(*iter);
        iter++;
    }

    m_pClassilyWidgetLayout->addStretch();

    m_pClassilyBtnWidget->setLayout(m_pClassilyWidgetLayout);
}
