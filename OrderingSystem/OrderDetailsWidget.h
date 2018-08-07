#ifndef ORDERDETAILSWDIEG_H
#define ORDERDETAILSWDIEG_H

#include <QWidget>

/**
 * @brief The OrderDetailsWidget class
 * 所有订单清单总界面
 */
class OrderDetailsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderDetailsWidget(QWidget *parent = 0);
    ~OrderDetailsWidget();

private:
    void init();
};

#endif //ORDERDETAILSWDIEG_H
