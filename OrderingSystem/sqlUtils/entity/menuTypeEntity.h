﻿#ifndef MENUTYPEENTITY_H
#define MENUTYPEENTITY_H

#include <QString>

class menuTypeEntity
{
private:
    QString type_id;
    QString type_name;
    QString image;

public:
    QString getType_name() const
    {
        return type_name;
    }

    void setType_name(const QString &value)
    {
        type_name = value;
    }

    QString getImage() const
    {
        return image;
    }

    void setImage(const QString &value)
    {
        image = value;
    }

    QString getType_id() const
    {
        return type_id;
    }

    void setType_id(const QString &value)
    {
        type_id = value;
    }
};

#endif // MENUTYPEENTITY_H

