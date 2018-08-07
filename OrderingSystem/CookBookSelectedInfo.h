#ifndef COOKBOOKSELECTEDINFO_H
#define COOKBOOKSELECTEDINFO_H
#include <QString>

/**
 * @brief 选中菜品类
 */

class CookBookSelectedInfo
{
public:
    CookBookSelectedInfo(int id, int classilyId, QString name, float price, QString image, int addedCount, QString remarks);

    int id() const;
    void setId(int id);

    int classilyId() const;
    void setClassilyId(int classilyId);

    QString name() const;
    void setName(const QString &name);

    QString imageUrl() const;
    void setImageUrl(const QString &imageUrl);

    int addedCount() const;
    void setAddedCount(int addedCount);

    QString remarks() const;
    void setRemarks(const QString &remarks);

    float price() const;
    void setPrice(float price);

private:
    int m_nId;
    int m_nClassilyId;

    QString m_strName;
    float m_fPrice;
    QString m_strImageUrl;

    int m_nAddedCount;

    QString m_strRemarks;
};

#endif // COOKBOOKSELECTEDINFO_H
