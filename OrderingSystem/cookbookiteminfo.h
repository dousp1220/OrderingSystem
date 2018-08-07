#ifndef COOKBOOKITEMINFO_H
#define COOKBOOKITEMINFO_H
#include <QString>

/**
 * @brief The CookBookItemInfo class
 * 菜品信息（菜品展示使用）
 */
class CookBookItemInfo
{
public:
    CookBookItemInfo(int id, int classilyId, QString name, float price, QString image);

    QString name() const;
    void setStrName(const QString &name);

    QString imageUrl() const;
    void setStrImageUrl(const QString &imageUrl);

    int id() const;
    void setNId(int id);

    int classilyId() const;
    void setNClassilyId(int classilyId);

    int addedCount() const;
    void setNAddedCount(int addedCount);

    float price() const;
    void setPrice(float price);

private:
    int m_nId;
    int m_nClassilyId;

    QString m_strName;
    float m_nPrice;
    QString m_strImageUrl;

    int m_nAddedCount;
};

#endif // COOKBOOKITEMINFO_H
