#include "MainWidget.h"
#include <QApplication>
#include "CookBookItemWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;
//    w.show();
    w.showMaximized();

//    CookBookItem s;
//    s.show();

//    QSize sa = s.size();
    return a.exec();
}
