#ifndef COOKBOOKSELECTEDINFO_H
#define COOKBOOKSELECTEDINFO_H
#include <QString>
#include "cookbookiteminfo.h"

/**
 * @brief 选中菜品类
 */

class CookBookSelectedInfo : public CookBookItemInfo
{
public:
    CookBookSelectedInfo(int addedCount, QString remarks);
    CookBookSelectedInfo(CookBookItemInfo* info, int addedCount, QString remarks);
    CookBookSelectedInfo();

    int addedCount() const;
    void setAddedCount(int addedCount);

    QString remarks() const;
    void setRemarks(const QString &remarks);

private:
    int m_nAddedCount;

    QString m_strRemarks;
};

#endif // COOKBOOKSELECTEDINFO_H
