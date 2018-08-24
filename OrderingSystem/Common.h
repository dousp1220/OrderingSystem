#ifndef COMMON_H
#define COMMON_H

#include<QDateTime>

enum EN_SelectedCookBookCol
{
    EN_name = 0,
    EN_count,
    EN_price,
    EN_Remarks
};

uint dateTimeToStamp(QDateTime &dt);
QDateTime stampToDateTime(uint stamp);
QString dateTimeToString(QDateTime &dt);
QDateTime stringToDateTime(QString str);

#endif // COMMON_H
