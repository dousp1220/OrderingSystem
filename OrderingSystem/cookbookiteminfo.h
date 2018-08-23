#ifndef COOKBOOKITEMINFO_H
#define COOKBOOKITEMINFO_H
#include <QString>

#include "sqlUtils/entity/menuitementity.h"

/**
 * @brief The CookBookItemInfo class
 * 菜品信息（菜品展示使用）
 */
class CookBookItemInfo : public menuItemEntity
{
public:
    CookBookItemInfo();
};

#endif // COOKBOOKITEMINFO_H
