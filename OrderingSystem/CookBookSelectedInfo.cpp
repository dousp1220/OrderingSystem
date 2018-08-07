#include "CookBookSelectedInfo.h"

CookBookSelectedInfo::CookBookSelectedInfo(int id, int classilyId, QString name, float price, QString image, int addedCount, QString remarks)
    : m_nId(id)
    , m_nClassilyId(classilyId)
    , m_strName(name)
    , m_fPrice(price)
    , m_strImageUrl(image)
    , m_nAddedCount(addedCount)
    , m_strRemarks(remarks)
{

}

int CookBookSelectedInfo::id() const
{
    return m_nId;
}

void CookBookSelectedInfo::setId(int nId)
{
    m_nId = nId;
}

int CookBookSelectedInfo::classilyId() const
{
    return m_nClassilyId;
}

void CookBookSelectedInfo::setClassilyId(int nClassilyId)
{
    m_nClassilyId = nClassilyId;
}

QString CookBookSelectedInfo::name() const
{
    return m_strName;
}

void CookBookSelectedInfo::setName(const QString &strName)
{
    m_strName = strName;
}

QString CookBookSelectedInfo::imageUrl() const
{
    return m_strImageUrl;
}

void CookBookSelectedInfo::setImageUrl(const QString &strImageUrl)
{
    m_strImageUrl = strImageUrl;
}

int CookBookSelectedInfo::addedCount() const
{
    return m_nAddedCount;
}

void CookBookSelectedInfo::setAddedCount(int nAddedCount)
{
    m_nAddedCount = nAddedCount;
}

QString CookBookSelectedInfo::remarks() const
{
    return m_strRemarks;
}

void CookBookSelectedInfo::setRemarks(const QString &strRemarks)
{
    m_strRemarks = strRemarks;
}

float CookBookSelectedInfo::price() const
{
    return m_fPrice;
}

void CookBookSelectedInfo::setPrice(float fPrice)
{
    m_fPrice = fPrice;
}
