#include "CookBookMain.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ClassifyBox.h"
#include "sqlUtils/sqlUntils.h"
#include "sqlUtils/entity/menuTypeEntity.h"
#include <QSqlQuery>
#include <QDebug>

CookBookMain::CookBookMain(QWidget *parent) :
    QWidget(parent)
{
    init();
    initDate();
}

CookBookMain::~CookBookMain()
{
}

void CookBookMain::onCookBookCountChanged(QString id, QString classilyId, int nCount)
{
    Q_UNUSED(classilyId);

    CookBookClassilyWidget * pCookBookClassilyWidget;
    int count = m_pStackedWidget->count();
    for (int i = 0; i < count; ++i)
    {
        pCookBookClassilyWidget = dynamic_cast<CookBookClassilyWidget *>(m_pStackedWidget->widget(i));
        if (pCookBookClassilyWidget->hasMenuItem(id)) {
            pCookBookClassilyWidget->setCookBookSelectedCount(id, nCount);
//            return;
        }

//        if (pCookBookClassilyWidget->property("type_id").compare(classilyId) == 0) {
//            pCookBookClassilyWidget->setCookBookSelectedCount(id, nCount);
////            return;
//        }
    }
}

void CookBookMain::onAddCookBookClassilyPage()
{
    QVector<CookBookItemInfo*> infoList;
    CookBookClassilyWidget *pCookBookClassilyWidget = new CookBookClassilyWidget(infoList, this);
    connect(pCookBookClassilyWidget, SIGNAL(addCook(CookBookItemInfo *)), this, SIGNAL(addCook(CookBookItemInfo*)));
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
    QVector<menuTypeEntity *>  typeList =  m_pClassifyBox->getMenuTypeList();
    for (int i = 0; i < typeList.length(); ++i)
    {
        QSqlQuery query;
        if (typeList[i]->getHot_flag() != 0)
        {
            query = sqlUntils::getSqlUntils()->execSqlSelect(QString("SELECT * FROM menu_item WHERE hot_flag=%1 OR type_id='%2'")
                                                       .arg(typeList[i]->getHot_flag()).arg(typeList[i]->getType_id()));
        }
        else
        {
             query = sqlUntils::getSqlUntils()->execSqlSelect(QString("SELECT * FROM menu_item WHERE type_id='%1'").arg(typeList[i]->getType_id()));
        }

        QVector<CookBookItemInfo*> menuInfoList;
        while(query.next())
        {
            CookBookItemInfo *ent = new CookBookItemInfo();
            ent->setMenu_id(query.value("menu_id").toString());
            ent->setMenu_name(query.value("menu_name").toString());
            ent->setMenu_image(query.value("menu_image").toString());
            ent->setPrice(query.value("price").toFloat());
            ent->setDesc(query.value("desc").toString());
            ent->setType_id(query.value("type_id").toString());
            ent->setIs_special_price(query.value("is_special_price").toBool());
            ent->setHot_flag(query.value("hot_flag").toBool());
            ent->setNew_price(query.value("new_price").toFloat());

            menuInfoList.append(ent);
        }

        CookBookClassilyWidget *pCookBookClassilyWidget = new CookBookClassilyWidget(menuInfoList, this);
        pCookBookClassilyWidget->setProperty("type_id", typeList[i]->getType_id());
        connect(pCookBookClassilyWidget, SIGNAL(addCook(CookBookItemInfo *)), this, SIGNAL(addCook(CookBookItemInfo*)));
        m_pStackedWidget->addWidget(pCookBookClassilyWidget);
    }
    m_pStackedWidget->setCurrentIndex(0);
}
