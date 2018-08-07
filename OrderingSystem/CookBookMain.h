#ifndef COOKBOOKMAIN_H
#define COOKBOOKMAIN_H

#include <QWidget>
#include <QToolBox>
#include <QStackedWidget>
#include "CookBookClassilyWidget.h"

class ClassifyBox;

/**
 * @brief The CookBookMain class
 * 菜单左边菜品贴换以及展示界面
 */

class CookBookMain : public QWidget
{
    Q_OBJECT

public:
    explicit CookBookMain(QWidget *parent = 0);
    ~CookBookMain();

public slots:
    void onCookBookCountChanged(int id, int classilyId, int nCount);
    void onAddCookBookClassilyPage();
    void onRemoveCookBookClassilyPage(int index);

signals:
    void addCook(CookBookSelectedInfo*);

private:
    void init();
    void initDate();

private:
    ClassifyBox *m_pClassifyBox;
    QStackedWidget *m_pStackedWidget;
};

#endif // COOKBOOKMAIN_H
