#ifndef CLASSIFYBOX_H
#define CLASSIFYBOX_H

#include <QWidget>
#include <QVector>
#include <QToolButton>
#include <QPushButton>
#include <QVBoxLayout>


class menuTypeEntity;
/**
 * @brief 左边菜品分类界面
 */
class ClassifyBox : public QWidget
{
    Q_OBJECT

public:
    explicit ClassifyBox(QWidget *parent = 0);
    ~ClassifyBox();

    int getClassifyCount() const;

    QVector<menuTypeEntity*> getMenuTypeList() const;

signals:
    void switchCookBookClassilyPage(int index);
    void addCookBookClassilyPage();
    void removeCookBookClassilyPage(int index);

public slots:
    void onSwitchPage();
    void onAddClassily();
    void onDeleteClassily();
    void onEditClassily();

private:
    void init();
    void updateLayout();

private:
    QVector<QToolButton *> m_oBtnList;

    QWidget *m_pClassilyBtnWidget;

    QVBoxLayout *m_pClassilyWidgetLayout;
    QHBoxLayout *m_pEditLayout;

    QPushButton *m_pAddBtn;
    QPushButton *m_pDeleteBtn;
    QPushButton *m_pEditBtn;

    QVector<menuTypeEntity*> m_pClassilyTypeEntityList;
};

#endif // CLASSIFYBOX_H
