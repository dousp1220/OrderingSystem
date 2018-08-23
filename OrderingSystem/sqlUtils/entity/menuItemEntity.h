#ifndef MENUITEMENTITY_H
#define MENUITEMENTITY_H

#include <QString>

class menuItemEntity
{
public:
    QString getMenu_id() const
    {
        return menu_id;
    }
    void setMenu_id(const QString &value)
    {
        menu_id = value;
    }

    QString getMenu_name() const
    {
        return menu_name;
    }
    void setMenu_name(const QString &value)
    {
        menu_name = value;
    }

    QString getMenu_image() const
    {
        return menu_image;
    }
    void setMenu_image(const QString &value)
    {
        menu_image = value;
    }

    float getPrice() const
    {
        return price;
    }
    void setPrice(float value)
    {
        price = value;
    }

    QString getDesc() const
    {
        return desc;
    }
    void setDesc(const QString &value)
    {
        desc = value;
    }

    QString getType_id() const
    {
        return type_id;
    }
    void setType_id(const QString &value)
    {
        type_id = value;
    }

    bool getIs_special_price() const
    {
        return is_special_price;
    }
    void setIs_special_price(bool value)
    {
        is_special_price = value;
    }

    bool getIs_hot() const
    {
        return is_hot;
    }
    void setIs_hot(bool value)
    {
        is_hot = value;
    }

    float getNew_price() const
    {
        return new_price;
    }
    void setNew_price(float value)
    {
        new_price = value;
    }

private:
    QString menu_id;
    QString menu_name;
    QString menu_image;

    float price;
    QString desc;
    QString type_id;

    bool is_special_price;
    bool is_hot;
    float new_price;
};

#endif // MENUITEMENTITY_H
