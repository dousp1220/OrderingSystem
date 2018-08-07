#ifndef ORERINGWIDGET_H
#define ORERINGWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include "SelectedWidget.h"
#include "CookBookMain.h"
/**
 * @brief The CookBookMain class
 * 左边菜单主界面
 */
class OrderingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderingWidget(QWidget *parent = 0);
    ~OrderingWidget();

private:
    void init();

private:
    QTabWidget *m_pOrderingTabWidget;

    SelectedWidget *m_pSelectedWidget;
    CookBookMain *m_pCookBookMainWidget;
};

#endif // ORERINGWIDGET_H
