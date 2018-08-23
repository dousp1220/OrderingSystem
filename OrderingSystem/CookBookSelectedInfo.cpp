#include "CookBookSelectedInfo.h"

CookBookSelectedInfo::CookBookSelectedInfo(int addedCount, QString remarks)
    : m_nAddedCount(addedCount)
    , m_strRemarks(remarks)
{

}

CookBookSelectedInfo::CookBookSelectedInfo(CookBookItemInfo *info, int addedCount, QString remarks)
{
    this->setMenu_id(info->getMenu_id());
    this->setMenu_name(info->getMenu_name());
    this->setMenu_image(info->getMenu_image());
    this->setPrice(info->getPrice());
    this->setNew_price(info->getNew_price());
    this->setHot_flag(info->getHot_flag());
    this->setIs_special_price(info->getIs_special_price());
    this->setType_id(info->getType_id());
    this->setDesc(info->getDesc());

    m_nAddedCount = addedCount;
    m_strRemarks = remarks;
}

CookBookSelectedInfo::CookBookSelectedInfo()
{

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

