#include "Common.h"

uint dateTimeToStamp(QDateTime &dt)
{
    return dt.toTime_t(); //将当前时间转为时间戳
}

QDateTime stampToDateTime(uint stamp)
{
    return QDateTime::fromTime_t(stamp); //将时间戳转为时间
}

QString dateTimeToString(QDateTime &dt)
{
    return dt.toString("yyyy-MM-dd HH:mm:ss");
}

QDateTime stringToDateTime(QString str)
{
    return QDateTime::fromString(str, "yyyy-MM-dd HH:mm:ss");
}
