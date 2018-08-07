#include "CookBookItemInfo.h"


CookBookItemInfo::CookBookItemInfo(int id, int classilyId, QString name, float price, QString image)
    : m_nId(id)
    , m_nClassilyId(classilyId)
    , m_strName(name)
    , m_nPrice(price)
    , m_strImageUrl(image)
    , m_nAddedCount(0)
{

}

QString CookBookItemInfo::name() const
{
    return m_strName;
}

void CookBookItemInfo::setStrName(const QString &strName)
{
    m_strName = strName;
}

QString CookBookItemInfo::imageUrl() const
{
    return m_strImageUrl;
}

void CookBookItemInfo::setStrImageUrl(const QString &strImageUrl)
{
    m_strImageUrl = strImageUrl;
}

int CookBookItemInfo::id() const
{
    return m_nId;
}

void CookBookItemInfo::setNId(int nId)
{
    m_nId = nId;
}

int CookBookItemInfo::classilyId() const
{
    return m_nClassilyId;
}

void CookBookItemInfo::setNClassilyId(int nClassilyId)
{
    m_nClassilyId = nClassilyId;
}

int CookBookItemInfo::addedCount() const
{
    return m_nAddedCount;
}

void CookBookItemInfo::setNAddedCount(int nAddedCount)
{
    m_nAddedCount = nAddedCount;
}

float CookBookItemInfo::price() const
{
    return m_nPrice;
}

void CookBookItemInfo::setPrice(float nPrice)
{
    m_nPrice = nPrice;
}
