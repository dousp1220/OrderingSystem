#ifndef COOKBOOIKFLIPPAGEBAR_H
#define COOKBOOIKFLIPPAGEBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

/**
 * 菜品翻页类
 * @brief The CookBooikFlipPageBar class
 */
class CookBooikFlipPageBar : public QWidget
{
    Q_OBJECT

public:
    explicit CookBooikFlipPageBar(QWidget *parent = 0);
    ~CookBooikFlipPageBar();

    int currentPage() const;
    void setCurrentPage(int currentPage);

    int pageCount() const;
    void setPageCount(int pageCount);
    void updateMegLabel();

public slots:
    void onFlipPage();

signals:
    void flipPage(int index);

private:
    void init();

private:
    QPushButton *m_pUpPageBtn;
    QPushButton *m_pDownPageBtn;

    QLabel *m_pMsgLabel;

    QLineEdit *m_pInputPageEdit;
    QPushButton *m_pJumpPageBtn;

    int m_nCurrentPage;
    int m_nPageCount;
};

#endif // COOKBOOIKFLIPPAGEBAR_H
