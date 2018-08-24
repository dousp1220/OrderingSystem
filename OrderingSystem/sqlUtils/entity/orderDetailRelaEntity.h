#ifndef ORDERDETAILRELAENTITY_H
#define ORDERDETAILRELAENTITY_H

#include <QString>

class orderDetailRelaEntity
{
public:

    QString orderDetailRelaEntity::getRelaton_id() const
    {
        return relaton_id;
    }

    void orderDetailRelaEntity::setRelaton_id(const QString &value)
    {
        relaton_id = value;
    }

    int orderDetailRelaEntity::getCount() const
    {
        return count;
    }

    void orderDetailRelaEntity::setCount(int value)
    {
        count = value;
    }

    QString orderDetailRelaEntity::getRemark() const
    {
        return remark;
    }

    void orderDetailRelaEntity::setRemark(const QString &value)
    {
        remark = value;
    }

    QString orderDetailRelaEntity::getOrder_id() const
    {
        return order_id;
    }

    void orderDetailRelaEntity::setOrder_id(const QString &value)
    {
        order_id = value;
    }

    QString orderDetailRelaEntity::getMenu_id() const
    {
        return menu_id;
    }

    void orderDetailRelaEntity::setMenu_id(const QString &value)
    {
        menu_id = value;
    }

private:
    QString relaton_id;
    int count;
    QString remark;
    QString order_id;
    QString menu_id;
};

#endif // ORDERDETAILRELAENTITY_H
