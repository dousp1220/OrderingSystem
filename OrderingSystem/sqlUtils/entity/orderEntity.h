#ifndef ORDERENTITY_H
#define ORDERENTITY_H

#include <QString>

class orderItemEntity
{
public:

    QString orderItemEntity::getOrder_id() const
    {
        return order_id;
    }

    void orderItemEntity::setOrder_id(const QString &value)
    {
        order_id = value;
    }

    float orderItemEntity::getDiscount() const
    {
        return discount;
    }

    void orderItemEntity::setDiscount(float value)
    {
        discount = value;
    }

    float orderItemEntity::getOffer_count() const
    {
        return offer_count;
    }

    void orderItemEntity::setOffer_count(float value)
    {
        offer_count = value;
    }

    float orderItemEntity::getWipe_zero() const
    {
        return wipe_zero;
    }

    void orderItemEntity::setWipe_zero(float value)
    {
        wipe_zero = value;
    }

    float orderItemEntity::getOrig_price_count() const
    {
        return orig_price_count;
    }

    void orderItemEntity::setOrig_price_count(float value)
    {
        orig_price_count = value;
    }

    float orderItemEntity::getReal_price_count() const
    {
        return real_price_count;
    }

    void orderItemEntity::setReal_price_count(float value)
    {
        real_price_count = value;
    }

    int orderItemEntity::getTable_num() const
    {
        return table_num;
    }

    void orderItemEntity::setTable_num(int value)
    {
        table_num = value;
    }

    QString orderItemEntity::getRemarks() const
    {
        return remarks;
    }

    void orderItemEntity::setRemarks(const QString &value)
    {
        remarks = value;
    }

private:
    QString order_id;
    float discount;
    float offer_count;
    float wipe_zero;
    float orig_price_count;
    float real_price_count;
    int table_num;
    QString remarks;
};

#endif // ORDERENTITY_H
