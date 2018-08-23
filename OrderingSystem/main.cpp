#include "MainWidget.h"
#include <QApplication>
#include "CookBookItemWidget.h"
#include "sqlUtils/sqlUntils.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (sqlUntils::getSqlUntils()->openDb())
    {
        qDebug() << "open success!";
    }
    else
    {
        qDebug() << "open fail!";
    }

//    for (int i = 0; i < 10; ++i)
//    {
//        QString s = sqlUntils::getGUID();
//        qDebug() << s;
//    }


    MainWidget w;
    w.showMaximized();

    return a.exec();
}
