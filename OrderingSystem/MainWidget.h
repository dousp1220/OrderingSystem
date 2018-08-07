#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTabWidget>

class OrderingWidget;
class OrderDetailsWidget;

/**
 * @brief The CookBookMain class
 * 主界面
 */
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    void init();

private:
//    QWidget *m_pTitle

    QTabWidget *m_pTabWidget;

    OrderingWidget *m_pQrderingWidget;
    OrderDetailsWidget *m_pOrderDetailsWidget;
};

#endif // MAINWIDGET_H
